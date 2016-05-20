/*文件名：1527403034_E59.c
*作者：王俊
*时间：2015年12月14日
*功能：求元素总和、最大值、最小值、平均值
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
/*
	功能：求元素总和、最大值、最小值、平均值
	参数：int num[]		待计算的数组
	int n		数组有效元素个数
	double *sum		总和
	double *max		最大值
	double *min		最小值
	double *average		平均值
	返回值：无
*/
void func(int num[],int n,double *sum,double *max,double *min,double *average);
int main()
{
	int num[N];
	int i;
	double sum;
	double max;
	double min;
	double average;
	//随机赋值
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		num[i]=rand();
	}
	//计算
	func(num,N,&sum,&max,&min,&average);
	//输出
	printf("原数组为：\n");
	for(i=0;i<N;i++)
	{
		printf("%6d",num[i]);
	}
	printf("\n");
	printf("总和为;%g\n",sum);
	printf("最大值为;%g\n",max);
	printf("最小值为;%g\n",min);
	printf("平均值为;%g\n",average);
	return 0;
}

void func(int num[],int n,double *sum,double *max,double *min,double *average)
{
	int i;
	*sum=0;
	*max=num[0];
	*min=num[0];
	*average=0;
	for(i=0;i<n;i++)
	{
		*sum+=num[i];
		if(num[i]>*max)
		{
			*max=num[i];
		}
		if(num[i]<*min)
		{
			*min=num[i];
		}
		*average=*sum/n;
	}


}