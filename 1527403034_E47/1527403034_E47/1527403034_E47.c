/*文件名：1527403034_E47.c
*作者：王俊
*时间：2015年12月3日
*功能：编写一个函数,将整数的各位数字对调，并编写测试程序,在测试函数中输入整数和输出新的整数.例如：输入123，调用该函数之后得到结果为321
*备注：
*/
#include<stdio.h>
/*
	功能:逆序整数
	参数:int num	待逆序的整数
	返回值:int	逆序后的整数
*/

int InvertSequence(int num);

int main()
{
	int num;
	//输入
	printf("请输入一个整数\n");
	scanf("%d",&num);
	//计算所逆序后的数并输出
	printf("逆序的结果为%d\n",InvertSequence(num));
	return 0;
}

int InvertSequence(int num)
{
	int result=0;
	//逆序
	while(num>0)
	{
		result=result*10+num%10;
		num/=10;
	}
	return result;
}