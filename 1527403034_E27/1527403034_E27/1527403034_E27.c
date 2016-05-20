/*文件名：1527403034_E27.c
*作者：王俊
*时间：2015年11月13日
*功能：用筛法求100之内的质数，并打印输出所有的质数每5个一行。
*备注：
*/
#include<stdio.h>
int main()
{
	int judge[101];
	int i=0,j=0;
	//初始化
	for(i=0;i<=100;i++)
	{
		judge[i]=1;
	}
	//进行素数判断
	judge[0]=judge[1]=0;
	judge[2]=1;
	for(i=3;i<=100;i++)
	{
		for(j=2;j<i;j++)
		{
			if((i%j)==0)
			{
				judge[i]=0;
				break;
			}
		}

	}

	//输出
	j=0;
	for(i=0;i<=100;i++)
	{
		if(judge[i]==1)
		{
			printf("%6d",i);
			if((j+1)%5==0)
			{
				printf("\n");
			}
			j++;
		}
		
	}

	return 0;
}