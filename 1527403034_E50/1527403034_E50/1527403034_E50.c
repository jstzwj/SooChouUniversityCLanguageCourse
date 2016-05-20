/*文件名：1527403034_E50.c
*作者：王俊
*时间：2015年12月3日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
/*
	功能：对数组进行排序
	参数：int num[]		整型数组
		int len		有效长度
	返回值：无
*/
void Sort(int num[],int len);
/*
	功能：在屏幕上输出数组内容，每行输出6个元素，每个占8列
	参数：int num[]	整型数组
		int len	长度
	返回值：无
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