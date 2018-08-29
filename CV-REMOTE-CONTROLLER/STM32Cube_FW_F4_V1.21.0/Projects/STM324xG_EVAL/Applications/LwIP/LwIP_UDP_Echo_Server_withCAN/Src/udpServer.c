#include "main.h"
#include "lwip/pbuf.h"
#include "lwip/udp.h"
#include "lwip/tcp.h"
#include <string.h>
#include <stdio.h>
#include "udpServer.h"
#include "motor.h"

uint8_t UDP_MesajGeldi;
uint8_t UDP_RxData[44];
uint8_t kameraSwitch = 0;
uint8_t kameraSwitchChar = 0;uint8_t defMessage[8] = {1, 2, 3, 4, 5, 6, 7, 8};
uint8_t resetFlag = 0;

extern uint32_t resetCounter;
extern uint32_t telemetriCounter;

extern uint8_t kule_enable;
extern uint8_t firstEmergencyFlag;

/*taret*/
uint16_t joystick_tilt, joystick_pan;
uint8_t zoom_direction = 0;
uint8_t tetik_cek = 0;
uint8_t zoom_seviyesi = 0;
int16_t tilt_aci_durumu = 0;
int16_t pan_aci_durumu = 0;
int16_t LRF_mesafesi = 0;
/*taret*/

extern float pitch_value;
extern float yaw_value;
extern float roll_value;

/* Private function prototypes -----------------------------------------------*/
void udp_echoserver_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port);

extern ip_addr_t udpTestIP;

extern uint16_t jsXmessage;
extern uint16_t jsYmessage;
extern uint16_t jsZmessage;

uint16_t jsYmessageTilt;
uint16_t jsXmessagePan;
uint16_t jsZmessageZoom;

uint8_t emergencySwitch;
uint8_t	lightSwitch;
uint8_t tetik_emniyet;
uint8_t kurma_kolu;
uint8_t speedControlSwitch1;
uint8_t speedControlSwitch2;
uint8_t speedControlSwitch3;
uint8_t speedLevel = 0;

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Initialize the server application.
  * @param  None
  * @retval None
  */
void udpServerInit(void)
{
   struct udp_pcb *upcb;
   err_t err;
   
   /* Create a new UDP control block  */
   upcb = udp_new();
   
   if (upcb)
   {
     /* Bind the upcb to the UDP_PORT port */
     /* Using IP_ADDR_ANY allow the upcb to be used by any local interface */
      err = udp_bind(upcb, IP_ADDR_ANY, UDP_SERVER_PORT);
      
      if(err == ERR_OK)
      {
        /* Set a receive callback for the upcb */
        udp_recv(upcb, udp_echoserver_receive_callback, NULL);
      }
   }
}

/**
  * @brief This function is called when an UDP datagrm has been received on the port UDP_PORT.
  * @param arg user supplied argument (udp_pcb.recv_arg)
  * @param pcb the udp_pcb which received data
  * @param p the packet buffer that was received
  * @param addr the remote IP address from which the packet was received
  * @param port the remote port from which the packet was received
  * @retval None
  */

void udp_echoserver_receive_callback(void *arg, struct udp_pcb *upcb, struct pbuf *p, const ip_addr_t *addr, u16_t port)
{
  UDP_MesajGeldi = 1;

  strncpy((char *)UDP_RxData, (char *) p->payload, 44);

  //udpTestIP = *addr; // test icin yazildi. Bilgisayarin ip'sini almasi icin.
	
#if 0
  /* Connect to the remote client */
  udp_connect(upcb, addr, UDP_CLIENT_PORT);

  /* Tell the client that we have accepted it */
  udp_send(upcb, p);

  /* free the UDP connection, so we can accept new clients */
  udp_disconnect(upcb);
#endif

  /* Free the p buffer */
  pbuf_free(p);
}

#include "definition.h"

char analog_message[8];
char read_ethernet[ETHERNET_READ_SIZE];
char approved_ethernet[ETHERNET_READ_SIZE];

uint8_t atis_serbest_flag, silah_aktif_flag, tetik_cek;
uint8_t kamera_degistir=0,kamera_old=0,kamera_temp;
uint8_t mast_state;

