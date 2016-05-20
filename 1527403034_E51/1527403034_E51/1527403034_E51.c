/*文件名：1527403034_E51.c
*作者：王俊
*时间：2015年12月8日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
/*
	功能：计算主对角线元素的和
	参数：int matrix[][N];待计算的矩阵
		int m;矩阵阶数
	返回值：主对角线元素的和
*/
int LeadingDiagonal(int matrix[][N],int m);
/*
	功能：对矩阵每一行进行排序
	参数：int matrix[][N];待计算的矩阵
		int m;矩阵阶数
	返回值：无
*/
void RowSort(int matrix[][N],int m);
/*
	功能：输出每一个元素，每个元素占6列，右对齐
	参数：int matrix[][N];待计算的矩阵
		int m;矩阵阶数
	返回值：无
*/
void PrintMatrix(int matrix[][N],int m);

int main()
{
	int i,j;
	int matrix[N][N];
	//随机初始化二维矩阵
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix[i][j]=rand();
		}
	}
	//输出矩阵
	printf("原矩阵为：\n");
	PrintMatrix(matrix,N);
	//计算主对角线的和
	//输出主对角线的和
	printf("主对角线的和为%d\n",LeadingDiagonal(matrix,N));
	//对每一行排序
	RowSort(matrix,N);
	//输出矩阵
	printf("排序后矩阵为：\n");
	PrintMatrix(matrix,N);
	return 0;
}

int LeadingDiagonal(int matrix[][N],int m)
{
	int i=0;
	int sum=0;
	//计算主对角线的和
	for(i=0;i<m;i++)
	{
		sum+=matrix[i][i];
	}
	//返回和
	return sum;
}

void RowSort(int matrix[][N],int m)
{
	int k=0;
	int i,j;
	int temp;
	//冒泡排序
	for(k=0;k<m;k++)
	{
		for(i=0;i<m;i++)
		{
			for(j=m-2;j>=i;j--)
			{
				if(matrix[k][j+1]<matrix[k][j])
				{
					temp=matrix[k][j];
					matrix[k][j]=matrix[k][j+1];
					matrix[k][j+1]=temp;
				}
			}
		}
	}
}

void PrintMatrix(int matrix[][N],int m)
{
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%6d",matrix[i][j]);
		}
		printf("\n");
	}
}