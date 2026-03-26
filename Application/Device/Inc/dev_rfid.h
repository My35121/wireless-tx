#ifndef __RFID_H
#define __RFID_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "string.h"

#include "conf_dev.h"


void RFID_On(void);
void RFID_Off(void);
uint8_t RFID_Detect(void);
uint8_t Compare_RFID_Code(uint8_t *rx_code);

#ifdef __cplusplus
}
#endif

#endif
