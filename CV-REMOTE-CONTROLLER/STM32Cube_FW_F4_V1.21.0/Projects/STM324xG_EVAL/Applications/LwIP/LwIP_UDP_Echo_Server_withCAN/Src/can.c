//25.03.2018
//BEST GRUP SAVUNMA
//
//Mehmet Bilgehan Tosun
//
//OZET:
//
//Bu dosya CAN1 ve CAN2 iletisimi icin gerekli bilgileri icermektedir.
//UYARILAR:
//Bu dosya icinde CAN iletisimi disinda bir isleme yapilmamalidir.
//

#include "can.h"
#include "stdio.h"
#include "udpServer.h"
#include "config.h"
#include "general_purpose_func.h"

extern uint32_t messageCAN_timeout_counter;
extern uint16_t CAN_mesaji_toplam_uzunluk;
extern uint8_t mesaj_state;
extern uint8_t mesaj_data[CAN_MESAJ_ALMA_SIZE];
extern uint8_t mesaj[CAN_MESAJ_ALMA_SIZE];
extern uint8_t mesaj_tipi;
extern uint8_t zoom_seviyesi;
extern int16_t tilt_aci_durumu;
extern int16_t pan_aci_durumu;
extern int16_t LRF_mesafesi;
extern uint8_t kurma_kolu;
uint8_t parka_hazir = 0;

#define CAN_FIFO_AZAMI_BOYUT 1024

uint8_t paket_sayisi=0; //test

CAN_HandleTypeDef	CanHandle;
CAN_HandleTypeDef   Can2Handle;
CAN_RxHeaderTypeDef CAN1_RXMesaji;
CAN_TxHeaderTypeDef CAN1_TXMesaji;
CAN_RxHeaderTypeDef CAN2_RXMesaji;
CAN_TxHeaderTypeDef CAN2_TXMesaji;
uint8_t             CAN_RxData[8];
uint8_t			    CAN_MesajGeldi;

//Bu fonksiyon CAN1 icin tum ayarlari yapar
//Bu karta ait CAN adresi "CAN_KENDI_ADRESI" bilgisinde degistirilir
//CAN Hizi 1Mbps olarak ayarlanmistir.
//
void CAN1_Konfigurasyonu_Yap(GPIO_TypeDef *CANPort, uint16_t CANPin1, uint16_t CANPin2)
{
	CAN_FilterTypeDef	sFilterConfig;
	GPIO_InitTypeDef	GPIO_InitStruct;

	__HAL_RCC_CAN1_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	GPIO_InitStruct.Pin = CANPin1;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Alternate =  GPIO_AF9_CAN1;

	HAL_GPIO_Init(CANPort, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = CANPin2;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Alternate =  GPIO_AF9_CAN1;

	HAL_GPIO_Init(CANPort, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(CAN1_RX0_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(CAN1_RX0_IRQn);

	CanHandle.Instance = CAN1;

	CanHandle.Init.TimeTriggeredMode = DISABLE;
	CanHandle.Init.AutoBusOff = ENABLE;
	CanHandle.Init.AutoWakeUp = ENABLE;
	CanHandle.Init.AutoRetransmission = ENABLE;
	CanHandle.Init.ReceiveFifoLocked = ENABLE;
	CanHandle.Init.TransmitFifoPriority = ENABLE;
	CanHandle.Init.Mode = CAN_MODE_NORMAL;
	CanHandle.Init.SyncJumpWidth = CAN_SJW_1TQ;
	CanHandle.Init.TimeSeg1 = CAN_BS1_11TQ;
	CanHandle.Init.TimeSeg2 = CAN_BS2_2TQ;
	CanHandle.Init.Prescaler = 3;

	if (HAL_CAN_Init(&CanHandle) != HAL_OK)
	{
		while(1);
	}

	sFilterConfig.FilterBank = 0;
	sFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
	sFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
	sFilterConfig.FilterIdHigh = 0x0000;
	sFilterConfig.FilterIdLow = 0x0000;
	sFilterConfig.FilterMaskIdHigh = 0x0000;
	sFilterConfig.FilterMaskIdLow = 0x0000;
	sFilterConfig.FilterFIFOAssignment = CAN_RX_FIFO0;
	sFilterConfig.FilterActivation = ENABLE;
	sFilterConfig.SlaveStartFilterBank = 14;

	if (HAL_CAN_ConfigFilter(&CanHandle, &sFilterConfig) != HAL_OK)
	{
		while(1);
	}

	if (HAL_CAN_Start(&CanHandle) != HAL_OK)
	{
		while(1);
	}

	if (HAL_CAN_ActivateNotification(&CanHandle, CAN_IT_RX_FIFO0_MSG_PENDING) != HAL_OK)
	{
		while(1);
	}
}



extern uint8_t motorRxFlag;
extern uint8_t motorTxFlag;

/* taret baslangic */
uint8_t CAN1_newDataFlag=0; //yeni bilgi geldiginde interrupt icinde guncelleniyor

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &CAN1_RXMesaji, CAN_RxData) != HAL_OK)
	{
		//while(1);
	}
	else
	{
		CAN_MesajGeldi = 1;
		
		if (CAN_RxData[0] == 0x47 && CAN_RxData[1] == 0x12 && CAN_RxData[2] == 0x21 && CAN_RxData[4] != 0)
			sendUDPMessage(CAN_RxData);
		
		//if (CAN_RxData[0] != 0x05) motorRxFlag = 1;
		
		if (CAN1_RXMesaji.StdId == 0x04)
		{
			CAN1_newDataFlag = 1;
			CAN1_RX8Bayt();
		}
	}
}


