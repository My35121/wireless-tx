/**
 * @file control_task.h
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __CONTROL_TASK_H
#define __CONTROL_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "cmsis_os.h"
#include "string.h"

#include "conf_task.h"
#include "device.h"
#include "driver.h"

rfid_detect_state_t rfid_detect_state = eRESET;

void StartControlTask(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* __CONTROL_TASK_H */
