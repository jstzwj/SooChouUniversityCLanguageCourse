/*�ļ�����1527403034_E64.c
*���ߣ�����
*ʱ�䣺2015��12��21��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#define N 10
/*
	���ܣ��������������
	������int arry[]		����
		int len		����
	����ֵ����
*/
void sort(int arry[],int len);
/*
	���ܣ��ҳ���������
	������int arry[]		����
		int len		����
		int prime[]   ��������
	����ֵ��int prime����ĳ���
*/
int FindPrime(int arry[],int len,int prime[]);
/*
	���ܣ����
	������int arry[]		����
		int len		����
		int m		ÿ�и���
		int n		ռ������
	����ֵ����
*/
void PrintArry(int arry[],int len,int m,int n);
int main()
{
	int arry[N];
	int prime[N];
	int prime_len;
	int i;
	//�������ʼ������
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		arry[i]=rand()%10000;
	}
	//���ԭʼ����
	printf("ԭ����Ϊ��\n");
	PrintArry(arry,N,7,8);
	printf("\n");
	//����
	sort(arry,N);
	//������������
	printf("���������Ϊ��\n");
	PrintArry(arry, N, 5, 12);
	printf("\n");
	//�ҳ����е�����
	prime_len=FindPrime(arry,N,prime);
	//�����������
	printf("��������Ϊ��\n");
	PrintArry(prime, prime_len, 5, 12);
	printf("\n");
	return 0;
}

void sort(int arry[],int len)
{
	//��������
	int i,j;
	int temp;
	for(i=1;i<len;i++)
	{
		for (j=i;j>0;j--)
		{
			if(arry[j]<arry[j-1])
			{
				temp=arry[j];
				arry[j]=arry[j-1];
				arry[j-1]=temp;
			}
			else
			{
				break;
			}
		}
	}

}

int FindPrime(int arry[],int len,int prime[])
{
	int prime_len=0;
	int i,j;
	int sq;
	for(i=0;i<len;i++)
	{
		sq=(int)sqrt((float)arry[i]);
		for(j=2;j<=sq;j++)
		{
			if(arry[i]%j==0)
			{
				break;
			}
		}
		if(j==sq+1)
		{
			prime[prime_len]=arry[i];
			prime_len++;
		}
	}
	return prime_len;
}

void PrintArry(int arry[],int len,int m,int n)
{
	int i;
	char str[10];
	sprintf(str,"%c%d%c\0",'%',n,'d');
	//strcat(str,"d");
	for (i = 0; i < len; i++)
	{
		printf(str, arry[i]);
		if ((i + 1) % m == 0)
		{
			printf("\n");
		}
	}

}