/*文件名：1527403034_E61.c
*作者：王俊
*时间：2015年12月17日
*功能：对任意一个整型元素的数组排序
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#define N 30
/*
	功能：对整型元素数组进行排序
	参数：int * p:整型数组
		  int n:数组有效元素的个数
	返回值：无
*/
void sort(int * p,int n);

int main()
{
	int *num;
	int n=10;
	int i;
	//输入
	printf("请输入数组元素个数：\n");
	scanf("%d",&n);
	num=(int *)malloc(sizeof(int)*n);
	if(num==NULL)
	{
		printf("内存分配失败\n");
		return 1;
	}
	printf("请输入数组的元素：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//排序
	sort(num,n);
	//输出
	printf("排序结果为：\n");
	for(i=0;i<n;i++)
	{
	printf("%5d",num[i]);
	}
	printf("\n");
	free(num);
	return 0;
}
//选择排序(从小到大)
void sort(int * p,int n)
{
	int i,j;
	int temp;
	int min;

	for(i=0;i<n-1;i++)
	{
		min=n-1;
		for(j=i;j<n;j++)
		{
			if(p[min]>p[j])
			{
				min=j;
			}
		}
		temp=p[min];
		p[min]=p[i];
		p[i]=temp;
	}
}