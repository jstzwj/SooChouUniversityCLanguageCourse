/*�ļ�����1527403034_E51.c
*���ߣ�����
*ʱ�䣺2015��12��8��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
/*
	���ܣ��������Խ���Ԫ�صĺ�
	������int matrix[][N];������ľ���
		int m;�������
	����ֵ�����Խ���Ԫ�صĺ�
*/
int LeadingDiagonal(int matrix[][N],int m);
/*
	���ܣ��Ծ���ÿһ�н�������
	������int matrix[][N];������ľ���
		int m;�������
	����ֵ����
*/
void RowSort(int matrix[][N],int m);
/*
	���ܣ����ÿһ��Ԫ�أ�ÿ��Ԫ��ռ6�У��Ҷ���
	������int matrix[][N];������ľ���
		int m;�������
	����ֵ����
*/
void PrintMatrix(int matrix[][N],int m);

int main()
{
	int i,j;
	int matrix[N][N];
	//�����ʼ����ά����
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			matrix[i][j]=rand();
		}
	}
	//�������
	printf("ԭ����Ϊ��\n");
	PrintMatrix(matrix,N);
	//�������Խ��ߵĺ�
	//������Խ��ߵĺ�
	printf("���Խ��ߵĺ�Ϊ%d\n",LeadingDiagonal(matrix,N));
	//��ÿһ������
	RowSort(matrix,N);
	//�������
	printf("��������Ϊ��\n");
	PrintMatrix(matrix,N);
	return 0;
}

int LeadingDiagonal(int matrix[][N],int m)
{
	int i=0;
	int sum=0;
	//�������Խ��ߵĺ�
	for(i=0;i<m;i++)
	{
		sum+=matrix[i][i];
	}
	//���غ�
	return sum;
}

void RowSort(int matrix[][N],int m)
{
	int k=0;
	int i,j;
	int temp;
	//ð������
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