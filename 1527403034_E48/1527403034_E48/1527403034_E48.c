/*�ļ�����1527403034_E48.c
*���ߣ�����
*ʱ�䣺2015��12��3��
*���ܣ��������ʼ��һ����������,����Ԫ�ظ����Զ�����дһ�����������е����ֵ����д���������������ĺ�������.
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
/*
	���ܣ��������е����ֵ
	������int arry[]	��������
		int len		���鳤��
	����ֵ�����������ֵ
*/
int ArryMax(int arry[],int len);

int main()
{
	int i;
	int num[N];
	//�����ʼ��
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		num[i]=rand()%1000;
	}
	//ȫ�����
	for(i=0;i<N;i++)
	{
		printf("%5d",num[i]);
	}
	printf("\n");
	//�����������ֵ�����
	printf("���������ֵΪ%d\n",ArryMax(num,N));
	return 0;
}

int ArryMax(int arry[],int len)
{
	int i;
	int max;
	//Ϊmax����ֵ
	max=arry[0];
	for(i=0;i<len;i++)
	{
		if(arry[i]>max)
		{
			max=arry[i];
		}
	}
	//�������ֵ
	return max;
}