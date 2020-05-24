#include "main.h"
//#include "uart.h"

//#define RX_DATA buffer
//串口中断接收任意长度字节
Frame_Typedef frame[FRAME_QUANTITY];     		//开2个帧缓存
Uart_Frame_Typedef uart1;										//

unsigned char uart_frame_id;


void Uart_Time_Even(void){             			//串口接收用在定时器上的事件 用来判断超时

		if(uart1.status !=FREE){
			uart1.time_out++;

				if(uart1.time_out>=FRAME_TIMEOUT){			//完成一帧的接收
					uart1.status=FREE;						//串口标记为空闲



					frame[uart1.frame_id].status=1;  		//当前缓存帧的状态 0以处理 1未处理

					uart_frame_id=uart1.frame_id;			//传出当前缓存的编号在main中处理
				    /*
					此处添加帧处理程序
					*/
					uart_frame_id=uart1.frame_id;			//传出当前缓存的编号在main中处理
					uart1.frame_id++;

					Uart_Data_Processing();                	//数据处理 切换缓存的数组后 再处理前一个缓存中的数据避免数据覆盖

					if(uart1.frame_id >= FRAME_QUANTITY){
					uart1.frame_id=0;
					}
				}
		}
	}


void Receive_Interrupt(){     			//进一次串口中断
	     if(uart1.status!=BUSY){
					uart1.status=BUSY;
					frame[uart1.frame_id].length=0;
			 }


	      	  	//接收一字节
	    frame[uart1.frame_id].buffer[frame[uart1.frame_id].length]=  buffer[0];



	     	 	frame[uart1.frame_id].length++;
				if(frame[uart1.frame_id].length>=19){
				frame[uart1.frame_id].length=19;
				}
				uart1.time_out=0;
}

/*数据处理
 * 放在main里面处理数据
*/
void Uart_Data_Processing(){
	if(frame[uart_frame_id].status!=0){    			//接收到数据后status=1;

	HAL_UART_Transmit(&huart1,(uint8_t*)frame[uart_frame_id].buffer,frame[uart_frame_id].length,10);

	frame[uart_frame_id].status=0;					//处理完数据后status 清0;
	}
}


/*
 * 串口回调函数
 * 根据HAL_UART_Receive_IT(&huart1,buffer,1);
 * 的最后一位设定每接收x个字节进一次回调
 * 每一个串口的结构体都包含一个指针
 * 这个指针指向用户定义的一个数组来缓存数据
 * buffer为指向的数组名1为接收的长度
 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance == USART1)	// 判断是由哪个串口触发的中断
	{
		Receive_Interrupt();

		//HAL_UART_Transmit(&huart1,(uint8_t*)"0",2,10);


		HAL_UART_Receive_IT(&huart1,buffer,1);		// 重新使能串口1接收中断
	}
}

//发送字符串
void HAL_UART_Transmit_Str(UART_HandleTypeDef *huart,uint8_t *p)
{
	uint8_t temp=0;

	while(*p!='\0'){
		p++;
		temp++;
	}
	HAL_UART_Transmit(huart,p-temp,temp,10); //传入的值的地址不用加&

}

