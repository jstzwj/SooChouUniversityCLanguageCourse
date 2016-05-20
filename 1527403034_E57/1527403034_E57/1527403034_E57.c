/*文件名：1527403034_E57.c
*作者：王俊
*时间：2015年12月10日
*功能：用递归计算整数位数
*备注：
*/
#include<stdio.h>
/*
	功能：计算整数位数
	参数：int num	整数
	返回值：int 位数
*/
int CountDigit(int num);
int main()
{
	int num;
	//输入
	printf("请输入一个整数\n");
	scanf("%d",&num);
	//计算并输出
	printf("位数为%d\n",CountDigit(num));
	return 0;
}

int CountDigit(int num)
{
	if(num>=-9&&num<=9)
	{
		return 1;
	}
	else
	{
		return CountDigit(num/10)+1;
	}
}