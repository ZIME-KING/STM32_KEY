
#ifndef __KEY_FUNCTION_H
#define __KEY_FUNCTION_H

#include "main.h"
#define KEY_NUMBER 4
typedef struct
{
    uint8_t  event;   	 		 //按键输出事件 1短按，2长按，3超长按，4双击，5三击 ，0空闲
    uint8_t  edge_flag; 		 //边沿标记  1上升 2下降
	uint8_t  count; 	 		 //边沿检测
	uint16_t time_up_pre[2]; 	 //保存最近2次抬起的时间用来判断连击
	uint16_t time_down_pre; 	 //保存最近1次按下的时间

	uint16_t time_down;  		 //记录按下的时间
	uint16_t time_up; 			 //记录抬起的时间
	
} KEY_TypeDef;

/* Public Define */

#define KEY_PRESS 0x01
#define KEY_FREE  0x02

extern uint8_t key_value;
extern KEY_TypeDef key[KEY_NUMBER];

void Key_Timer_Interrupt();
void Key_Processing();

#endif



