/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num){
   switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin | LED5_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB,  LED6_Pin, SET);
		break;

	case 1:
		HAL_GPIO_WritePin(GPIOB,  LED1_Pin | LED2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin , SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED1_Pin |  LED3_Pin | LED4_Pin |  LED6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED2_Pin | LED5_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin |LED1_Pin | LED2_Pin | LED3_Pin | LED6_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED4_Pin | LED5_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED1_Pin | LED2_Pin |  LED5_Pin | LED6_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED3_Pin | LED4_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED2_Pin | LED3_Pin |  LED5_Pin | LED6_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED1_Pin | LED4_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin |  LED2_Pin | LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED1_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED1_Pin | LED2_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin , SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED1_Pin | LED2_Pin | LED3_Pin | LED4_Pin | LED5_Pin | LED6_Pin , RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, LED0_Pin | LED1_Pin | LED2_Pin | LED3_Pin | LED5_Pin | LED6_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED4_Pin, SET);
		break;
   }
}
void display7SEG_1(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED8_Pin | LED9_Pin | LED10_Pin | LED11_Pin | LED12_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB,  LED13_Pin, SET);
		break;

	case 1:
		HAL_GPIO_WritePin(GPIOB, LED8_Pin | LED9_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED10_Pin | LED11_Pin | LED12_Pin | LED13_Pin , SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED8_Pin |  LED10_Pin | LED11_Pin |  LED13_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED9_Pin | LED12_Pin, SET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin |LED8_Pin | LED9_Pin | LED10_Pin | LED13_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED11_Pin | LED12_Pin, SET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, LED8_Pin | LED9_Pin |  LED12_Pin | LED13_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED10_Pin | LED11_Pin, SET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED9_Pin | LED10_Pin |  LED12_Pin | LED13_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED8_Pin | LED11_Pin, SET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin |  LED9_Pin | LED10_Pin | LED11_Pin | LED12_Pin | LED13_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED8_Pin, SET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED8_Pin | LED9_Pin, RESET);
		HAL_GPIO_WritePin(GPIOB, LED10_Pin | LED11_Pin | LED12_Pin | LED13_Pin , SET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED8_Pin | LED9_Pin | LED10_Pin | LED11_Pin | LED12_Pin | LED13_Pin , RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, LED7_Pin | LED8_Pin | LED9_Pin | LED10_Pin | LED12_Pin | LED13_Pin , RESET);
		HAL_GPIO_WritePin(GPIOB, LED11_Pin, SET);
		break;
   }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
