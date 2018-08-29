#include "config.h"
#include "io_config.h"
#include "io_pin.h"

uint16_t ADC1ConvertedValue[ANALOG_PIN_AMOUNT];
ADC_HandleTypeDef	AdcHandle;

void ADC_DMA_CONFIG(void)
{
	CREATE_ANALOG_PIN();

	AdcHandle.Instance = ADCx;

	AdcHandle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
	AdcHandle.Init.Resolution = ADC_RESOLUTION_12B;
	AdcHandle.Init.ScanConvMode = ENABLE;
	AdcHandle.Init.ContinuousConvMode = ENABLE;
	AdcHandle.Init.DiscontinuousConvMode = DISABLE;
	AdcHandle.Init.NbrOfDiscConversion = 0;
	AdcHandle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
	AdcHandle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
	AdcHandle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
	AdcHandle.Init.NbrOfConversion = ANALOG_PIN_AMOUNT;
	AdcHandle.Init.DMAContinuousRequests = ENABLE;
	AdcHandle.Init.EOCSelection = DISABLE;

	HAL_ADC_Init(&AdcHandle);
	
	ADC_CHANNEL_CONFIG(ADCx_CHANNEL_1, 1, ADC_SAMPLETIME_144CYCLES, 0);
	ADC_CHANNEL_CONFIG(ADCx_CHANNEL_2, 2, ADC_SAMPLETIME_144CYCLES, 0);

	HAL_ADC_Start_DMA(&AdcHandle, (uint32_t*)ADC1ConvertedValue, ANALOG_PIN_AMOUNT);
}

void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef          GPIO_InitStruct;
  static DMA_HandleTypeDef  hdma_adc;
  
  ADCx_CHANNEL_GPIO_CLK_ENABLE();
  ADCx_CLK_ENABLE();
  DMAx_CLK_ENABLE(); 
  
  GPIO_InitStruct.Pin = ACCEL_BRAKE.PIN | STEERING.PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  hdma_adc.Instance = ADCx_DMA_STREAM;
  
  hdma_adc.Init.Channel  = ADCx_DMA_CHANNEL;
  hdma_adc.Init.Direction = DMA_PERIPH_TO_MEMORY;
  hdma_adc.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_adc.Init.MemInc = DMA_MINC_ENABLE;
  hdma_adc.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  hdma_adc.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  hdma_adc.Init.Mode = DMA_CIRCULAR;
  hdma_adc.Init.Priority = DMA_PRIORITY_LOW;
  hdma_adc.Init.FIFOMode = DMA_FIFOMODE_DISABLE;         
  hdma_adc.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
  hdma_adc.Init.MemBurst = DMA_MBURST_SINGLE;
  hdma_adc.Init.PeriphBurst = DMA_PBURST_SINGLE;

  HAL_DMA_Init(&hdma_adc);
  
  __HAL_LINKDMA(hadc, DMA_Handle, hdma_adc);

  HAL_NVIC_SetPriority(ADCx_DMA_IRQn, 0, 0);   
  HAL_NVIC_EnableIRQ(ADCx_DMA_IRQn);
}

void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
  static DMA_HandleTypeDef  hdma_adc;
  
  ADCx_FORCE_RESET();
  ADCx_RELEASE_RESET();

  HAL_GPIO_DeInit(STEERING.PORT, STEERING.PIN);
  HAL_GPIO_DeInit(ACCEL_BRAKE.PORT, ACCEL_BRAKE.PIN);
  
  HAL_DMA_DeInit(&hdma_adc); 

  HAL_NVIC_DisableIRQ(ADCx_DMA_IRQn);
}

void ADC_CHANNEL_CONFIG (uint32_t ADC_CHANNEL, uint32_t RANK, uint32_t ADC_SAMPLETIME_xCYCLES, uint32_t OFFSET)
{
	ADC_ChannelConfTypeDef sConfig;
	
	sConfig.Channel = ADC_CHANNEL;
	sConfig.Rank = RANK;
	sConfig.SamplingTime = ADC_SAMPLETIME_xCYCLES;
	sConfig.Offset = OFFSET;

	HAL_ADC_ConfigChannel(&AdcHandle, &sConfig);
}

void DIGITAL_IN_CONFIG(void) {
	CREATE_DIGITAL_IN_PIN();

	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitStructure.Pin = HAZARD_LIGHTS.PIN  | IGNITION.PIN | MANUAL_OVERRIDE.PIN | HAND_BRAKE.PIN |GEAR_D.PIN | GEAR_N.PIN |GEAR_R.PIN | GEAR_P.PIN  | ENGINE_STARTER.PIN | SIGNAL_RIGHT.PIN | SIGNAL_LEFT.PIN; // GPIOE All Pins;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = HEADLIGHTS.PIN | IR_LIGHTS.PIN | TAIL_LIGHTS.PIN;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void DIGITAL_OUT_CONFIG(void) {
	CREATE_DIGITAL_OUT_PIN();

	GPIO_InitTypeDef GPIO_InitStructure;
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitStructure.Pin = LED_GEAR_P.PIN | LED_GEAR_N.PIN | LED_GEAR_D.PIN | LED_GEAR_R.PIN;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLDOWN;
 	GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = BLINK.PIN;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStructure);
}
