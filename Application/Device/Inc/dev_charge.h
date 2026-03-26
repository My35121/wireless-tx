#ifndef __CHARGE_H
#define __CHARGE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "tim.h"

#include "conf_dev.h"

void Charge_Start(void);
void Charge_Stop(void);
void Charge_LED_ON(void);
void Charge_LED_OFF(void);

#ifdef __cplusplus
}
#endif

#endif