/*
int dec_to_7seg(int num){
	switch(num){
	case 0: return 0x3f;
	case 1: return 0x06;
	case 2: return 0x5b;
	case 3: return 0x4f;
	case 4: return 0x66;
	case 5: return 0x6d;
	case 6: return 0x7D;
	case 7: return 0x07;
	case 8: return 0x7F;
	case 9: return 0x6f;
	default : return 0x00;
	}
}

void display7SEG(int num){
	int bit_var;
	bit_var = dec_to_7seg(num);
	HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, !(bit_var & 0x01));
	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, !((bit_var>>1)&0x01));
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, !((bit_var>>2)&0x01));
	HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, !((bit_var>>3)&0x01));
	HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, !((bit_var>>4)&0x01));
	HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, !((bit_var>>5)&0x01));
	HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, !((bit_var>>6)&0x01));
}
void display7SEG_1(int num){
	int bit_var;
	bit_var = dec_to_7seg(num);
	HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, !(bit_var & 0x01));
	HAL_GPIO_WritePin(LED8_GPIO_Port, LED8_Pin, !((bit_var>>1)&0x01));
	HAL_GPIO_WritePin(LED9_GPIO_Port, LED9_Pin, !((bit_var>>2)&0x01));
	HAL_GPIO_WritePin(LED10_GPIO_Port, LED10_Pin, !((bit_var>>3)&0x01));
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, !((bit_var>>4)&0x01));
	HAL_GPIO_WritePin(LED12_GPIO_Port, LED12_Pin, !((bit_var>>5)&0x01));
	HAL_GPIO_WritePin(LED13_GPIO_Port, LED13_Pin, !((bit_var>>6)&0x01));
}
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
      int8_t status = 2;
      int8_t count_green = 3;
      int8_t count_yellow = 2;
      int8_t count_red = 5;
      int8_t status1 = 0;
      int8_t count_green1 = 3;
      int8_t count_yellow1 = 2;
      int8_t count_red1 = 5;
      HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
      HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
      HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
      HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
      HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
      HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
  while (1)
  {
    /* USER CODE END WHILE */
	  //7SEG-LED1
	  if(status == 2){
	  	 		  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	  	 		  display7SEG(count_green--);
	  	 		  if(count_green == 0){
	  	 			  status = 1;
	  	 			  count_green = 3;
	  	 			  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	  	 		  }
	  	 	  }
	  	 	  if(status == 1){
	  	 		  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	  	 		  display7SEG(count_yellow--);
	  	 		  if(count_yellow == 0){
	  	 			  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	  	 			  count_yellow = 2;
	  	 			  status = 0;
	  	 		  }
	  	 	  }
	  	 	  if(status == 0){
	  	 		  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
	  	 		  display7SEG(count_red--);
	  	 		  if(count_red == 0){
	  	 			  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
	  	 			  status = 2;
	  	 			  count_red = 5;
	  	 		  }
	  	 	  }
	  	 	  //7 SEGMENT LED 2
	  	 	  	  	 if(status1 == 2){
	  	 	 	 		  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);
	  	 	 	 		   display7SEG_1(count_green1--);
	  	 	 	 		  if(count_green1 == 0){
	  	 	 	 			  status1 = 1;
	  	 	 	 			  count_green1 = 3;
	  	 	 	 			  HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
	  	 	 	 		  }
	  	 	 	 	  }
	  	 	 	 	 if(status1 == 1){
	  	 	 	 		  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	  	 	 	 		  display7SEG_1(count_yellow1--);
	  	 	 	 		  if(count_yellow1 == 0){
	  	 	 	 			  HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
	  	 	 	 			  count_yellow1 = 2;
	  	 	 	 			  status1 = 0;
	  	 	 	 		  }
	  	 	 	 	  }
	  	 	 	 	  if(status1 == 0){
	  	 	 	 		  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	  	 	 	 		  display7SEG_1(count_red1--);
	  	 	 	 		  if(count_red1 == 0){
	  	 	 	 			  HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	  	 	 	 			  status1 = 2;
	  	 	 	 			  count_red1 = 5;
	  	 	 	 		  }
	  	 	 	 	  }
	  	 	 	 HAL_Delay(1000);
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
  HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin|LED_YELLOW_Pin|LED_RED_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED0_Pin|LED1_Pin|LED2_Pin|LED10_Pin
                          |LED11_Pin|LED12_Pin|LED13_Pin|LED3_Pin
                          |LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_GREEN_Pin LED_YELLOW_Pin LED_RED_Pin LED_GREEN1_Pin
                           LED_YELLOW1_Pin LED_RED1_Pin */
  GPIO_InitStruct.Pin = LED_GREEN_Pin|LED_YELLOW_Pin|LED_RED_Pin|LED_GREEN1_Pin
                          |LED_YELLOW1_Pin|LED_RED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : LED0_Pin LED1_Pin LED2_Pin LED10_Pin
                           LED11_Pin LED12_Pin LED13_Pin LED3_Pin
                           LED4_Pin LED5_Pin LED6_Pin LED7_Pin
                           LED8_Pin LED9_Pin */
  GPIO_InitStruct.Pin = LED0_Pin|LED1_Pin|LED2_Pin|LED10_Pin
                          |LED11_Pin|LED12_Pin|LED13_Pin|LED3_Pin
                          |LED4_Pin|LED5_Pin|LED6_Pin|LED7_Pin
                          |LED8_Pin|LED9_Pin;
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
