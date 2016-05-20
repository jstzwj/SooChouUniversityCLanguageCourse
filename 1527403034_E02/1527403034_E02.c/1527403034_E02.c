/*文件名：1527403034_E02.c
*作者：王俊
*日期：2015年10月16日
*功能：计算用户输入的 3 个整数的平均值、和、最大值和最小值，并输出到屏幕上
*备注：
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,sum,max,min;
	float average;
	//输入三个整数
	printf("请输入3个整数：\n");
	scanf("%d%d%d",&a,&b,&c);
	//计算平均值
	average=(a+b+c)/3.0;
	//计算最大值
	if(a>b)
	{
		if(a>c)
		{
			max=a;
		}
		else
		{
			max=c;
		}
	}
	else 
	{
		if(b>c)
		{
			max=b;
		}
		else
			{
				max=c;
		}
	}
	//计算最小值
	if(a>b)
	{
		if(b>c)
			{
			min=c;
		}
		else {
			min=b;
		}
	}
	else
	{
		if(a>c)
			{
				min=c;
		}
		else 
			{
				min=a;
		}
	}
	//计算和
	sum=a+b+c;
	printf("平均值：%-8.4f\n最大值：%6d\n最小值：%6d\n和：%6d\n",average,max,min,sum);
return 0;
}
