#include "dev_rfid.h"


//2025赛季
// 卡1：02 30 38 30 30 32 41 30 33 46 38 44 39 03
// 卡2：02 30 38 30 30 32 39 44 33 37 45 38 43 03
// 卡3：02 30 38 30 30 32 39 45 38 30 37 43 45 03
// 卡4：02 30 38 30 30 32 39 45 42 43 31 30 42 03
// 卡5：02 30 38 30 30 32 39 46 30 38 42 35 41 03

//2026赛季
// 卡10：02 30 38 30 30 32 39 38 46 46 43 35 32 03 
// 卡11：02 30 38 30 30 32 39 35 35 32 31 35 35 03 
// 卡12：02 30 38 30 30 32 39 44 33 44 36 32 34 03 
// 卡13：02 30 38 30 30 32 39 42 39 39 36 30 45 03 
// 卡14：02 30 38 30 30 32 39 46 45 35 41 38 35 03 

#define RFID_CODE_SIZE 14
#define RFID_CARD_COUNT 12
uint8_t rx_rfid_code[RFID_CODE_SIZE] = {0};
uint8_t RFID_Codes[RFID_CARD_COUNT][RFID_CODE_SIZE] = {
    /*--------------------------------------2025--------------------------------------------------*/
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x41, 0x30, 0x33, 0x46, 0x38, 0x44, 0x39, 0x03}, // card 1
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x44, 0x33, 0x37, 0x45, 0x38, 0x43, 0x03}, // card 2
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x45, 0x38, 0x30, 0x37, 0x43, 0x45, 0x03}, // card 3
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x45, 0x42, 0x43, 0x31, 0x30, 0x42, 0x03}, // card 4
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x46, 0x30, 0x38, 0x42, 0x35, 0x41, 0x03}, // card 5
    {0X02, 0x30, 0x38, 0x30, 0x30, 0x32, 0X41, 0X31, 0X36, 0X39, 0X39, 0X41, 0X44, 0X03}, // card 6
    {0X02, 0x30, 0x38, 0x30, 0x30, 0x32, 0X39, 0X45, 0X30, 0X34, 0X37, 0X38, 0X36, 0X03}, // card 7
    /*--------------------------------------2026--------------------------------------------------*/
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x38, 0x46, 0x46, 0x43, 0x35, 0x32, 0x03}, // card 10
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x35, 0x35, 0x32, 0x31, 0x35, 0x35, 0x03}, // card 11
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x44, 0x33, 0x44, 0x36, 0x32, 0x34, 0x03}, // card 12
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x42, 0x39, 0x39, 0x36, 0x30, 0x45, 0x03}, // card 13
    {0x02, 0x30, 0x38, 0x30, 0x30, 0x32, 0x39, 0x46, 0x45, 0x35, 0x41, 0x38, 0x35, 0x03}  // card 14
};

uint8_t is_detect_rfid_code = 0;

void RFID_On(void)
{
    // RFID module on
    HAL_GPIO_WritePin(RFID_EN_GPIO_Port, RFID_EN_Pin, GPIO_PIN_SET);
}

void RFID_Off(void)
{
    // RFID module off
    HAL_GPIO_WritePin(RFID_EN_GPIO_Port, RFID_EN_Pin, GPIO_PIN_RESET);
    is_detect_rfid_code = 0;
    memset(rx_rfid_code, 0, sizeof(rx_rfid_code)); // Clear the RFID code buffer
}

uint8_t RFID_Detect(void)
{
    is_detect_rfid_code = 0;
    
    is_detect_rfid_code = Compare_RFID_Code(rx_rfid_code);

    if (is_detect_rfid_code) {
        return 1; // RFID detected and code matches
    }

    return 0; // RFID not detected or code does not match
}

uint8_t Compare_RFID_Code(uint8_t *rx_code) 
{
    for (uint8_t card = 0; card < RFID_CARD_COUNT; card++) {
        uint8_t match = 1;
        for (uint8_t i = 0; i < RFID_CODE_SIZE; i++) {
            if (rx_code[i] != RFID_Codes[card][i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            return 1; // Found a matching card
        }
    }
    return 0; // No matching card found
}
