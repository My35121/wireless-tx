/**
 * @file conf_task.h
 * @author Iassc
 * @brief 
 * @version 1.0
 * @date 2025-06-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __CONF_TASK_H__
#define __CONF_TASK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"

typedef enum {
    eRESET = 0,
    eDETECT = 1,
    ePRECHARGING,
    eCHARGING,
    eLOWPOWER,
}rfid_detect_state_t;

extern uint8_t rfid_detect_state;

extern osEventFlagsId_t xDataProcessEventHandle;


#ifdef __cplusplus
}
#endif

#endif /* __CONF_TASK_H__ */
