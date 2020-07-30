#include "color.h"
int R=0,G=0,B=0;

int flag=0;
int Gray;//����Ҷ�ֵ
//int g_SF[3];//��TCS3200����źŵ�������ת��ΪRGB��׼ֵ��RGB����
float g_SF[3];//��TCS3200����źŵ�������ת��ΪRGB��׼ֵ��RGB����
int g_count = 0;//�����뷴���ǿ���ӦTCS3200��ɫ����������źŵ�������

//�������ڴ洢��1S��TCS3200����źŵ���������������RGB�������Ӿ���RGB��׼ֵ
int g_array[3];
int g_flag =0;//�˲���ģʽѡ��˳���־

//����������־λ�����ڶ�ֵ��ȡ��������
int getrate1=0;  
int getrate2=0;  
int getrate3=0;  


//��ʼ��TSC3200���������ŵ��������ģʽ
//����TCS3200D��������������Ƶ����������ź�Ƶ�ʵı�������Ϊ2%
void TSC_Init()
{
	TCS32_S0(0);TCS32_S1(1);
}



//ѡ���˲���ģʽ�������ú졢�̡��������ֹ���ͨ���˲���
void TSC_FilterColor(int Level01,int Level02)
{
	if(Level01 !=0)
		Level01 = 1 ;
	
	if(Level02 !=0)
		Level02 = 1 ;
	
	TCS32_S2(Level01);
	TCS32_S3(Level02);
}


//�жϺ���������TCS3200����źŵ�������
void TSC_Count()
{
	g_count ++;
}

//���÷�����к졢�̡�����ɫ��ֱ�ͨ���˲���ʱ��δ������ݵı�־
//�ú����� TSC����Callback��������
void TSC_WB(int Level0,int Level1)
{
	g_count = 0; //����ֵ����
	g_flag ++; //����źż�����־
	TSC_FilterColor(Level0,Level1);//�˲���ģʽ

}



//��ʱ���жϺ�����ÿ1S�жϺ󣬰Ѹ�ʱ���ڵĺ졢�̡������ֹ���ͨ���˲���ʱ��
//TCS3200����ź���������ֱ�洢������g_array[3]����ӦԪ�ر�����
void TSC_Call()
{
	switch (g_flag)
	
	{
		case 0:
			TSC_WB(0,0); //ѡ���ú�ɫ����ͨ���˲���ģʽ
		  break;
		case 1:
			
			flag=1;
		  g_array[0] = g_count;//�洢1S�ڵĺ��ͨ���˲���ʱ��TCS3200������������ ����
		  TSC_WB(1,1);//ѡ�����̹���ͨ���˲�����ģʽ
		  break;
		case 2:
			
			flag=2;
		  g_array[1] = g_count;//�洢1S�ڵ��̹�ͨ���˲���ʱ��TCS3200������������
		  TSC_WB(0,1);//ѡ����������ͨ���˲�����ģʽ
		  break;
		case 3:
			
			flag=3;
		  g_array[2] = g_count;//�洢1S�ڵ�����ͨ���˲���ʱ��TCS3200������������
		  TSC_WB(1,0);//ѡ�������˲�����ģʽ
		  
		  break;
		
		default:
			flag=4;
			g_count = 0;//����ֵ����

		  break;
		
	}
}




float Rrate=0,Grate=0,Brate=0; //�õ��ı������Ӷ�ֵ�����ں�����ɫ���ʱʹ��

//ʶ����ɫ������ʵʱ��⣬���  STOP_TIME;   ע�͵������򿪶�ʱ��
int TCS3200_Distinguish(void)
{
	
	
	int Blue1=1,Green1=2,Red1=3;
	
    switch(flag)
	{
		case 1:
			 g_SF[0] =255.0/g_array[0]; //��ɫ���������
		   //�ڴ����д�ӡ������������
		
		   getrate1++;//�ñ�־λgetrate1=1����������Ӷ��ﵽ����ĳһʱ�̱�������
		   if(getrate1==1)
			 {
				 Rrate=g_SF[0];
			 }
			 
		   flag=0;
		   break;
		
		case 2:
			 g_SF[1] =255.0/g_array[1]; //��ɫ���������
		
		   getrate2++;
		   if(getrate2==1)
				Grate=g_SF[1];
		   flag=0;
		   break;
		
		case 3:
			 g_SF[2] =255.0/g_array[2]; //��ɫ���������
		
		   getrate3++;
		   if(getrate3==1)
			 {
				 Brate=g_SF[2];
			 }
			 
		   flag=0;
		   break;
	}

	

	if(flag==4)
	{
		float Max=0,Min=0;
        float Rhsv=0,Ghsv=0,Bhsv=0;
        float H=0,S=0,V=0;
		
		R = (int)(g_array[0]*Rrate);
		G = (int)(g_array[1]*Grate);
		B = (int)(g_array[2]*Brate);
		flag=0;//ѡ�������ɫ�ı������Ӻ�RGB��־λ����
		g_flag =0;//�˲���ģʽѡ��˳���־λ����
		

		
		if((B>=150)&&(R<=150)&&(G<=150)) //��
			return Blue1;
		if((G>=150)&&(R<=150)&&(B<=150)) //��
			return Green1;
		if((R>=150)&&(B<=150)&&(G<=150)) //��
			return Red1;
		

		
	}
	return 0;
}



