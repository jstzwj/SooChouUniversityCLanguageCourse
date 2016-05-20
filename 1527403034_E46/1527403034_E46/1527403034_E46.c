/*文件名：1527403034_E46.c
*作者：王俊
*时间：2015年12月3日
*功能：编写一个函数,计算一个整数的所有因子之和，并编写测试程序，并在测试程序中输入整数和输出所有因子之和。例如：输入8，调用该函数之后,得到结果为7。
*备注：
*/
#include<stdio.h>
/*
功能:计算一个整数的所有因子之和
参数:int num	待求因子的整数
返回值:int	所有因子的和
*/
int DivisorSum(int num);
int main()
{
	int num;
	//输入
	printf("请输入一个整数\n");
	scanf("%d",&num);
	//计算所有因子的和并输出
	printf("所有因子的和为%d\n",DivisorSum(num));
	return 0;
}
int DivisorSum(int num)
{
	int i;
	int sum=0;

	for(i=1;i<num;i++)
	{
		if(num%i==0)
		{
			sum+=i;//因子求和
		}
	}
	return sum;
}