void parseEthernetValues (void)
{
	uint16_t dig_val=0;
	copyArray(approved_ethernet, read_ethernet, ETHERNET_READ_SIZE, 0);
	zeroArray(read_ethernet,ETHERNET_READ_SIZE);
	dig_val=(approved_ethernet[4]-0x30)*100;
	dig_val=dig_val+(approved_ethernet[5]-0x30)*10;
	dig_val=dig_val	+(approved_ethernet[6]-0x30);
	atis_serbest_flag=dig_val>>3&1;

	kamera_temp=dig_val>>8&1;
	if(kamera_old!=kamera_temp && kamera_old==1)
	{
		kamera_degistir=1-kamera_degistir;
	}
	kamera_old=kamera_temp;

	silah_aktif_flag=dig_val>>1&1;
	if(silah_aktif_flag&&atis_serbest_flag)
		tetik_cek=(dig_val>>7&1);
	else
		tetik_cek=0;

	uint16_t tempValue = 0;
	zeroArray(analog_message,4);
	copyArray(analog_message,approved_ethernet,4, 8);
	tempValue += ((analog_message[0] - 48));
	for (int var = 1; var < 4; var++) {
		tempValue *=10;
		tempValue += ((analog_message[var] - 48));
	}
	joystick_pan = tempValue;

	tempValue = 0;
	zeroArray(analog_message,4);
	copyArray(analog_message,approved_ethernet,4, 12);
	tempValue += ((analog_message[0] - 48));
	for (int var = 1; var < 4; var++) {
		tempValue *=10;
		tempValue += ((analog_message[var] - 48));
	}
	joystick_tilt = tempValue;

	zoom_direction = approved_ethernet[16] - 48;
	mast_state = approved_ethernet[18] - 48;
}

extern uint32_t udpMessageTimeout;
extern uint8_t kule_enable;
extern uint8_t tetik_cek;
uint8_t atis_serbest = 0;
/*
uint8_t udpParser (void)
{
	if (UDP_RxData[0] == 'M' && UDP_RxData[1] == 'D' && UDP_RxData[43] == 'S')
	{
		udpMessageTimeout = 0;
	}
	else
	{
		kule_enable = 0;
		tetik_cek = 0;
		return 0;
	}
	
	emergencySwitch = UDP_RxData[12];
	lightSwitch = UDP_RxData[11];
	speedControlSwitch1 = UDP_RxData[10];
	speedControlSwitch2 = UDP_RxData[9];
	speedControlSwitch3 = UDP_RxData[8];
	kule_enable = UDP_RxData[16];
	atis_serbest = UDP_RxData[17];
	tetik_cek = UDP_RxData[7];
	tetik_emniyet = UDP_RxData[14];
	kurma_kolu = UDP_RxData[15];
	kameraSwitchChar = UDP_RxData[2];
	
	if (atis_serbest == '1')
	{
		if (tetik_emniyet == '1' && tetik_cek == '1')
			tetik_cek = 1;
		else
			tetik_cek = 0;
	}
	else
	{
		tetik_cek = 0;
	}
	
	if (kurma_kolu == '1')
	{
		kurma_kolu = 1;
	}
	else
	{
		kurma_kolu = 0;
	}
	
	if (kule_enable == '1')
	{
		kule_enable = 1;
	}
	else
	{
		kule_enable = 0;
	}
	
	if (kameraSwitchChar == '1')
	{
		if (kameraSwitch == 0) kameraSwitch = 1;
		else if (kameraSwitch == 1) kameraSwitch = 0;
	}
	else
	{
		kameraSwitch = 0;
	}
	
	if (speedControlSwitch1 == '0' && speedControlSwitch2 == '0' && speedControlSwitch3 == '1')
	{
		speedLevel = 3;
	}
	else if (speedControlSwitch1 == '0' && speedControlSwitch2 == '1' && speedControlSwitch3 == '0')
	{
		speedLevel = 2;
	}
	else if (speedControlSwitch1 == '1' && speedControlSwitch2 == '0' && speedControlSwitch3 == '0')
	{
		speedLevel = 1;
	}
	else if (speedControlSwitch1 == '0' && speedControlSwitch2 == '0' && speedControlSwitch3 == '0')
	{
		//speedLevel = 0;
	}
	
	if (lightSwitch == '1')
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_SET);
	}
	else
	{
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9, GPIO_PIN_RESET);
	}
	
	char *ptr;
	char value[4];
	strncpy(ptr, (char *)UDP_RxData, 44);
	
	ptr = strstr((char *)UDP_RxData, "A");
	
	if (ptr != NULL)
	{
		ptr++;
		strncpy(value, ptr, 4);
		
		jsYmessage = atoi(value);
		
		ptr+=4;
		
		if (ptr != NULL)
		{
			strncpy(value, ptr, 4);
			
			jsXmessage = atoi(value);
			
			ptr+=4;
			
			if (ptr != NULL)
			{
				strncpy(value, ptr, 4);
				
				jsZmessage = atoi(value);
				
				ptr+=4;
				
				if (ptr != NULL)
				{
					strncpy(value, ptr, 4);
				
					jsYmessageTilt = atoi(value);
				
					ptr+=4;
					
					if (ptr != NULL)
					{
						strncpy(value, ptr, 4);
				
						jsXmessagePan = atoi(value);
				
						ptr+=4;
						
						if (ptr != NULL)
						{
							strncpy(value, ptr, 4);
				
							jsZmessageZoom = atoi(value);
				
							ptr+=4;
				
							if (strstr((char *)ptr, "S") != NULL)
							{
								ptr = NULL;
								return 1;
							}
							else
							{
								ptr = NULL;
								return 0;
							}
						}
						else
						{
							ptr = NULL;
							return 0;
						}
					}
					else
					{
						ptr = NULL;
						return 0;
					}
				}
				else
				{
					ptr = NULL;
					return 0;
				}
			}
			else
			{
				ptr = NULL;
				return 0;
			}
		}
		else
		{
			ptr = NULL;
			return 0;
		}
	}
	else
	{
		ptr = NULL;
		return 0;
	}
}*/

