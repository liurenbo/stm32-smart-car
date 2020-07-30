#include"car.h"

void go(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,350);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,350);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 350);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,350);
}

void left(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,800);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,800);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 350);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,350);
}
void right(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,350);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,350 );
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 800);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,800);
}

void left1(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,600);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,600);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 600);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,600);
}
void left2(void)
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_RESET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,0);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 350);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,350);
}

void stop()
{
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1,0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3,0);
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_2,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4,0);
}

//int Blue1=1,Green1=2,Red1=3;
//ʶ����ɫ��ת��ķ���
void color_judge(int color)
{
	if(color==1)
	{
		left1();
		HAL_Delay(500);
		go();
		HAL_Delay(200);

	}
	if(color==2)
	{
		left1();
		HAL_Delay(800);
		go();
		HAL_Delay(200);
	}
	
	if(color==3)
	{
		left1();
		HAL_Delay(1000);
		go();
		HAL_Delay(200);
	}
}

//��������ת��ķ���
void color_end(int color)
{

	left1();
	HAL_Delay(800);
	go();
	HAL_Delay(200);
}


uint8_t q1=0;
uint8_t q2=0;
uint8_t q3=0;
uint8_t q4=0;

//����ʱ��С��Ѳ��
void car(void)
{
	q1 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3);
	q2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
	q3 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
	q4 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
	
	if(q1==0&&q2==0&&q3==0&&q4==0)  //�ĸ���Ϊ����ǰ��
		go();
	else if((q1==1||q2==1)&&q3==0)
		left();
	else if(q2==0&&(q3==1||q4==1))
		right();
	else if(q1==0&&q2==1&&q3==1&&q4==0)
		go();
	else
		stop();
}

//С������ʱ��Ѳ��
void car_back(void)
{
	q1 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3);
	q2 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4);
	q3 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5);
	q4 = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6);
	
	if(q1==0&&q2==0&&q3==0&&q4==0)  //�ĸ���Ϊ����ǰ��
		go();
	else if(q2==1&&q3==0)
		left();
	else if(q2==0&&q3==1)
		right();
	else if(q1==1&&q2==1&&q3==1&&q4==1)
	{
		
		left();
		HAL_Delay(1000);
		go();
		HAL_Delay(500);
	}
	
}