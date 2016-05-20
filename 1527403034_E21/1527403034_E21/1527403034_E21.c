/*文件名：1527403034_E21.c
*作者：王俊
*时间：2015年10月31日
*功能：有一分数序列： 2/1 ，3/2 ，5/3 ，8/5 ，13/8 ，21/13...,求出这个数列的前20项之和。
*备注：
*/
#include<stdio.h>
int main()
{
	int a=2,b=1,i=0,m=0;
	double sum=0;
	//计算20项的和
	for(i=1;i<=20;i++)
	{
		sum+=(double)a/(double)b;
		m=a+b;
		b=a;
		a=m;
	}
	//输出和
	printf("这20项和为%f\n",sum);
	return 0;
}