extern struct pbuf *udpTestBuf;
extern struct udp_pcb *udpTestPCB;
extern ip_addr_t udpTestIP;

void sendUDPMessage (uint8_t canData[8])
{
	IP_ADDR4(&udpTestIP, REMOTE_IP_ADDR0, REMOTE_IP_ADDR1, REMOTE_IP_ADDR2, REMOTE_IP_ADDR3);
	udp_connect(udpTestPCB, &udpTestIP, UDP_CLIENT_PORT);

	udpTestBuf = pbuf_alloc(PBUF_TRANSPORT, 8, PBUF_RAM);
	memcpy(udpTestBuf->payload, (char *)canData, 8);
	udp_sendto(udpTestPCB, udpTestBuf, &udpTestIP, UDP_CLIENT_PORT);

	udp_disconnect(udpTestPCB);
	pbuf_free(udpTestBuf);
}

extern struct udp_pcb *udpTelemetryPCB;
extern ip_addr_t udpTelemetryIP;

uint8_t debugHF = 0;
uint8_t testValue = 0;

err_t udpErr = 1;
/*
void sendTelemetryMessage (void)
{
	char message[35];
	
	debugHF = 10;
	
	sprintf(message, "!T%04dP%04dD%04dZ%02dH0K%dX%04dY%04d#", tilt_aci_durumu, pan_aci_durumu, LRF_mesafesi, zoom_seviyesi, kameraSwitch, (int32_t)(pitch_value), (int32_t)(roll_value));
	
	debugHF = 11;
	
	IP_ADDR4(&udpTelemetryIP, TELEMETRY_IP_ADDR0, TELEMETRY_IP_ADDR1, TELEMETRY_IP_ADDR2, TELEMETRY_IP_ADDR3);
	udpErr = udp_connect(udpTelemetryPCB, &udpTelemetryIP, UDP_TELEMTRY_PORT);

	if (udpErr == ERR_OK)
	{
		struct pbuf *udpTelemetryBuf;
		udpTelemetryBuf = pbuf_alloc(PBUF_TRANSPORT, 35, PBUF_RAM);

		if (udpTelemetryBuf != NULL)
		{
			memcpy(udpTelemetryBuf->payload, (char *)message, 36);
			udp_sendto(udpTelemetryPCB, udpTelemetryBuf, &udpTelemetryIP, UDP_TELEMTRY_PORT);

			udp_disconnect(udpTelemetryPCB);
			pbuf_free(udpTelemetryBuf);
		}
	}
	debugHF = 2;
}
*/
void udpMessageTask (void)
{
	if (UDP_MesajGeldi)
	{
		resetFlag = 0;
		resetCounter = 0;
		
		//udpParser();
		UDP_MesajGeldi = 0;
		
		sendUDPMessage(defMessage);
		
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_SET);
	}

	if (udpMessageTimeout > 200)
	{
		//motorEmergencyStop();
		//firstEmergencyFlag = 0;
		kule_enable=0;
		resetFlag = 1;
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_15, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOE, GPIO_PIN_12, GPIO_PIN_RESET);
	}
	
}

void telemetryTask (void)
{
	if (telemetriCounter > 300) //300
	{
		telemetriCounter = 0;
	//	sendTelemetryMessage();
	}
}
