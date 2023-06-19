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
#include "stdio.h"
#include "string.h"
#include "master.h"
//#include "slave.h"

#define sizeOfBuffer 10

uint8_t spiSlaveRX = 0b00000000;
uint8_t spiSlaveTX[sizeOfBuffer] = "a";
uint8_t data_Slave;

char rxBuffer[sizeOfBuffer];
char txBuffer[sizeOfBuffer];
uint8_t RX_Index = 0, Tx_index = 0;
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
SPI_HandleTypeDef hspi1;
SPI_HandleTypeDef hspi2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);
static void MX_SPI2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(hspi);
  if (hspi->Instance == SPI1) {

	  rxBuffer[RX_Index] = spiSlaveRX;
	  RX_Index++;
	  if(RX_Index == sizeOfBuffer)
	  	{
	  		RX_Index=0;
	  		uint8_t i=0;
	  		for(i=0;i<sizeOfBuffer;i++)
	  		{
	  			rxBuffer[i]=0;
	  		}
	  	}
	  HAL_SPI_Receive_IT(&hspi1, &spiSlaveRX, 1);
  }
  /* NOTE : This function should not be modified, when the callback is needed,
            the HAL_SPI_RxCpltCallback should be implemented in the user file
   */
}

void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi) {
	UNUSED(hspi);
	if(hspi->Instance == SPI1) {
//		txBuffer[Tx_index] = spiSlaveTX;
//		Tx_index++;
//		if (Tx_index == sizeOfBuffer) {
//			Tx_index = 0;
//			for(uint8_t i = 0; i < sizeOfBuffer; i++) {
//				txBuffer[i] = 0;
//			}
//		}
		HAL_SPI_Transmit_IT(&hspi1, spiSlaveTX, 1);
	}
};

/*
* Function: digitalWirte
* Description: set mode in signal pin for port A
* Input:
* 	  pinMode - uint8_t
* 	  value - uint8_t
* Output:
* 	  None
*/
void digitalWirte(uint8_t pinMode, uint8_t value) {
  	if(value == MODE_HIGH) GPIOA->BSRR = 1 << pinMode; //set to high level
  	else  GPIOA->BRR = 1 << pinMode; //Reset to low level
};

/*
* Function: SPIInit
* Description: init status of signal port
* Input:
* 	  None
* Output:
* 	  None
*/
void SPIInit(){
  	digitalWirte(CLK, MODE_LOW);
  	digitalWirte(MOSI, MODE_LOW);
//  	digitalWirte(MISO, MODE_LOW);
  	digitalWirte(SELECT_SERIAL, MODE_HIGH);
};

/*
* Function: clockSPIGenerate
* Description: Generate clock for SPI
* Input:
* 	  None
* Output:
* 	  None
*/
 void clockSPIGenerate(){
  	digitalWirte(CLK, MODE_HIGH);
  	HAL_Delay(100);
  	digitalWirte(CLK, MODE_LOW);
  	HAL_Delay(100);
};
/*
* Function: SPISlaveStatus
* Description: set status for slave to transmit or receive data
* Input:
* 	  mode - uint8_t
* Output:
* 	  None
*/
void SPISlaveStatus(uint8_t mode){
	digitalWirte(SELECT_SERIAL, mode);
};
/*
* Function: SPITransmitData
* Description: transmit data from master to slave
* Input:
* 	  data - uint8_t
* Output:
* 	  None
*/
void SPITransmitData(uint8_t data) {
  	uint8_t bit;
  	SPISlaveStatus(MODE_LOW);
  	for(bit = 0; bit < 8; bit++) {
  		digitalWirte(MOSI, (data & 0x80) ? MODE_HIGH : MODE_LOW);
  		clockSPIGenerate();
  		data <<= 1; //or data = data << 1;
  	}
  	SPISlaveStatus(MODE_HIGH);
};

/*
* Function: SPIReceiveData
* Description: Receive data from slave to master
* Input:
* 	  None
* Output:
* 	  Return: Rx_data from slave
*/
uint8_t SPIReceiveData() {
  	uint8_t Rx_data = 0b000000;
  	SPISlaveStatus(MODE_LOW);
  	for(uint8_t i = 0; i < 8; i++) {
  		digitalWirte(MOSI, MODE_LOW);
  		Rx_data <<= 1;
  		clockSPIGenerate();
//  		int a = HAL_GPIO_ReadPin(GPIOA, MISO);
  		Rx_data |= HAL_GPIO_ReadPin(GPIOA, MISO);
  	}
  	SPISlaveStatus(MODE_HIGH);
  	return Rx_data;
};

/*
* Function: SPITransmitDataSlave
* Description: transmit data from slave to master
* Input:
* 	  data - uint8_t
* Output:
* 	  None
*/
void SPITransmitDataSlave(uint8_t data) {
  	uint8_t bit;
  	SPISlaveStatus(MODE_LOW);
  	for(bit = 0; bit < 8; bit++) {
  		digitalWirte(MOSI, (data & 0x80) ? MODE_HIGH : MODE_LOW);
  		clockSPIGenerate();
  		data <<= 1; //or data = data << 1;
  	}
  	SPISlaveStatus(MODE_HIGH);
};

/*
* Function: SPIReceiveDataSlave
* Description: Receive data from master to slave
* Input:
* 	  None
* Output:
* 	  Return: Rx_data from slave
*/
uint8_t SPIReceiveDataSlave() {
  	uint8_t Rx_data = 0b000000;
  	SPISlaveStatus(MODE_LOW);
  	for(uint8_t i = 0; i < 8; i++) {
  		digitalWirte(MOSI, MODE_LOW);
  		Rx_data <<= 1;
  		clockSPIGenerate();
//  		int a = HAL_GPIO_ReadPin(GPIOA, MISO);
  		Rx_data |= HAL_GPIO_ReadPin(GPIOA, MISO);
  	}
  	SPISlaveStatus(MODE_HIGH);
  	return Rx_data;
};

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
  MX_SPI1_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  SPIInit();
  clockSPIGenerate();
//  SPITransmitData(spiMasterTX);
//  HAL_SPI_Transmit_IT(&hspi2, spiSlaveTX, 1);
//  SPIReceiveData();
  HAL_SPI_Receive_IT(&hspi1, &spiSlaveRX, 1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

    while (1)
    {
    /* USER CODE END WHILE */
		#if 1
			 for(uint8_t i = 'a'; i < 'z'; i++) {
				  SPITransmitData(i);
				  printf("data send from master to slave: %c\n", i);
				  HAL_Delay(100);
			  }
		#endif
		#if 0
			data_Slave = SPIReceiveData();
			printf("data receive from slave is: %c", data_Slave);
			HAL_Delay(100);
		#endif
		#if 0

		#endif

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
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_SLAVE;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_INPUT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

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
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, MISO_Slave_Pin|CLK_Pin|SELECT_SERIAL_Pin|MOSI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SPI2_CS_GPIO_Port, SPI2_CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : MOSI_Slave_Pin SS_Slave_Pin CLK_Slave_Pin MISO_Pin */
  GPIO_InitStruct.Pin = MOSI_Slave_Pin|SS_Slave_Pin|CLK_Slave_Pin|MISO_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : MISO_Slave_Pin CLK_Pin SELECT_SERIAL_Pin MOSI_Pin */
  GPIO_InitStruct.Pin = MISO_Slave_Pin|CLK_Pin|SELECT_SERIAL_Pin|MOSI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : SPI2_CS_Pin */
  GPIO_InitStruct.Pin = SPI2_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SPI2_CS_GPIO_Port, &GPIO_InitStruct);

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
