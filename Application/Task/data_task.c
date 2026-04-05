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
extern filter_t filter ;
extern adc_data_t adc_data;
float Detect_Value_temp = 0,i_out=0;
void StartDataProcessTask(void *argument)
{
    uint32_t data_read = 0;
    /* Infinite loop */
    for(;;)
    {
        // Wait for data event
        data_read = osEventFlagsWait(xDataProcessEventHandle, ADC_DATA_READY_BIT | USART1_DATA_READY_BIT, osFlagsNoClear, osWaitForever);
        WL_UART_printf("%.3f,%.3f\n",filter.filter_charge_i,(float)adc_data.adc_list_record[0]);
        // Read ADC data
        if (data_read & ADC_DATA_READY_BIT)
        {
            // Process ADC data
            ADC1_Read();
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
		
		for(int i = 0; i < 1000; i++)
    {
        Detect_Value_temp += (float)adc_data.adc_list_record[0];
    } //ÑÓÊ±+ÂË²¨
		i_out = Detect_Value_temp/1000;
		Detect_Value_temp=0;
		//WL_UART_printf("%.3f,%.3f\n",filter .filter_charge_i,(float)adc_data.adc_list_record[0]);
        osDelay(1);
				
    }
}