//CAN 1 icin mesaj alma interrupt'u
//Bilgileri CAN1_RXMesaji icine toplar

#define TILT_MOTOR_CVP 0x584
#define PAN_MOTOR_CVP 0x585
#define DIREKSIYON_MOTOR_CVP 0x583
uint8_t pozisyon_alindi_flag=0;
int32_t pozisyon=0, tilt_anlik_pozisyon=0, pan_anlik_pozisyon,direksiyon_anlik_pozisyon=0;

#define HIZ_CAN_MESAJI 0x18FEF100
#define DEVIR_CAN_MESAJI 0x0CF00400
#define ELECTRONIC_TRANSMISSION_CONTROLLER_CAN_MESAJI 0x18F00504
uint16_t motor_can_devir=0, motor_can_hiz=0;

#define VITESN 4
#define VITESR 5
#define VITESD 6

uint8_t vites_can=0;//0:N, 1-6:D, 8:R
uint8_t can_hiz_counter=0;
uint16_t loop_counter=0;

//CAN1'den 8bayt bilgiyi alip CAN1_uzun_buffera yaziyor.
//Bu ya main altinda,
//if(CAN1_newDataFlag)
// CAN1_RX8Bayt()   seklinde bulundurulmalidir, ya da interrupt icine yazilmalidir.
//CAN datasi geldiginde okunmak uzere CAN1_uzun_buffer'a yazar.
//
uint8_t CAN1_RX8Bayt()
{
	uint8_t counter=0;

	if(!CAN1_newDataFlag)
		return 0;

	CAN1_newDataFlag=0;
	for (counter=0;counter<8;counter++)
		FIFO_push(CAN_RxData[counter]);
	return 1;
}

uint16_t FIFODataSayisi=0;
uint16_t FIFOKuyruk=0;
uint16_t FIFOKafa=0;
uint8_t FIFO[CAN_FIFO_AZAMI_BOYUT];

uint8_t CAN1_RX(uint8_t *CAN_Bilgi,uint16_t CAN_BilgiSayisi)
{
	uint16_t counter=0;
	if(FIFODataSayisi<CAN_BilgiSayisi)
		return 0; // Hatali istek yapilmis

	for (counter=0;counter<CAN_BilgiSayisi;counter++)
	{
		*CAN_Bilgi=FIFO_pull();
		CAN_Bilgi++;
	}
	
	return 1;
}

