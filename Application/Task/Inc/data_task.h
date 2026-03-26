/**
 * @file data_task.h
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __DATA_TASK_H
#define __DATA_TASK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "cmsis_os.h"

#include "conf_task.h"
#include "driver.h"
#include "device.h"

void StartDataProcessTask(void *argument);

#ifdef __cplusplus
}
#endif

#endif /* __DATA_TASK_H */
