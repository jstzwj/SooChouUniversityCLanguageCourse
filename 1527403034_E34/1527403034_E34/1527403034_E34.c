/*文件名：1527403034_E034.c
*作者：王俊
*时间：2015年11月20日
*功能：打印8行杨辉三角形。
*备注：
*/
#include<stdio.h>
#define N 8
int main()
{
	int i,j;
	int arry[N][N]={0};
	//对杨辉三角形进行初始化
	for(i=0;i<N;i++)
	{
		arry[i][0]=1;
	}
	for(i=0;i<N;i++)
	{
		arry[i][i]=1;
	}
	//对除了两边外的数字进行计算
	for(i=1;i<N;i++)
	{
		for(j=1;j<i;j++)
		{
			arry[i][j]=arry[i-1][j]+arry[i-1][j-1];
		}
	}
	//输出
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(arry[i][j]!=0)
			{
				printf("%3d",arry[i][j]);
			}
			else
			{
				printf("\n");
				break;
			}
		}
	}
	printf("\n");
	return 0;
}