//CAN1 icin icine yüklenen tum bilgiyi gonderir.
//CAN_Bilgi tum bilgiyi iceren array'i
//CAN_BilgiSayisi gonderilmesi hedeflenen toplam bilgi miktarini gosterir
//her paket 8bayt oldugundan, artik paket kalir ise kalan baytlarý 0 gonderir.
uint8_t CAN1_TX(uint8_t CAN_Adresi, uint8_t *CAN_Bilgi, uint8_t CAN_BilgiSayisi)
{
	uint8_t counter=0;
	uint8_t CAN_Bilgi8Bayt_Paket[8];
	while (CAN_BilgiSayisi){
		CAN_Bilgi8Bayt_Paket[counter]=*CAN_Bilgi;
		counter++;
		CAN_Bilgi++;
		CAN_BilgiSayisi--;
		if(counter==8)
		{
			counter=0;
			CAN1_TX_8Bayt(CAN_Adresi,CAN_Bilgi8Bayt_Paket);
		}
	}
	if(counter>0){

		while(counter<8){
		 CAN_Bilgi8Bayt_Paket[counter]=0;
		 counter++;
		}
		CAN1_TX_8Bayt(CAN_Adresi,CAN_Bilgi8Bayt_Paket);

	}
	return 1;
}

//bir CAN frame gonderilmesi icin Busy Wait
void CAN_TX_Bekle()
{
	uint16_t counter = 0;
	while(counter != 0x9FF ){
		counter++;
	}
}

//CAN1 uzerinden 8 bayt bilgi gonderir,
//tum CAN1 iletisim paketleri 8 bayt olacaktir.
//CAN_Adresi bilginin gonderilecegi hedefi
//CAN_8Bayt_Bilgi 8 baytlik TX array'i gosterir
uint8_t CAN1_TX_8Bayt(uint32_t CAN_Adresi, uint8_t CAN_8BaytBilgi[8])
{
	uint32_t TxMailbox = 0;
	
	CAN1_TXMesaji.IDE = CAN_ID_STD;
	CAN1_TXMesaji.StdId = CAN_Adresi;
	CAN1_TXMesaji.ExtId = 0x01;
	CAN1_TXMesaji.RTR = CAN_RTR_DATA;
	CAN1_TXMesaji.DLC = 8;
	
	HAL_CAN_AddTxMessage(&CanHandle, &CAN1_TXMesaji, (uint8_t *)CAN_8BaytBilgi, &TxMailbox);
	paket_sayisi++;
	return 1;
}

uint8_t FIFO_data_dolu_mu(void)
{
	if(FIFODataSayisi<CAN_FIFO_AZAMI_BOYUT)
		return 0;
	return 1;
}

uint8_t FIFO_data_var_mi(void)
{
	if(FIFODataSayisi>0)
		return 1;
	return 0;
}

uint8_t FIFO_data_sayisi_kac(void)
{
	return FIFODataSayisi;
}

uint8_t FIFO_push(uint8_t data)
{
	if(!FIFO_data_dolu_mu())
	{
		FIFO[FIFOKafa]=data;
		if(FIFOKafa<(CAN_FIFO_AZAMI_BOYUT-1))
			FIFOKafa++;
		else
			FIFOKafa=0;
		FIFODataSayisi++;
		return 1;
	}
	else
		return 0;
}


uint8_t FIFO_pull(void)
{
	uint8_t data=0;
	if(FIFO_data_var_mi())
	{
		data=FIFO[FIFOKuyruk];
		if(FIFOKuyruk<(CAN_FIFO_AZAMI_BOYUT-1))
		{
			FIFOKuyruk++;
		}
		else
			FIFOKuyruk=0;
		FIFODataSayisi--;
		return data;
	}
	return 0;

}

void CAN1_FIFO_temizle(void)
{
	FIFODataSayisi=0;
	FIFOKuyruk=0;
	FIFOKafa=0;
}

#define ADR 0x00
uint8_t CAN_timestamp=0;
#define STX 0x82
#define ETX 0x80

uint8_t CAN_gondermeye_hazir_mesaj[1024];

