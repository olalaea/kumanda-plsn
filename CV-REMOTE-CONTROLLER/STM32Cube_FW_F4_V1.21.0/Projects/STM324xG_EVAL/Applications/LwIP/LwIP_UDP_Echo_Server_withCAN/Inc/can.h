//25.03.2018
//BEST GRUP SAVUNMA
//
//Mehmet Bilgehan Tosun
//
//OZET:
//
//Bu dosya CAN1 ve CAN2 iletisimi icin gerekli bilgileri icermektedir.
//UYARILAR:
//
//
#include "stm32f4xx.h"
#include "stm32f4xx_hal_can.h"

uint8_t CAN1_TX_8Bayt(uint32_t CAN_Adresi, uint8_t *CAN_8BaytBilgi);
uint8_t CAN1_TX(uint8_t CAN_Adresi, uint8_t *CAN_Bilgi, uint8_t CAN_BilgiSayisi);
void CAN1_Konfigurasyonu_Yap(GPIO_TypeDef *CANPort, uint16_t CANPin1, uint16_t CANPin2);
void CAN2_Konfigurasyonu_Yap(GPIO_TypeDef *CANPort, uint16_t CANPin1, uint16_t CANPin2);
uint8_t CAN1_RX8Bayt(void);
uint16_t CAN1_RX_Buffer_Boyut_Al(void);
void CAN1_RX_Buffer_Sil(void);
uint8_t CAN1_RX(uint8_t *CAN_Bilgi,uint16_t CAN_BilgiSayisi);

uint8_t FIFO_data_dolu_mu(void);
uint8_t FIFO_pull(void);
uint8_t FIFO_push(uint8_t data);
uint8_t FIFO_data_var_mi(void);
void CAN1_FIFO_temizle(void);
uint8_t CAN_gondermeye_hazirla(uint8_t alt_adres,uint8_t *gonderilecek_mesaj,uint8_t mesaj_uzunluk);
uint8_t MOTOR_iste_pozisyon(uint32_t motor_no);

extern uint8_t CAN_gondermeye_hazir_mesaj[1024];


uint8_t MOTOR_set_hiz(int32_t desired_speed,uint32_t motor_no);
uint8_t MOTOR_go(uint32_t motor_no);
uint8_t MOTOR_halt(uint32_t motor_no);
uint8_t MOTOR_init_config(uint32_t motor_no);
uint8_t MOTOR_set_ivme(int32_t ivme_acc,int32_t ivme_dcc,uint32_t motor_no);

void CAN_gonder_hiz_zoom_enable_park (void);

extern CAN_HandleTypeDef   CanHandle;
extern CAN_HandleTypeDef   Can2Handle;
extern CAN_RxHeaderTypeDef CAN1_RXMesaji;
extern CAN_TxHeaderTypeDef CAN1_TXMesaji;
extern uint8_t             CAN_RxData[8];
extern uint8_t			   CAN_MesajGeldi;

void canRunTask (void);
