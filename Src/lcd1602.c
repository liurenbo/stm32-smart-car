/*
        1602.C�ļ�
	1602�������ߴ���
*/
#include "lcd1602.h"

 
/* ���Һ��æ��æ */

 
/*��1602д��һ�ֽ�����,cmd-��д������ */
//д��ָ��PA4-7 RS-0  RW-0
void LCD1602_Write_Cmd(u8 cmd)
{
//	LCD1602_Wait_Ready();  //�ж�æ��æ
	HAL_Delay(15);
	LCD_RS_Clr();   
	LCD_RW_Clr();
//	GPIO_Write(cmd);  //�ȴ�����λ
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,cmd&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,(cmd<<1)&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,(cmd<<2)&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,(cmd<<3)&0x80);
	HAL_Delay(1);
	LCD_EN_Set();
	HAL_Delay(5);
	LCD_EN_Clr();
	
//	GPIO_Write(cmd<<4); //����λ���Ƶ�����λ
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,cmd&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,(cmd<<1)&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,(cmd<<2)&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,(cmd<<3)&0x08);
	
	HAL_Delay(1);
	LCD_EN_Set();
	HAL_Delay(5);
	LCD_EN_Clr();
}
 
/* ��1602д��һ�ֽ�����*/
void LCD1602_Write_Dat(u8 dat)
{
	HAL_Delay(15);
	LCD_RS_Set();   //1
	LCD_RW_Clr();   //0
	
//	GPIO_Write(dat);   //�ȴ�����λ
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,dat&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,(dat<<1)&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,(dat<<2)&0x80);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,(dat<<3)&0x80);
	HAL_Delay(1);
	LCD_EN_Set();  
	HAL_Delay(5);
	LCD_EN_Clr();
	
//	GPIO_Write(dat<<4); //����λ���Ƶ�����λ
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,dat&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,(dat<<1)&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,(dat<<2)&0x08);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,(dat<<3)&0x08);
	HAL_Delay(1);
	LCD_EN_Set();
	HAL_Delay(5);	
	LCD_EN_Clr();
	
}
 
/*����*/
void LCD1602_ClearScreen(void)
{
	LCD1602_Write_Cmd(0x01);
	
}
 
/* ����RAM��ʵ��ַ,�����λ��,��X,Y����Ӧ��Ļ�ϵ��ַ����� */
void LCD1602_Set_Cursor(u8 x, u8 y)
{
	u8 addr;
	
	if (y == 0)
		addr = 0x00 + x;
	else
		addr = 0x40 + x;
	LCD1602_Write_Cmd(addr | 0x80);
}
 
/* ��Һ������ʾ�ַ���,��X,Y��-��Ӧ��Ļ�ϵ���ʵ���꣬str-�ַ���ָ�� */
void LCD1602_Show_Str(u8 x, u8 y, u8 *str)
{
	LCD1602_Set_Cursor(x, y);
	while(*str != '\0')
	{
		LCD1602_Write_Dat(*str++);
	}
}
 
/* ��ʼ��Һ�� */
void LCD1602_Init(void)
{
	LCD1602_Write_Cmd(0x32);	 //��8λ����תΪ4λ����
	LCD1602_Write_Cmd(0x28);	//16*2��ʾ��5*7����4λ���ݿ�
	LCD1602_Write_Cmd(0x0C);	//����ʾ�����ر�
	HAL_Delay(10);
	LCD1602_Write_Cmd(0x06);	//���ֲ�������ַ�Զ�+1
	HAL_Delay(10);
	LCD1602_Write_Cmd(0x01);	//����
}

void GPIO_Write(u8 cmd)
{
	for(int i=0;i<4;i++)
	{
		if((cmd<<i)&0x80)
			HAL_GPIO_WritePin(GPIOA,1<(i+1),GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOA,1<(i+1),GPIO_PIN_RESET);
	}

}
