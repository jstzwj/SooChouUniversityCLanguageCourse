/*�ļ�����1527403034_E50.c
*���ߣ�����
*ʱ�䣺2015��12��3��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
/*
	���ܣ��������������
	������int num[]		��������
		int len		��Ч����
	����ֵ����
*/
void Sort(int num[],int len);
/*
	���ܣ�����Ļ������������ݣ�ÿ�����6��Ԫ�أ�ÿ��ռ8��
	������int num[]	��������
		int len	����
	����ֵ����
*/
void PrintArry(int num[],int len);

int main()
{
	int num[N];
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		num[i]=rand();
	}
	Sort(num,N);
	PrintArry(num,N);
	printf("\n");
	return 0;
}

void Sort(int num[],int len)
{
	int i,j;
	int temp;
	for(i=len-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}

		}
	}
}

void PrintArry(int num[],int len)
{
	int i;
	int count=0;
	for(i=0;i<len;i++)
	{
		printf("%8d",num[i]);
		if((count+1)%6==0)
		{
			printf("\n");
		}
		count++;
	}
}