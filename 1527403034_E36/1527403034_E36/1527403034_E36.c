/*�ļ�����1527403034_E36.c
*���ߣ�����
*ʱ�䣺2015��11��26��
*���ܣ���ӡn��ħ����nΪ��������ħ�����ÿһ�С�ÿһ�С��Խ��ߵ�Ԫ�ض���ȡ�
*��ע��
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
	//�ضԽ������η��룬�����Ѿ������ĸ�������
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
	//���
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