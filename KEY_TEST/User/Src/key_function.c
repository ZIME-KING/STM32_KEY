#include "key_function.h"



#define KEY0_READ 	HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_7)
#define KEY1_READ 	HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)
#define KEY2_READ 	HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)
#define KEY3_READ 	HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)

#define SHORT_TIME 300        		//小于这个时间单击
#define SHORT_SHORT_TIME 120		//高电平小于这个时间有连击

#define LONG_TIME  500				//大于为长按
#define LONG_LONG_TIME  3000		//大于这个时间进入连按模式

#define FALL_EDGE 0xF0
#define RISE_EDGE 0x0F



KEY_TypeDef key[KEY_NUMBER]; //结构体包含按键状态值

/********************
 **功能：获取按键状态
 **输入按键的编号
 **返回值：1/0
 ********************/
static uint8_t Get_Key_Value(unsigned char temp) {
	switch (temp) {
	case 0:
		return KEY0_READ;
		break;

	case 1:
		return KEY1_READ;
		break;

	case 2:
		return KEY2_READ;
		break;

	case 3:
		return KEY3_READ;
		break;

	default:
		return 0;
		break;
	}
}

/********************************
 函数功能：获取键按下 和抬起时间的值
 *******************************/
void Get_Key_Time_Value() {
	static uint8_t i;						//加了static进入函数不会给清零，要么整个全局边量
	for (i = 0; i < KEY_NUMBER; i++) {
		if (key[i].edge_flag == KEY_PRESS) //如果按键按下（下降沿）开始计时到松开结束
			key[i].time_down++;
		else if (key[i].edge_flag == KEY_FREE) {
			key[i].time_up++;				//定时器间隔（1ms）加1，用来判断按键松开时长到下个下降沿结束
			if (key[i].time_up > 65000)
				key[i].time_up = 65000;
		}

	}
}

/************************
 函数功能：获取键按下的事件
 ***********************/
void Get_Key_Event() {
	static uint8_t i;
	for (i = 0; i < KEY_NUMBER; i++) {
		if (key[i].event == 0) {
			//短按
			if (key[i].time_down_pre > 0 && key[i].time_down_pre < SHORT_TIME) {
				key[i].event = 1;
			}

			//双击
			if (key[i].time_up_pre[1]>0 && key[i].time_up_pre[1]<SHORT_SHORT_TIME) {
				key[i].event = 4;
			}

			//三击
			if (key[i].time_up_pre[1]>0 && key[i].time_up_pre[0]<SHORT_SHORT_TIME && key[i].time_up_pre[1]<SHORT_SHORT_TIME) {
				key[i].event = 5;
			}

			//长按
			if (key[i].time_down_pre > LONG_TIME && key[i].time_down_pre < LONG_LONG_TIME) {
				key[i].event = 2;
			}
		}
	}
}

void Key_EdgeJudge() {
	static uint8_t i;

	for (i = 0; i < KEY_NUMBER; i++) {


		//持续按判断
		if (key[i].time_down > LONG_LONG_TIME) {
			key[i].event = 3;
		}

		//抬起后120ms再判断事件避免把双击顶掉
		if (key[i].time_up == SHORT_SHORT_TIME) {
			Get_Key_Event();
			key[i].time_down_pre = 0;
		}

		//边沿检测
		key[i].count <<= 1;					//放弃最老的值
		if (Get_Key_Value(i) == SET)		//写入新的值
			key[i].count++;   				//最低位加1   0000 0000->0000,0001->0000 0011

		//下降沿判断
		if (key[i].count == FALL_EDGE) {
			key[i].edge_flag = KEY_PRESS;

			key[i].time_up_pre[0] = key[i].time_up_pre[1];
			key[i].time_up_pre[1] = key[i].time_up;
			key[i].time_up = 0;			//清空time_up
		}

		//上升沿判断
		if (key[i].count == RISE_EDGE) {
			key[i].edge_flag = KEY_FREE;
			key[i].time_down_pre = key[i].time_down;
			key[i].time_down = 0;		//清空time_down
		}
	}
}

