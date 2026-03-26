/**
 * @file drv_adc.c
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "drv_adc.h"

//平均滤波
static float Filter_average(float new_value);

adc_data_t adc_data = {
    .num = 0,
    .charge_v_m = 1.0f,
    .charge_i_m = 1.0f,
    .charge_v_a = 0.0f,
    .charge_i_a = 0.0f};

filter_t filter = {
    .filter_index = 0,
    .filter_charge_i = 0,
};

/**
 * @brief Initializes the ADC peripheral.
 */
void ADC1_Init(void)
{

    HAL_ADCEx_Calibration_Start(&hadc1);
    HAL_Delay(10);
    HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_data.adc_list_record, ADC_BUFFER_SIZE);

    hdma_adc1.XferCpltCallback = ADC1_DMA_CpltCallback;

}
/**
 * @brief Reads the ADC values and updates the adc_data structure.
 */
void ADC1_Read(void)
{
    adc_data.charge_i = ((float)adc_data.adc_list_record[0] * 3300.f / 4096.0f - 1650.f) * 20.f * adc_data.charge_i_m + adc_data.charge_i_a;
    adc_data.charge_v = (float)adc_data.adc_list_record[1] * 3300.f / 4096.0f * 20.f * adc_data.charge_v_m + adc_data.charge_v_a;
    filter.filter_charge_i = Filter_average(adc_data.charge_i);
	
}

/**
 * @brief Callback function for ADC DMA transfer complete.
 * 
 * @param hdma Pointer to the DMA handle.
 */
void ADC1_DMA_CpltCallback(DMA_HandleTypeDef *hdma)
{
    if (hdma->Instance == DMA1_Channel1) {
        // ADC1_Read(); // Read ADC values and update adc_data
        osEventFlagsSet(xDataProcessEventHandle, ADC_DATA_READY_BIT);
    }
}

static float Filter_average(float new_value)
{
    static float sum = 0;

    // 移除旧值，加入新值
    sum -= filter.filter_buffer[filter.filter_index];
    sum += new_value;
    filter.filter_buffer[filter.filter_index] = new_value;

    // 更新索引
    filter.filter_index = (filter.filter_index + 1) % FILTER_SIZE;

    return sum / FILTER_SIZE;
}
