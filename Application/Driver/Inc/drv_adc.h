/**
 * @file drv_adc.h
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __DRV_ADC_H
#define __DRV_ADC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "adc.h"

#include "conf_drv.h"

#define FILTER_SIZE 1000
#define ADC_BUFFER_SIZE 2

typedef struct _adc_data_t{
    uint16_t adc_list_record[ADC_BUFFER_SIZE];
    uint8_t num;
    float charge_v;
    float charge_i;
    float charge_v_m;
    float charge_i_m;
    float charge_v_a;
    float charge_i_a;
}adc_data_t;


typedef struct _filter_t{
    float filter_buffer[FILTER_SIZE];
    uint8_t filter_index;
    float filter_charge_i;
    float input_charge_i;
} filter_t;
/**
 * @brief Initializes the ADC peripheral.
 */
void ADC1_Init(void);

/**
 * @brief Reads the ADC values and updates the adc_data structure.
 */
void ADC1_Read(void);

/**
 * @brief Callback function for ADC DMA transfer complete.
 * 
 * @param hdma Pointer to the DMA handle.
 */
void ADC1_DMA_CpltCallback(DMA_HandleTypeDef *hdma);

extern adc_data_t adc_data;

#ifdef __cplusplus
}
#endif

#endif /* __DRV_ADC_H */
