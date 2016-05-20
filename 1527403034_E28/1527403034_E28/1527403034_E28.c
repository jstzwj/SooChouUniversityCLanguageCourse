/*文件名：1527403034_E28.c
*作者：王俊
*时间：2015年11月13日
*功能：用选择法对10个整数排序，输出前后的情况。用随机数来初始化组。
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main()
{
	int a[N];
	int i,j,k,temp;
	int min;

	//随机初始化数组
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++)
	{
		a[i]=rand();
	}
	//输出排序前情况
	for(i=0;i<N;i++)
	{
		printf("%10d",a[i]);
	}
	printf("\n");
	//选择排序
	for(j=0;j<N-1;j++)
	{
		min=j;
		for(i=j;i<N;i++)
		{
			if(a[i]<a[min])
			{
				min=i;
			}
		}
		temp=a[min];
		for(k=min;k>j;k--)
		{
			a[k]=a[k-1];
		}

		a[j]=temp;
	}
	//输出排序后的情况
	for(i=0;i<N;i++)
	{
		printf("%10d",a[i]);
	}
	printf("\n");
	return 0;
}