/*文件名：1527403034_E38.c
*作者：王俊
*时间：2015年11月23日
*功能：利用随机数初始一个 N*N 的 二维数组，请对每一行元素根据的数位按照从小到大排序。例如：假设二维数组第一行元素为： [23456,34,5,2,45 ]，则排序后的结果为[2, 45,345,23456]
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 11
int main()
{
	int arry[N][N];
	int num[N][N];
	int temp;
	int i,j,m,n;
	//随机初始化
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			arry[i][j]=rand();
		}
	}
	//输出原数组
	printf("原数组为:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%7d",arry[i][j]);
		}
		printf("\n");
	}
	//计算位数
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			temp=arry[i][j];
			m=0;
			while(temp>0)
			{
				temp/=10;
				m++;
			}
			num[i][j]=m;
		}
	}
	//冒泡排序
	for(i=0;i<N;i++)
	{
		for(m=N-1;m>=0;m--)
		{
			for(j=0;j<m;j++)
			{
				if(num[i][j]>num[i][j+1])
				{
					temp=num[i][j];
					num[i][j]=num[i][j+1];
					num[i][j+1]=temp;

					temp=arry[i][j];
					arry[i][j]=arry[i][j+1];
					arry[i][j+1]=temp;
				}
			}
		}
	}
	//输出排序后数组
	printf("排序后数组为：\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%7d",arry[i][j]);
		}
		printf("\n");
	}
	return 0;
}