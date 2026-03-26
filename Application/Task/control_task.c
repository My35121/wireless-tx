/**
 * @file control_task.c
 * @author Isaac
 * @brief 
 * @version 1.0
 * @date 2025-06-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "control_task.h"

#define LOWER_POWER_THRESHOLD 500 // Threshold for low power detection
uint32_t charge_time = 0;
uint32_t lowpower_time = 0;

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

void StartControlTask(void *argument)
{   

    Charge_Stop();
	
	HAL_TIM_Base_Start_IT(&htim3);
	HAL_TIM_Base_Start_IT(&htim4);
    /* Infinite loop */
    for(;;)
    {   
        HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET);
//        switch (rfid_detect_state)
//        {
//            case eRESET:
//            {
//                RFID_On();
//                Charge_Stop();
//                Charge_LED_OFF();
//                charge_time = 0;
//                lowpower_time = 0;
//        
//                break;
//            }

//            case eDETECT:
//            {
//                charge_time++;
//                Charge_LED_ON();
//                if (charge_time >= 500)
//                {
//                    rfid_detect_state = ePRECHARGING;
//                }
//                if (!RFID_Detect())
//                {
//                    rfid_detect_state = eRESET;
//                    charge_time = 0;
//                }
//                
//                break;
//            }

//            case ePRECHARGING:
//            {
//                charge_time++;
//                RFID_Off();
//                Charge_LED_ON();
//                
//                if (charge_time >= 600)
//                {
//                    rfid_detect_state = eCHARGING;
//                }

//                break;
//            }

//            case eCHARGING:
//            {
//                charge_time++;
//                RFID_Off();
//                Charge_LED_ON();
//                Charge_Start();

//                if (adc_data.charge_i < 1000.f)
//                {
//                    lowpower_time++;
//                }
//                else if (adc_data.charge_i > 3000.f)
//                {
//                    lowpower_time = 0;
//                }

//                if (lowpower_time >= LOWER_POWER_THRESHOLD)

//                {
//                    rfid_detect_state = eLOWPOWER;
//                    charge_time = 0;
//                    lowpower_time = 0;
//                }

//                break;
//            }

//            case eLOWPOWER:
//            {
//                rfid_detect_state = eRESET;
//                Charge_Stop();
//                Charge_LED_OFF();

//                break;
//            }

//            default:
//            {
//                RFID_Off();
//                Charge_Stop();
//                Charge_LED_OFF();

//                break;
//            }
//        }
	RFID_Off();
        osDelay(1);
    }
}
