/*文件名：1527403034_E35.c
*作者：王俊
*时间：2015年11月20日
*功能：利用随机初始化一个N*N的矩阵，并计算正、负对角线元素的和。
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main()
{
	int j,k;
	int matrix[N][N];
	int p_sum=0,n_sum=0;
	//随机初始化
	srand((unsigned int)time(NULL));
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++)
		{
			matrix[j][k]=rand()%10000;
		}
	}
	//计算正负对角线元素的和
	for(j=0;j<N;j++)
	{
		p_sum+=matrix[j][j];
		n_sum+=matrix[j][N-j];
	}
	//输出
	printf("矩阵为：\n");
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++)
		{
			printf("%5d",matrix[j][k]);
		}
		printf("\n");
	}
	printf("正对角线的和为%d\n",p_sum);
	printf("负对角线的和为%d\n",n_sum);
	return 0;
}