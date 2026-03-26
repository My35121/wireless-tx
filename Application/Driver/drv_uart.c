#include "drv_uart.h"
#include "string.h"

uint8_t rx_dma_buffer1[RX_BUFFER_SIZE];
uint8_t rx_dma_buffer3[RX_BUFFER_SIZE];
void USART1_Init()
{
	HAL_UART_Receive_DMA(&huart1, rx_dma_buffer1, RX_BUFFER_SIZE);
}

void USART3_Init()
{
	HAL_UART_Receive_DMA(&huart3, rx_dma_buffer3, RX_BUFFER_SIZE);
}

void USART1_RxHandler(void)
{
    if(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(&huart1);
        memcpy(rx_rfid_code, rx_dma_buffer1, RX_BUFFER_SIZE);
		HAL_UART_Receive_DMA(&huart1, rx_dma_buffer1, RX_BUFFER_SIZE);
        // DETECT_RFID_CODE = Compare_RFID_Code(rx_dma_buffer1, RFID_Code_1);
        // DETECT_RFID = !HAL_GPIO_ReadPin(INT_GPIO_Port, INT_Pin);
//		memset(rx_dma_buffer1, 0, sizeof(rx_dma_buffer1));
        osEventFlagsSet(xDataProcessEventHandle, USART1_DATA_READY_BIT);
	}
}

void USART3_RxHandler(void)
{
    if(__HAL_UART_GET_FLAG(&huart3, UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(&huart3);
		HAL_UART_Receive_DMA(&huart3, rx_dma_buffer3, RX_BUFFER_SIZE);
	}
}

void UART_SendFloat_ASCII(float f)
{
    uint8_t buf[20];
    
    sprintf((char*)buf, "%.4f", f);
    
    HAL_UART_Transmit_DMA(&huart3, buf, strlen((char*)buf));
}