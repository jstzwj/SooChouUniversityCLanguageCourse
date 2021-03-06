/*文件名：1527403034_E37.c
*作者：王俊
*时间：2015年11月22日
*功能：利用随机初始化一个N*N的二维矩阵，请编写程序找出该二维矩阵中的所有鞍点，并输其值和在行号列号。是指元素是其所在行的最大值，所在列的最小值。 注意：一个二维矩阵可能有多个鞍点，也可能没有鞍点。 （N为预先设定好的一个正整数）
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 11
int main()
{
	int matrix[N][N]={0};
	int i,j,m,n;
	int judge=0,judge1=0,judge2=0;
	//初始化
	for(i=0;i<N;i++)
	{
		matrix[1][i]=-1;
	}
	for(i=0;i<N;i++)
	{
		matrix[3][i]=-1;
	}
	for(i=0;i<N;i++)
	{
		matrix[i][1]=2;
	}
	for(i=0;i<N;i++)
	{
		matrix[i][3]=2;
	}
	matrix[1][1]=0;
	matrix[1][3]=0;
	matrix[3][1]=0;
	matrix[3][3]=0;
	//输出矩阵
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%5d",matrix[i][j]);
		}
		printf("\n");
	}
	//寻找鞍点
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			//判断是否为一行最大值
			for(m=0;m<N;m++)
			{
				if(matrix[i][j]<matrix[i][m])
				{
					break;
				}

			}
			if(m==N)
			{
				judge1=1;
			}
			//判断是否为一列最小值
			for(n=0;n<N;n++)
			{
				if(matrix[i][j]>matrix[n][j])
				{
					break;
				}
			}
			if(n==N)
			{
				judge2=1;
			}
			//判断是否为鞍点
			if((judge1==1)&&(judge2==1))
			{
				printf("鞍点值为%d,行号与列号为%d,%d\n",matrix[i][j],i,j);
				judge=1;
			}
			judge1=0;
			judge2=0;
		}
	}
	//不存在鞍点的输出
	if(judge==0)
	{
		printf("此矩阵不存在鞍点\n");
	}
	return 0;
}