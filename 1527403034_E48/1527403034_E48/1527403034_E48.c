/*文件名：1527403034_E48.c
*作者：王俊
*时间：2015年12月3日
*功能：随机来初始化一个整型数组,数组元素个数自定。编写一函数求数组中的最大值。编写主函数测试上述的函数功能.
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
/*
	功能：求数组中的最大值
	参数：int arry[]	整型数组
		int len		数组长度
	返回值：数组中最大值
*/
int ArryMax(int arry[],int len);

int main()
{
	int i;
	int num[N];
	//随机初始化
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		num[i]=rand()%1000;
	}
	//全部输出
	for(i=0;i<N;i++)
	{
		printf("%5d",num[i]);
	}
	printf("\n");
	//计算数组最大值并输出
	printf("数组中最大值为%d\n",ArryMax(num,N));
	return 0;
}

int ArryMax(int arry[],int len)
{
	int i;
	int max;
	//为max赋初值
	max=arry[0];
	for(i=0;i<len;i++)
	{
		if(arry[i]>max)
		{
			max=arry[i];
		}
	}
	//返回最大值
	return max;
}