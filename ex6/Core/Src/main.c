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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
void displayClock(int num){
		switch(num){
			case 0:
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin , RESET);
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin , RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, LED_2_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, LED_3_Pin , RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOA, LED_4_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOA, LED_5_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOA, LED_6_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOA, LED_7_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
							LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOA, LED_8_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOA, LED_9_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_10_Pin | LED_11_Pin, SET);
				break;
			case 10:
				HAL_GPIO_WritePin(GPIOA, LED_10_Pin , RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_11_Pin, SET);
				break;
			case 11:
				HAL_GPIO_WritePin(GPIOA, LED_11_Pin, RESET);
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
					LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin , SET);
				break;
		}
}

void initialClock(){
	HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
				LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
}
void clearAllClock(){
	HAL_GPIO_WritePin(GPIOA, LED_0_Pin | LED_1_Pin | LED_2_Pin | LED_3_Pin | LED_4_Pin | LED_5_Pin | LED_6_Pin |
			LED_7_Pin | LED_8_Pin | LED_9_Pin | LED_10_Pin | LED_11_Pin, SET);
}
void setNumberOnClock(int num){
	      uint16_t display[12] ={0x001, 0x002, 0x004, 0x008, 0x010, 0x020, 0x040, 0x080,  0x100, 0x200, 0x400, 0x800};
		  uint16_t var;
	      var = display[num];
	      HAL_GPIO_WritePin(GPIOA, var<<4, GPIO_PIN_RESET);
}
void clearNumberOnClock(int num){
	switch(num){
			case 0:
				HAL_GPIO_WritePin(GPIOA, LED_0_Pin , SET);
				break;
			case 1:
				HAL_GPIO_WritePin(GPIOA, LED_1_Pin , SET);
				break;
			case 2:
				HAL_GPIO_WritePin(GPIOA, LED_2_Pin, SET);
				break;
			case 3:
				HAL_GPIO_WritePin(GPIOA, LED_3_Pin , SET);
				break;
			case 4:
				HAL_GPIO_WritePin(GPIOA, LED_4_Pin, SET);
				break;
			case 5:
				HAL_GPIO_WritePin(GPIOA, LED_5_Pin, SET);
				break;
			case 6:
				HAL_GPIO_WritePin(GPIOA, LED_6_Pin, SET);
				break;
			case 7:
				HAL_GPIO_WritePin(GPIOA, LED_7_Pin, SET);
				break;
			case 8:
				HAL_GPIO_WritePin(GPIOA, LED_8_Pin, SET);
				break;
			case 9:
				HAL_GPIO_WritePin(GPIOA, LED_9_Pin, SET);
				break;
			case 10:
				HAL_GPIO_WritePin(GPIOA, LED_10_Pin, SET);
				break;
			case 11:
				HAL_GPIO_WritePin(GPIOA, LED_11_Pin, SET);
				break;
	}
}
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
  initialClock();
  int second = 50, minute = 5,  hour = 0;
  while (1)
   {
 	  /* USER CODE BEGIN 3 */
     if(second >= 60){
     	second = 0;
     	clearNumberOnClock(11);
     	++minute;
     }

     if(minute >= 60){
     	minute = 0;
     	clearNumberOnClock(11);
     	hour++;
     }

     if(hour >= 24){
     	hour = 0;
     }
     if(second >=0 && second <5) setNumberOnClock(0);
     if(second >=5 && second <10) {
 	if(second == 5) clearNumberOnClock(0);
 	setNumberOnClock(1);
     }
     if(second >=10 && second <15) {
 	if(second == 10) clearNumberOnClock(1);
 	setNumberOnClock(2);
     }
    if(second >=15 && second <20) {
 	if(second == 15) clearNumberOnClock(2);
 	setNumberOnClock(3);
     }
    if(second >=20 && second <25) {
 	if(second == 20) clearNumberOnClock(3);
 	setNumberOnClock(4);
     }
    if(second >=25 && second <30) {
 	if(second == 25) clearNumberOnClock(4);
 	setNumberOnClock(5);
     }
    if(second >=30 && second <35) {
 	if(second == 30) clearNumberOnClock(5);
 	setNumberOnClock(6);
     }
     if(second >=35 && second <40) {
 	if(second == 35) clearNumberOnClock(6);
 	setNumberOnClock(7);
     }
     if(second >=40 && second <45) {
 	if(second == 40) clearNumberOnClock(7);
 	setNumberOnClock(8);
     }
     if(second >=45 && second <50) {
 	if(second == 45) clearNumberOnClock(8);
 	setNumberOnClock(9);
     }
    if(second >=50 && second <55) {
 	if(second == 50) clearNumberOnClock(9);
 	setNumberOnClock(10);
     }
    if(second >=55 && second <60) {
 	if(second == 55) clearNumberOnClock(10);
 	setNumberOnClock(11);
    }
 /*minute*/
     if(minute >=0 && minute <5) setNumberOnClock(0);
     if(minute >=5 && minute <10) {
 	if(minute == 5) clearNumberOnClock(0);
 	setNumberOnClock(1);
     }
     if(minute >=10 && minute <15) {
 	if(minute == 10) clearNumberOnClock(1);
 	setNumberOnClock(2);
     }
    if(minute >=15 && minute <20) {
 	if(minute == 15) clearNumberOnClock(2);
 	setNumberOnClock(3);
     }
    if(minute >=20 && minute <25) {
 	if(minute == 20) clearNumberOnClock(3);
 	setNumberOnClock(4);
     }
    if(minute >=25 && minute <30) {
 	if(minute == 25) clearNumberOnClock(4);
 	setNumberOnClock(5);
     }
    if(minute >=30 && minute <35) {
 	if(minute == 30) clearNumberOnClock(5);
 	setNumberOnClock(6);
     }
     if(minute >=35 && minute <40) {
 	if(minute == 35) clearNumberOnClock(6);
 	setNumberOnClock(7);
     }
     if(minute >=40 && minute <45) {
 	if(minute == 40) clearNumberOnClock(7);
 	setNumberOnClock(8);
     }
     if( minute >=45 && minute <50) {
 	if(minute == 45) clearNumberOnClock(8);
 	setNumberOnClock(9);
     }
    if(minute >=50 && minute <55) {
 	if(minute == 50) clearNumberOnClock(9);
 	setNumberOnClock(10);
     }
    if(minute >=55 && minute <60) {
 	if(minute == 55) clearNumberOnClock(10);
 	setNumberOnClock(11);
    }
 /*hour*/
     switch(hour){
         case 0:
         	setNumberOnClock(0);
         	break;
         case 1:
         	clearNumberOnClock(0);
         	setNumberOnClock(1);
         	break;
         case 2:
         	clearNumberOnClock(1);
         	setNumberOnClock(2);
         	break;
         case 3:
         	clearNumberOnClock(2);
         	setNumberOnClock(3);
         	break;
         case 4:
         	clearNumberOnClock(3);
         	setNumberOnClock(4);
         	break;
         case 5:
         	clearNumberOnClock(4);
         	setNumberOnClock(5);
         	break;
         case 6:
         	clearNumberOnClock(5);
         	setNumberOnClock(6);
         	break;
         case 7:
         	clearNumberOnClock(6);
         	setNumberOnClock(7);
         	break;
         case 8:
         	setNumberOnClock(8);
         	clearNumberOnClock(7);
         	break;
         case 9:
         	clearNumberOnClock(8);
         	setNumberOnClock(9);
         	break;
         case 11:
         	clearNumberOnClock(9);
         	setNumberOnClock(10);
         	break;
         case 12:
             clearNumberOnClock(11);
             setNumberOnClock(0);
             break;
         case 13:
         	clearNumberOnClock(0);
             setNumberOnClock(1);
             break;
         case 14:
         	clearNumberOnClock(1);
             setNumberOnClock(2);
             break;
         case 15:
         	clearNumberOnClock(2);
             setNumberOnClock(3);
             break;
         case 16:
         	clearNumberOnClock(3);
             setNumberOnClock(4);
             break;
         case 17:
         	clearNumberOnClock(4);
             setNumberOnClock(5);
             break;
         case 18:
         	clearNumberOnClock(5);
             setNumberOnClock(6);
             break;
         case 19:
         	clearNumberOnClock(6);
             setNumberOnClock(7);
             break;
         case 20:
         	clearNumberOnClock(7);
             setNumberOnClock(8);
             break;
         case 21:
         	clearNumberOnClock(8);
            	setNumberOnClock(9);
            	break;
         case 22:
         	clearNumberOnClock(9);
             setNumberOnClock(10);
             break;
         case 23:
         	clearNumberOnClock(10);
         	setNumberOnClock(11);
         	break;
         }
     second++;
     HAL_Delay(1000);
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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_0_Pin|LED_1_Pin|LED_2_Pin|LED_3_Pin
                          |LED_4_Pin|LED_5_Pin|LED_6_Pin|LED_7_Pin
                          |LED_8_Pin|LED_9_Pin|LED_10_Pin|LED_11_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_0_Pin LED_1_Pin LED_2_Pin LED_3_Pin
                           LED_4_Pin LED_5_Pin LED_6_Pin LED_7_Pin
                           LED_8_Pin LED_9_Pin LED_10_Pin LED_11_Pin */
  GPIO_InitStruct.Pin = LED_0_Pin|LED_1_Pin|LED_2_Pin|LED_3_Pin
                          |LED_4_Pin|LED_5_Pin|LED_6_Pin|LED_7_Pin
                          |LED_8_Pin|LED_9_Pin|LED_10_Pin|LED_11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
