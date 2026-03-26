#include "dev_charge.h"

// 步骤一：PWM先不开，RFID-EN开启。ID一旦识别到，串口1就会收到重复的ID卡号信息，同时会有一个GPIO电平翻转（INT引脚）
// 步骤二：匹配ID信息后，RFID-EN拉低，LED-W拉高，亮白灯，代表识别并匹配了，再开启PWM。
// 注意RFID-EN拉高和PWM输出不能同时出现，否则必烧坏模块。
// 步骤三：由于现在原边没有电流检测电路，因此，充电结束与否的标志无法通过电流大小来显示，能量正常传输时，电流超过5A，
// 当车离开，线圈不正对，空载时电流1A左右。步骤一和步骤二两种状态的切换现在先用按键来手动切换。
// 或者能量传输设置一个固定时间15s就开始切换一二步骤，为了检录方便。

void Charge_Start(void)
{
    // 充电开始
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);    
    HAL_TIMEx_PWMN_Start(&htim1,  TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2); 
    HAL_TIMEx_PWMN_Start(&htim1,  TIM_CHANNEL_2);
	//风扇开转
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, FAN_COMPARE);   
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_4);    
    
}

void Charge_Stop(void)
{
    // 充电停止
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);    
    HAL_TIMEx_PWMN_Stop(&htim1,  TIM_CHANNEL_1);
    HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_2);
    HAL_TIMEx_PWMN_Stop(&htim1,  TIM_CHANNEL_2);
	//风扇停止
	HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_4);   
}

void Charge_LED_ON(void)
{
    // 充电指示灯打开
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LED_W_GPIO_Port, LED_W_Pin, GPIO_PIN_SET);
}

void Charge_LED_OFF(void)
{
    // 充电指示灯关闭
    HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED_W_GPIO_Port, LED_W_Pin, GPIO_PIN_RESET);
}

