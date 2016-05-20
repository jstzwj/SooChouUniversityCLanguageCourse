/*文件名：1527403034_E04.c
*作者：王俊
*时间：2015年10月16日
*功能：编写程序输出用户输入的一个 3 位正整数的 3 个数字的和
*备注：
*/
#include<stdio.h>
int main()
{
	int a,b,c;
	int number;
	int sum;
	//输入3位整数
	printf("请输入3位正整数：\n");
	scanf("%d",&number);
	a=number%10;
	b=(number/10)%10;
	c=number/100;
	sum=a+b+c;
	printf("三位数各位和为%d\n",sum);
	return 0;
}