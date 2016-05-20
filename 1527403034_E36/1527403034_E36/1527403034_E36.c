/*文件名：1527403034_E36.c
*作者：王俊
*时间：2015年11月26日
*功能：打印n阶魔方阵（n为奇数）。魔方阵的每一行、每一列、对角线的元素都相等。
*备注：
*/
#include<stdio.h>
#define N 5
int main()
{
	int arry[N][N]={0};
	int i,j;
	int num;

	i=0;
	j=(N-1)/2;
	arry[i][j]=1;
	//沿对角线依次放入，遇到已经填满的格子跳过
	for(num=2;num<=N*N;num++)
	{
		i--;
		j++;
		if(i<0&&j==N)
		{
			i+=2;
			j--;
		}
		else
		{
			if(i<0)
			{
				i=N-1;
			}
			if(j>=N)
			{
				j=0;
			}
		}

		if(arry[i][j]==0)
		{
			arry[i][j]=num;
		}
		else
		{
			i=i+2;
			j=j-1;
			arry[i][j]=num;
		}
	}
	//输出
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%4d",arry[i][j]);
		}
		printf("\n");
	}
	return 0;
}