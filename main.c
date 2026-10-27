/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
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
void run_exercise_1(void);
void run_exercise_2(void);
void run_exercise_3(void);
void display7SEG(int num);
void run_exercise_4(void);
void set_traffic_lights(uint8_t red1, uint8_t yel1, uint8_t gre1, uint8_t red2, uint8_t yel2, uint8_t gre2);
void run_exercise_5(void);
void run_exercise_6(void);
void clearAllClock(void);
void setNumberOnClock(int num);
void clearNumberOnClock(int num);
void run_exercise_7(void);
void run_exercise_8(void);
void run_exercise_9(void);
void run_exercise_10(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //run_exercise_1();
	  //run_exercise_2();
	  //run_exercise_3();
	  //run_exercise_4();
	  //run_exercise_5();
	  //run_exercise_6();
	  //run_exercise_7();
	  //run_exercise_8();
	  //run_exercise_9();
	  run_exercise_10();

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
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin
                          |LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin
                           LED_RED_2_Pin LED_YELLOW_2_Pin LED_GREEN_2_Pin PA11
                           PA12 PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin
                          |LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin SEG_D_Pin
                           SEG_E_Pin SEG_F_Pin SEG_G_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void run_exercise_1(void) {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_Delay(2000);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_Delay(2000);
}
void run_exercise_2(void) {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
    HAL_Delay(5000);

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);
    HAL_Delay(3000);

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);
    HAL_Delay(2000);
}
void run_exercise_3(void) {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_RESET);
    HAL_Delay(3000);

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
    HAL_Delay(2000);

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
    HAL_Delay(3000);

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, GPIO_PIN_SET);
    HAL_Delay(2000);
}
void display7SEG(int num) {
    uint8_t seg_code[10] = {
        0x40,
        0x79,
        0x24,
        0x30,
        0x19,
        0x12,
        0x02,
        0x78,
        0x00,
        0x10
    };

    if (num >= 0 && num <= 9) {
        uint8_t pattern = seg_code[num];
        HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, (pattern & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, (pattern & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, (pattern & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, (pattern & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, (pattern & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, (pattern & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
        HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, (pattern & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}

void run_exercise_4(void) {
    for (int counter = 0; counter < 10; counter++) {
        display7SEG(counter);
        HAL_Delay(1000);
    }
}

void set_traffic_lights(uint8_t red1, uint8_t yel1, uint8_t gre1,
                        uint8_t red2, uint8_t yel2, uint8_t gre2) {
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, red1 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, yel1 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, gre1 ? GPIO_PIN_RESET : GPIO_PIN_SET);

    HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, red2 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, yel2 ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, gre2 ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void run_exercise_5(void) {
    set_traffic_lights(1, 0, 0,  0, 0, 1);
    display7SEG(5); HAL_Delay(1000);
    display7SEG(4); HAL_Delay(1000);
    display7SEG(3); HAL_Delay(1000);

    set_traffic_lights(1, 0, 0,  0, 1, 0);
    display7SEG(2); HAL_Delay(1000);
    display7SEG(1); HAL_Delay(1000);

    set_traffic_lights(0, 0, 1,  1, 0, 0);
    display7SEG(3); HAL_Delay(1000);
    display7SEG(2); HAL_Delay(1000);
    display7SEG(1); HAL_Delay(1000);

    set_traffic_lights(0, 1, 0,  1, 0, 0);
    display7SEG(2); HAL_Delay(1000);
    display7SEG(1); HAL_Delay(1000);
}

void run_exercise_6(void) {
    uint16_t clock_pins[12] = {
        GPIO_PIN_4,
        GPIO_PIN_5,
        GPIO_PIN_6,
        GPIO_PIN_7,
        GPIO_PIN_8,
        GPIO_PIN_9,
        GPIO_PIN_10,
        GPIO_PIN_11,
        GPIO_PIN_12,
        GPIO_PIN_13,
        GPIO_PIN_14,
        GPIO_PIN_15
    };

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            HAL_GPIO_WritePin(GPIOA, clock_pins[j], GPIO_PIN_SET);
        }

        HAL_GPIO_WritePin(GPIOA, clock_pins[i], GPIO_PIN_RESET);
        HAL_Delay(500);
        //HAL_Delay(1000);
    }
}

uint16_t clock_pins[12] = {
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
};

void clearAllClock(void) {
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(GPIOA, clock_pins[i], GPIO_PIN_SET);
    }
}

void run_exercise_7(void) {
    clearAllClock();
    HAL_Delay(1000);
}

/*
void run_exercise_7(void) {
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(GPIOA, clock_pins[i], GPIO_PIN_RESET);
    }
    HAL_Delay(1000);

    clearAllClock();
    HAL_Delay(1000);
}
*/

void setNumberOnClock(int num) {
    if (num >= 0 && num < 12) {
        HAL_GPIO_WritePin(GPIOA, clock_pins[num], GPIO_PIN_RESET);
    }
}

//Đối số setNumberOnClock(3);
void run_exercise_8(void) {
    clearAllClock();
    setNumberOnClock(3);
    HAL_Delay(1000);
}

/*
 void run_exercise_8(void) {
    clearAllClock();
    HAL_Delay(500);

    for (int i = 0; i < 12; i++) {
        setNumberOnClock(i);
        HAL_Delay(300);
    }
    HAL_Delay(1000);
}
 */

void clearNumberOnClock(int num) {
    if (num >= 0 && num < 12) {
        HAL_GPIO_WritePin(GPIOA, clock_pins[num], GPIO_PIN_SET);
    }
}

//Đổi số clearNumberOnClock(3);
void run_exercise_9(void) {
    for (int i = 0; i < 12; i++) setNumberOnClock(i);
    HAL_Delay(1000);
    clearNumberOnClock(3);
    HAL_Delay(1000);
}

/*
void run_exercise_9(void) {
    for (int i = 0; i < 12; i++) {
        setNumberOnClock(i);
    }
    HAL_Delay(1000);

    for (int i = 0; i < 12; i++) {
        clearNumberOnClock(i);
        HAL_Delay(300);
    }
    HAL_Delay(1000);
}
 */

void run_exercise_10(void) {
    //Chỉnh lại chỗ thời gian
    static int hour = 11;
    static int minute = 59;
    static int second = 50;

    clearAllClock();

    int hour_pos = hour % 12;
    int minute_pos = (minute / 5) % 12;
    int second_pos = (second / 5) % 12;

    setNumberOnClock(hour_pos);
    setNumberOnClock(minute_pos);
    setNumberOnClock(second_pos);

    //HAL_Delay(1000);
    HAL_Delay(50);

    second++;
    if (second >= 60) {
        second = 0;
        minute++;
        if (minute >= 60) {
            minute = 0;
            hour++;
            if (hour >= 24) {
                hour = 0;
            }
        }
    }
}



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
