/*�ļ�����1527403034_E38.c
*���ߣ�����
*ʱ�䣺2015��11��23��
*���ܣ������������ʼһ�� N*N �� ��ά���飬���ÿһ��Ԫ�ظ��ݵ���λ���մ�С�����������磺�����ά�����һ��Ԫ��Ϊ�� [23456,34,5,2,45 ]���������Ľ��Ϊ[2, 45,345,23456]
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 11
int main()
{
	int arry[N][N];
	int num[N][N];
	int temp;
	int i,j,m,n;
	//�����ʼ��
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			arry[i][j]=rand();
		}
	}
	//���ԭ����
	printf("ԭ����Ϊ:\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%7d",arry[i][j]);
		}
		printf("\n");
	}
	//����λ��
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			temp=arry[i][j];
			m=0;
			while(temp>0)
			{
				temp/=10;
				m++;
			}
			num[i][j]=m;
		}
	}
	//ð������
	for(i=0;i<N;i++)
	{
		for(m=N-1;m>=0;m--)
		{
			for(j=0;j<m;j++)
			{
				if(num[i][j]>num[i][j+1])
				{
					temp=num[i][j];
					num[i][j]=num[i][j+1];
					num[i][j+1]=temp;

					temp=arry[i][j];
					arry[i][j]=arry[i][j+1];
					arry[i][j+1]=temp;
				}
			}
		}
	}
	//������������
	printf("���������Ϊ��\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%7d",arry[i][j]);
		}
		printf("\n");
	}
	return 0;
}