/**
 * @file driver.c
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "driver.h"

/**
 * @brief Initializes all necessary peripherals for the driver module.
 * 
 */
void Driver_Init(void)
{
    // Initialize UART
    USART1_Init();
    USART3_Init();

    // Initialize ADC
    ADC1_Init();
}
