/*文件名：1527403034_E44.c
*作者：王俊
*时间：2015年11月26日
*功能：写两个函数，分别求两个整数的最大公约和最小公倍数，用主函数调这两个函数，并输出结果。两个整数由键盘输入。
*备注：
*/
#include<stdio.h>
/*
	功能：求最大公约数
	参数：int num1	
			int num2
	返回值：最大公约数
*/
int common_divisor(int num1,int num2);
/*
	功能：求最小公倍数
	参数：int num1	
			int num2
	返回值：最小公倍数
*/
int common_multiple(int num1,int num2);
int main()
{
	int a,b;
	//输入
	printf("请输入两个整数：\n");
	scanf("%d%d",&a,&b);
	//计算
	printf("最大公约数为%d\n",common_divisor(a,b));
	printf("最小公倍数为%d\n",common_multiple(a,b));
	return 0;
}

int common_divisor(int num1,int num2)
{
	int temp;
	//保证num1>num2
	if(num1<num2)
	{
		temp=num1;
		num1=num2;
		num2=temp;
	}
	//辗转相除
	do
	{
		temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	while(temp!=0);
	return num1;
}

int common_multiple(int num1,int num2)
{
	int result=num1*num2/common_divisor(num1,num2);
	return result;
}