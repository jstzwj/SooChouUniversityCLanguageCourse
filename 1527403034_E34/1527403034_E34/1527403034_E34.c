/*�ļ�����1527403034_E034.c
*���ߣ�����
*ʱ�䣺2015��11��20��
*���ܣ���ӡ8����������Ρ�
*��ע��
*/
#include<stdio.h>
#define N 8
int main()
{
	int i,j;
	int arry[N][N]={0};
	//����������ν��г�ʼ��
	for(i=0;i<N;i++)
	{
		arry[i][0]=1;
	}
	for(i=0;i<N;i++)
	{
		arry[i][i]=1;
	}
	//�Գ�������������ֽ��м���
	for(i=1;i<N;i++)
	{
		for(j=1;j<i;j++)
		{
			arry[i][j]=arry[i-1][j]+arry[i-1][j-1];
		}
	}
	//���
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