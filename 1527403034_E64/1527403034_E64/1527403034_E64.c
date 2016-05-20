/*文件名：1527403034_E64.c
*作者：王俊
*时间：2015年12月21日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define N 10
/*
	功能：对数组进行排序
	参数：int arry[]		数组
		int len		长度
	返回值：无
*/
void sort(int arry[],int len);
/*
	功能：找出所有素数
	参数：int arry[]		数组
		int len		长度
		int prime[]   保存素数
	返回值：int prime数组的长度
*/
int FindPrime(int arry[],int len,int prime[]);
/*
	功能：输出
	参数：int arry[]		数组
		int len		长度
		int m		每行个数
		int n		占的列数
	返回值：无
*/
void PrintArry(int arry[],int len,int m,int n);
int main()
{
	int arry[N];
	int prime[N];
	int prime_len;
	int i;
	//随机数初始化数组
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		arry[i]=rand()%10000;
	}
	//输出原始数组
	printf("原数组为：\n");
	PrintArry(arry,N,7,8);
	printf("\n");
	//排序
	sort(arry,N);
	//输出排序后数组
	printf("排序后数组为：\n");
	PrintArry(arry, N, 5, 12);
	printf("\n");
	//找出所有的质数
	prime_len=FindPrime(arry,N,prime);
	//输出所有质数
	printf("所有质数为：\n");
	PrintArry(prime, prime_len, 5, 12);
	printf("\n");
	return 0;
}

void sort(int arry[],int len)
{
	//插入排序
	int i,j;
	int temp;
	for(i=1;i<len;i++)
	{
		for (j=i;j>0;j--)
		{
			if(arry[j]<arry[j-1])
			{
				temp=arry[j];
				arry[j]=arry[j-1];
				arry[j-1]=temp;
			}
			else
			{
				break;
			}
		}
	}

}

int FindPrime(int arry[],int len,int prime[])
{
	int prime_len=0;
	int i,j;
	int sq;
	for(i=0;i<len;i++)
	{
		sq=(int)sqrt((float)arry[i]);
		for(j=2;j<=sq;j++)
		{
			if(arry[i]%j==0)
			{
				break;
			}
		}
		if(j==sq+1)
		{
			prime[prime_len]=arry[i];
			prime_len++;
		}
	}
	return prime_len;
}

void PrintArry(int arry[],int len,int m,int n)
{
	int i;
	char str[10];
	sprintf(str,"%c%d%c\0",'%',n,'d');
	//strcat(str,"d");
	for (i = 0; i < len; i++)
	{
		printf(str, arry[i]);
		if ((i + 1) % m == 0)
		{
			printf("\n");
		}
	}

}