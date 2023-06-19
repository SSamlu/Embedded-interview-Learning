/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
uint8_t rx = 0;
#define sizeOfBuffer 10

uint8_t i2cSlaveRX = 0b00000000;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void modeSDA(uint8_t modeGPIO) {
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = SDA_Master_Pin;
	GPIO_InitStruct.Mode = modeGPIO;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	if(modeGPIO == GPIO_MODE_OUTPUT_PP) GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void delayUs(uint16_t timeDelay){
    __HAL_TIM_SET_COUNTER(&htim2,0);  // set the counter value a 0
    while (__HAL_TIM_GET_COUNTER(&htim2) < timeDelay);  // wait for the counter to reach the us input in the parameter
}

void I2C_start() {
	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, LOW_MODE);
	delayUs(100);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	delayUs(100);
}
void I2C_Stop(void){
	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, HIGH_MODE);
	delayUs(100);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
	delayUs(100);
}

void I2C_Send_Byte(uint8_t txBuffer){
//	uint8_t txBuffer =  txd;0b01001110, 0b01000100, 0b00001
	for(uint8_t i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, ((txBuffer & 0x80) > 0) ? HIGH_MODE : LOW_MODE);
		delayUs(100);
		HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
		delayUs(100);
		HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
		delayUs(100);
		txBuffer <<= 1;
	}
	modeSDA(GPIO_MODE_INPUT); //listen ACK is 0 or 1

	if(HAL_GPIO_ReadPin(GPIOB, SDA_Master_Pin) == HIGH_MODE) {
		modeSDA(GPIO_MODE_OUTPUT_PP);
		I2C_Stop();
	}
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
	delayUs(100);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	delayUs(100);
	modeSDA(GPIO_MODE_OUTPUT_PP);
}
void I2C_Ack(void){
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	modeSDA(GPIO_MODE_OUTPUT_PP);
	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, ACK);
	delayUs(10);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
	delayUs(10);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	delayUs(10);
}
void I2C_NAck(void){
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	modeSDA(GPIO_MODE_OUTPUT_PP);
	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, NACK);
	delayUs(10);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
	delayUs(10);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	delayUs(10);
}

uint8_t I2C_Wait_Ack(void){
	uint8_t time=0;
	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, HIGH_MODE);
	modeSDA(GPIO_MODE_INPUT);
	delayUs(1);
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
	delayUs(1);
	while(HAL_GPIO_ReadPin(GPIOB, SDA_Master_Pin)){
		time++;
		if(time>250) {
			I2C_Stop();
			return 1;
		}
	}
	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
	return 0;
}

uint8_t I2C_Read_Byte(unsigned char ack){
	uint8_t rxBuffer = 0b1000100;
	modeSDA(GPIO_MODE_INPUT);
	for(uint8_t i = 0; i < 8; i++) {
		HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
		rxBuffer <<= 1;
		rxBuffer |= HAL_GPIO_ReadPin(GPIOB, SDA_Master_Pin);
		delayUs(100);
		HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
		delayUs(100);
	}
//	modeSDA(GPIO_MODE_OUTPUT_PP);
//	HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, ACK);
//	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, HIGH_MODE);
//	delayUs(100);
//	HAL_GPIO_WritePin(GPIOB, SCL_Master_Pin, LOW_MODE);
//	delayUs(100);
	if(!ack){
		I2C_Ack();
	} else {
	 I2C_NAck();
	}
	return rxBuffer;
}

void sendDataByI2C(){
	I2C_start();
	I2C_Send_Byte(0x06<<1|0); // bit address
	I2C_Send_Byte(0b01000100);
	I2C_Stop();
	HAL_Delay(1000);
	I2C_start();
	I2C_Send_Byte(0x06<<1|0); // bit address
	I2C_Send_Byte(0b01001110);
	I2C_Stop();
	HAL_Delay(1000);
}
void readDataByI2C(){
	uint8_t rxBuffer = 0;
	I2C_start();
	I2C_Send_Byte(0x06<<1|1); // bit address
	rxBuffer = I2C_Read_Byte(0);
	I2C_Stop();
	HAL_Delay(1000);
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c) {
	// Xử lý dữ liệu nhận được từ Master
	if (hi2c->Instance == I2C1) {
		if (hi2c->XferCount == 1) { // Chỉ nhận được 1 byte dữ liệu
			rx = i2cSlaveRX;
//			rxBuffer[RX_Index] = spiSlaveRX;
//				  RX_Index++;
//				  if(RX_Index == sizeOfBuffer)
//				  	{
//				  		RX_Index=0;
//				  		uint8_t i=0;
//				  		for(i=0;i<sizeOfBuffer;i++)
//				  		{
//				  			rxBuffer[i]=0;
//				  		}
//				  	}
//			HAL_I2C_Slave_Receive_IT(&hspi1, &i2cSlaveRX, 1);
		}

	}
}

void HAL_I2C_SlaveTxCpltCallback(I2C_HandleTypeDef *hi2c) {
	static uint8_t charr = 'H';
	if (hi2c->Instance == I2C1) {
		if(charr == 'H') {
			hi2c->pBuffPtr[0] = 'L';
			charr = 'L';
		} else {
			hi2c->pBuffPtr[0] = 'H';
			charr = 'H';
		}
	}
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start(&htim2);
  HAL_I2C_Init(&hi2c1);
  HAL_I2C_EnableListen_IT(&hi2c1);
  I2C_Stop();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  sendDataByI2C();
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, HIGH_MODE);
//	  HAL_Delay(100);
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, LOW_MODE);
//	  HAL_Delay(100);
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, HIGH_MODE);
//	  HAL_Delay(100);
//	  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, HIGH_MODE);
//	  HAL_Delay(100);
//	  HAL_GPIO_WritePin(GPIOB, SDA_Master_Pin, HIGH_MODE);
//	  HAL_Delay(100);
//	  readDataByI2C();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 36000;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 1999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|SCL_Master_Pin|SDA_Master_Pin|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB12 SCL_Master_Pin SDA_Master_Pin PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|SCL_Master_Pin|SDA_Master_Pin|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
