/*文件名：1527403034_E45.c
*作者：王俊
*时间：2015年12月2日
*功能：求1000以内的所有质数，每行8个输出到屏幕上（不要用筛法）。 写一个判断整数是否是素数的函数。
*备注：
*/
#include<stdio.h>
#include<math.h>
#define N 1000
/*
	功能：输出2到某个数之间的所有素数，每行8个
	参数：int limit 上界
	返回值：0	正常输出
			1	limit范围不正确
*/
int PrintPrimeNumber(int limit);
int main()
{
	PrintPrimeNumber(N);
	return 0;
}

int PrintPrimeNumber(int limit)
{
	int i,j;
	int count=0;
	if(limit>0)
	{
		//判断是否为素数
		for(i=2;i<=limit;i++)
		{
			for(j=2;j<i;j++)
			{
				if((i%j)==0)
				{
					break;
				}
			}
			if(j==i)
			{
				count++;
				printf("%5d",i);
				if(count%8==0)
				{
					printf("\n");
				}
				
			}

		}
		return 0;
	}
	else
	{
		return 1;
	}
}