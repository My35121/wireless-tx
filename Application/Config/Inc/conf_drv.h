/**
 * @file conf_drv.h
 * @author Iassc
 * @brief 
 * @version 1.0
 * @date 2025-06-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __CONF_DRV_H   
#define __CONF_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

#define ADC_DATA_READY_BIT (1 << 0) // Event bit for ADC data ready
#define USART1_DATA_READY_BIT (1 << 1) // Event bit for USART1 data ready

extern osEventFlagsId_t xDataProcessEventHandle;

#ifdef __cplusplus
}
#endif

#endif 
