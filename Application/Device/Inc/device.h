/**
 * @file device.h
 * @author Iassc
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __DEVICE_H
#define __DEVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#include "dev_rfid.h"
#include "dev_charge.h"

void Device_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __DEVICE_H */
