#ifndef __UART_H
#define __UART_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "usart.h"
#include "stdio.h"
#include "conf_drv.h"

#define RX_BUFFER_SIZE 14

extern uint8_t rx_dma_buffer1[RX_BUFFER_SIZE];
extern uint8_t rx_rfid_code[RX_BUFFER_SIZE];

void USART1_Init(void);
void USART3_Init(void);
void USART1_RxHandler(void);
void USART3_RxHandler(void);

void UART_SendFloat_ASCII(float f);
#ifdef __cplusplus
}
#endif

#endif
