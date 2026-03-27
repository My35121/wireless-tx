/**
 * @file data_task.c
 * @author Iassc
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "data_task.h"

extern filter_t filter;

uint8_t test_group[6] = {1, 2, 3, 4, 5, 6};
extern UART_HandleTypeDef huart3;

void StartDataProcessTask(void *argument)
{
    uint32_t data_read = 0;
    /* Infinite loop */
    for(;;)
    {
        // Wait for data event
        data_read = osEventFlagsWait(xDataProcessEventHandle, ADC_DATA_READY_BIT | USART1_DATA_READY_BIT, osFlagsNoClear, osWaitForever);
        
        // Read ADC data
        if (data_read & ADC_DATA_READY_BIT)
        {
            // Process ADC data
            ADC1_Read();
			
			//usart send data
            HAL_UART_Transmit_DMA(&huart3, test_group, sizeof(test_group));//use fot test
			//UART_SendFloat_ASCII(filter.filter_charge_i);
            osEventFlagsClear(xDataProcessEventHandle, ADC_DATA_READY_BIT);
        }
        // Read USART1 data
        if (data_read & USART1_DATA_READY_BIT)
        {
            // Process USART1 data
            if (RFID_Detect())
            {
                rfid_detect_state = eDETECT;
            }
            osEventFlagsClear(xDataProcessEventHandle, USART1_DATA_READY_BIT);
        }
        osDelay(1);
				
    }
}
