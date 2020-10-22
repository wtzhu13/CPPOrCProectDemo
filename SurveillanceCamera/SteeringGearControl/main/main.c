/*******************************************************************************
 * All rights reserved, Copyright (C) wtzhu                                             
 * -----------------------------------------------------------------------------
 * [File Name]: 			main.c
 * [Description]: 		    ����ͨ��PWM���ƶ��
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

sbit SEV_PWM = P2^0;  // PWM1	  ��ֱ������
sbit SEH_PWM = P2^4;  // PWM2	  ˮƽ������
uint count = 0;
 
uint command;
uchar flag = 0;		  // �����ж���Ӧ��־
uint SEV_count; 
uint SEH_count;

 
/*******************************************
* ��������
* ���ܣ���ʼ��
* ������
* ����ֵ��
********************************************/ 
void com_init()
{
	TMOD = 0x21;		// ��ʱ��0������ʽ1,��ʱ��1������ʽ2
    TH1 = 0xfd;			// ���ò�����9600
    TL1 = 0xfd;
	ET1 = CLOSE;    	// �رն�ʱ��1�ж�
    TR1 = OPEN;			// �򿪶�ʱ��1
		
    TH0 = (65536 - 100)/256;
    TL0 = (65536 - 100)%256;
    ET0 = OPEN; 
	TR0 = OPEN;
		
    SM0 = 0;	  		// ���ô���ģʽ
    SM1 = 1;
    REN = OPEN;
	ES = OPEN;
    EA = OPEN;

	SEV_count = 10;
	SEH_count = 10;
}

/*******************************************
* ��������
* ���ܣ�������
* ������
* ����ֵ��
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
				// ���ݴ�����Ϣ�ķ����ƶ�
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
* ��������
* ���ܣ���ʱ��0�ж�
* ������
* ����ֵ��
********************************************/
void tim0() interrupt 1
{
//	TR0 = CLOSE;
	TH0 = (65536 - 100)/256;
  TL0 = (65536 - 100)%256;

	// ���1
	SEH_PWM = count <= SEH_count ? HIGH : LOW;

	// ���2
	SEV_PWM = count <= SEV_count ? HIGH : LOW;

	count++;
	if(count >= 200) count = 0;

//	TR0 = OPEN;
}

/*******************************************
* ��������
* ���ܣ�
* ������
* ����ֵ��
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