/*文件名：1527403034_E22.c
*作者：王俊
*时间：2015年11月3日
*功能：用迭代法求 x=√𝑎。求平方根的迭代公式为：𝑥𝑛+1=1/2(𝑥𝑛+𝑎/𝑥𝑛)要求前后两次出的x的差绝对值小于 10−5。
*备注：
*/
#include<stdio.h>
#include<math.h>
int main()
{

	double a=0,x=0,x2=0;
	int n=0;
	//输入
	printf("请输入一个数：\n");
	scanf("%lf",&a);
	x=a/2;
	//迭代计算平方根
	while(fabs(x-x2)>=10e-5)
	{
		x2=x;
		x=0.5*(x+a/x);
	}
	//输出平方根
	printf("平方根为%f\n",x);
	return 0;
}