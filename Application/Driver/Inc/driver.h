/**
 * @file driver.h
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __DRIVER_H
#define __DRIVER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "cmsis_os.h"

#include "drv_uart.h"
#include "drv_tim.h"
#include "drv_adc.h"

void Driver_Init(void);


#ifdef __cplusplus
}
#endif

#endif /* __DRIVER_H */
