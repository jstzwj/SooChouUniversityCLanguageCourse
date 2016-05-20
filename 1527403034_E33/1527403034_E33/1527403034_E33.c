/*文件名：1527403034_E33.c
*作者：王俊
*时间：2015年11月19日
*功能：已知int arry[]={98, 23, 56, 78, 34, 256, 12, 789}，请使用选择法对数组元素按照其的值之和从大到小排序。
*备注：
*/
#include<stdio.h>
int main()
{
	int arry[]={98,23,56,78,34,256,12,789};
	int value[8]={0};
	int len;
	int temp,temp2;
	int i,j,max;
	len=8;
	//计算各位数的和
	for(i=0;i<len;i++)
	{
		temp=arry[i];
		while(temp>0)
		{
			value[i]=value[i]*10+temp%10;
			temp/=10;
		}
	}
	//选择排序两个数组
	for(i=0;i<len-1;i++)
	{
		max=i;
		for(j=i;j<len;j++)
		{
			if(value[max]<value[j])
			{
				max=j;
			}
		}
		temp=value[max];
		temp2=arry[max];
		for(j=max;j>i;j--)
		{
			value[j]=value[j-1];
			arry[j]=arry[j-1];
		}
		value[i]=temp;
		arry[i]=temp2;
	}
	//输出
	for(i=0;i<len;i++)
	{
		printf("%5d",arry[i]);
	}
	printf("\n");
	return 0;
}