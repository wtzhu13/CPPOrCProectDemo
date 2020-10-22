/*******************************************************************************
 * All rights reserved, Copyright (C) wtzhu                                             
 * -----------------------------------------------------------------------------
 * [File Name]: 			main.c
 * [Description]: 		    串口通过PWM控制舵机
 *				
 * [Author]: 				  wtzhu	
 * [Date Of Creation]: 		202010
 * [Note]: 
 *
 * ------------------------------------------------------------------------------
 * Date					Author				Modifications
 * ------------------------------------------------------------------------------
 * 202010			  wtzhu			    Created
 *******************************************************************************/
#include<reg51.h>

#define uint unsigned int
#define uchar unsigned char
#define OPEN  1
#define CLOSE 0
#define HIGH  1
#define LOW   0

sbit SEV_PWM = P2^0;  // PWM1	  竖直方向舵机
sbit SEH_PWM = P2^4;  // PWM2	  水平方向舵机
uint count = 0;
 
uint command;
uchar flag = 0;		  // 串口中断响应标志
uint SEV_count; 
uint SEH_count;

 
/*******************************************
* 函数名：
* 功能：初始化
* 参数：
* 返回值：
********************************************/ 
void com_init()
{
	TMOD = 0x21;		// 定时器0工作方式1,定时器1工作方式2
    TH1 = 0xfd;			// 设置波特率9600
    TL1 = 0xfd;
	ET1 = CLOSE;    	// 关闭定时器1中断
    TR1 = OPEN;			// 打开定时器1
		
    TH0 = (65536 - 100)/256;
    TL0 = (65536 - 100)%256;
    ET0 = OPEN; 
	TR0 = OPEN;
		
    SM0 = 0;	  		// 设置串口模式
    SM1 = 1;
    REN = OPEN;
	ES = OPEN;
    EA = OPEN;

	SEV_count = 10;
	SEH_count = 10;
}

/*******************************************
* 函数名：
* 功能：主函数
* 参数：
* 返回值：
********************************************/
void main()
{
	com_init();
	while(1)
	{
			if(flag == 1)
			{
				flag = 0;
				ES = CLOSE;
				SBUF = command;
				while(!TI);
				TI = 0;
				ES = OPEN;
				// 根据串口信息的方向移动
				switch (command)
				{
				case 'w':
					{
						SEV_count--;
						if (SEV_count <= 5) SEV_count = 5;
						break;
					}
				case 's':
					{
						SEV_count++;
						if (SEV_count >= 15) SEV_count = 15;
						break;
					}
				case 'a':
					{
						SEH_count--;
						if (SEH_count <= 5) SEH_count = 5;
						break;
					}
				case 'd':
					{
						SEH_count++;
						if (SEH_count <= 15) SEH_count = 15;
						break;
					}
				case 'r':
					{
						SEV_count = 10;
						SEH_count = 10;
						break;
					}	
				default:
					break;
				}
			}
			
	}			
}

/*******************************************
* 函数名：
* 功能：定时器0中断
* 参数：
* 返回值：
********************************************/
void tim0() interrupt 1
{
//	TR0 = CLOSE;
	TH0 = (65536 - 100)/256;
  TL0 = (65536 - 100)%256;

	// 舵机1
	SEH_PWM = count <= SEH_count ? HIGH : LOW;

	// 舵机2
	SEV_PWM = count <= SEV_count ? HIGH : LOW;

	count++;
	if(count >= 200) count = 0;

//	TR0 = OPEN;
}

/*******************************************
* 函数名：
* 功能：
* 参数：
* 返回值：
********************************************/
void uart_ser() interrupt 4
{
	if (RI == 0)
	{
		return;
	}
	RI = CLOSE;
	command = SBUF;
	flag = 1;
}