uint8_t CAN_gondermeye_hazirla(uint8_t alt_adres,uint8_t *gonderilecek_mesaj,uint8_t mesaj_uzunluk)
{
	//uint8_t *hazir_mesaj;
	//uint8_t hazir_mesaj_array[mesaj_uzunluk+6];
	uint16_t counter=0;
	uint8_t checksum=0;
//	CAN_gondermeye_hazir_mesaj=(uint8_t*)malloc(mesaj_uzunluk+6);

	CAN_gondermeye_hazir_mesaj[0]=STX;
	CAN_gondermeye_hazir_mesaj[1]=alt_adres;
	CAN_gondermeye_hazir_mesaj[2]=mesaj_uzunluk;

	for(counter=0;counter<mesaj_uzunluk;counter++)
	{
		CAN_gondermeye_hazir_mesaj[3+counter]=*gonderilecek_mesaj;
		checksum+=*gonderilecek_mesaj;
		gonderilecek_mesaj++;
	}
	
	CAN_gondermeye_hazir_mesaj[3+counter]=checksum+ CAN_timestamp+ mesaj_uzunluk + ADR;
	CAN_gondermeye_hazir_mesaj[4+counter]=CAN_timestamp;
	CAN_timestamp++;
	CAN_gondermeye_hazir_mesaj[5+counter]=ETX;
	
	return 1;
}

extern uint16_t joystick_tilt;
extern uint16_t joystick_pan;
extern uint8_t zoom_direction;
extern uint8_t tetik_cek;
uint8_t park_istegi=0;
uint8_t kule_enable=0;
uint8_t zoom_durumu=0;

extern uint16_t jsYmessageTilt;
extern uint16_t jsXmessagePan;
extern uint16_t jsZmessageZoom;

void CAN_gonder_hiz_zoom_enable_park (void)
{

	if(jsZmessageZoom>550)
		zoom_durumu=1; //ZOOM yap
	else if(jsZmessageZoom<450)
		zoom_durumu=2; //ZOOM azalt
	else
		zoom_durumu=0; //ZOOM Degisiklik yok

	uint8_t CANGonderArray[8];

//	joystick_tilt=500;
//	joystick_pan=500;
	/*
	CANGonderArray[0]=joystick_tilt>>8;
	CANGonderArray[1]=joystick_tilt;
	CANGonderArray[2]=joystick_pan>>8;
	CANGonderArray[3]=joystick_pan;
	CANGonderArray[4]=kule_enable;
	CANGonderArray[5]=zoom_direction;//zoom_durumu;
	CANGonderArray[6]=0;//park durumu gitmeyecek
	CANGonderArray[7]=tetik_cek;
	CAN_gondermeye_hazirla(0x11,CANGonderArray,8);
	CAN1_TX(0x07,CAN_gondermeye_hazir_mesaj,14);
	*/
	CANGonderArray[0]=jsYmessageTilt>>8;
	CANGonderArray[1]=jsYmessageTilt;
	CANGonderArray[2]=jsXmessagePan>>8;
	CANGonderArray[3]=jsXmessagePan;
	CANGonderArray[4]=kule_enable;
	CANGonderArray[5]=zoom_durumu;//zoom_durumu;
	CANGonderArray[6]=kurma_kolu;
	CANGonderArray[7]=tetik_cek;
	CAN_gondermeye_hazirla(0x11,CANGonderArray,8);
	CAN1_TX(0x07,CAN_gondermeye_hazir_mesaj,14);
}

/* taret bitis */

void canRunTask (void)
{
	/* can-taret */
	if(messageCAN_timeout_counter > 20)
	{
		CAN_gonder_hiz_zoom_enable_park();
		messageCAN_timeout_counter = 0;
	}

	if(CAN1_RX(mesaj,CAN_mesaji_toplam_uzunluk))
	{
		if(Mesaj_dogrulama())
		{
			if(mesaj_tipi==KULE_GONDERISI)
			{
				tilt_aci_durumu=(mesaj_data[0]<<8)+mesaj_data[1];
				if(tilt_aci_durumu>599)
					tilt_aci_durumu=600;
				else if(tilt_aci_durumu<-201)
					tilt_aci_durumu=-200;
				pan_aci_durumu=(mesaj_data[2]<<8)+mesaj_data[3];
				LRF_mesafesi=(mesaj_data[4]<<8)+mesaj_data[5];
				parka_hazir=mesaj_data[6];
				zoom_seviyesi=mesaj_data[7];
			}
		}
		CAN1_FIFO_temizle();
	}
}
