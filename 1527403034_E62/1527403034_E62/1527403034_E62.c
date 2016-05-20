/*文件名：1527403034_E62.c
*作者：王俊
*时间：2015年12月17日
*功能：在61题的基础上在数组中插入一个整数
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
/*
	功能：在有序整型元素数组中插入一个数
	参数：int * p:整型数组
		  int *n:数组有效元素的个数
		  int num:插入的数
	返回值：无
*/
void insert(int * p,int *n,int num);
int main()
{
	int *num;
	int n=10;
	int i;
	int insert_num;
	//输入
	printf("请输入数组元素个数：\n");
	scanf("%d",&n);
	num=(int *)malloc(sizeof(int)*(n+1));		//多分配一个int
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
	/*-------------------------------------------------*/
	//输入
	printf("请输入一个要插入数组中的数:\n");
	scanf("%d",&insert_num);
	//插入
	insert(num,&n,insert_num);
	//输出
	printf("插入数字后结果为：\n");
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

void insert(int * p,int *n,int num)
{
	int i=0;
	int j;
	while(p[i]<num)
	{
		i++;
	}
	j=i;
	for(i=*n;i>j;i--)
	{
		p[i]=p[i-1];
	}
	p[i]=num;
	(*n)++;
}