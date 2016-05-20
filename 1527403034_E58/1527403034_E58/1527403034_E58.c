/*文件名：1527403034_E58.c
*作者：王俊
*时间：2015年12月10日
*功能：计算两个数的最大公约数与最小公倍数
*备注：
*/
#include<stdio.h>
/*
	功能:计算两个数的最大公约数与最小公倍数
	参数：int num1;
		int num2;
		int *divisor	最大公约数
		int *multiple	最小公倍数
	返回值：无
*/
void DivisorAndMultiple(int num1,int num2,int *divisor,int *multiple);
int main()
{
	int a,b;
	int divisor,multiple;
	//输入
	printf("请输入两个整数：\n");
	scanf("%d%d",&a,&b);
	//计算
	DivisorAndMultiple(a,b,&divisor,&multiple);
	//输出
	printf("最大公约数为：%d，最小公倍数为：%d\n",divisor,multiple);
	return 0;
}

void DivisorAndMultiple(int num1,int num2,int *divisor,int *multiple)
{
	int temp;
	if(num1<num2)
	{
		temp=num1;
		num1=num2;
		num2=temp;
	}
	//暂存乘积
	*multiple=num1*num2;
	while(num2>0)
	{
		temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	*divisor=num1;
	*multiple=*multiple/num1;
}