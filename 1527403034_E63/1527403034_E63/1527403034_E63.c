/*文件名：1527403034_E63.c
*作者：王俊
*时间：2015年12月17日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
/*
	功能：将数组前n个数后移动m位
	参数：int *num	数组
		int len		有效元素个数
		int n		前n个数
		int m		向后移动的位数
	返回值：0   未做移动
			1	已做移动
*/
int move(int *num, int len, int n, int m);
/*
功能：输出数组，指定每行输出的个数和列数
参数：int *num	数组
int len		有效元素个数
int n		每行个数
int m		列数
返回值：无
*/
void PrintArry(int *num, int len, int n, int m);
int main()
{
	int num[N];
	int len=10;
	int i;
	int m;
	//随机赋值
	srand((unsigned)time(NULL));
	for(i=0;i<len;i++)
	{
		num[i]=rand()%1000;
	}
	//输出原数组
	printf("原数组为：\n");
	PrintArry(num, len, 6, 10);
	printf("\n");
	//向后移动
	printf("请输入向后移动的位数：\n");
	scanf("%d",&m);
	move(num,len,0,m);
	//输出移动后的数组
	printf("移动后的数组为：\n");
	PrintArry(num, len, 5, 12);
	printf("\n");
	return 0;
}

int move(int *num, int len, int n, int m)
{
	int i, j;
	int *temp = malloc(sizeof(int)*len);
	if (temp == NULL)
	{
		printf("内存分配失败\n");
		return 0;
	}
	//复制数组
	for (i = 0; i < len; i++)
	{
		temp[i] = num[i];
	}
	//判断是否可以移动
	if (len - n<m)
	{
		printf("未做移动\n");
		return 0;
	}
	//移动
	for (i = 0; i<len; i++)
	{
		j = i + m;
		if (j >= len)
		{
			j -= len;
		}
		num[j] = temp[i];
	}
	free(temp);
}

void PrintArry(int *num, int len, int n, int m)
{
	int i;
	char str[10];
	sprintf(str, "%c%d%c\0", '%', n, 'd');
	//strcat(str,"d");
	for (i = 0; i < len; i++)
	{
		printf(str, num[i]);
		if ((i + 1) % m == 0)
		{
			printf("\n");
		}
	}
}