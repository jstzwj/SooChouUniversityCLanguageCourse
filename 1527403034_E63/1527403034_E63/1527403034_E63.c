/*�ļ�����1527403034_E63.c
*���ߣ�����
*ʱ�䣺2015��12��17��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
/*
	���ܣ�������ǰn�������ƶ�mλ
	������int *num	����
		int len		��ЧԪ�ظ���
		int n		ǰn����
		int m		����ƶ���λ��
	����ֵ��0   δ���ƶ�
			1	�����ƶ�
*/
int move(int *num, int len, int n, int m);
/*
���ܣ�������飬ָ��ÿ������ĸ���������
������int *num	����
int len		��ЧԪ�ظ���
int n		ÿ�и���
int m		����
����ֵ����
*/
void PrintArry(int *num, int len, int n, int m);
int main()
{
	int num[N];
	int len=10;
	int i;
	int m;
	//�����ֵ
	srand((unsigned)time(NULL));
	for(i=0;i<len;i++)
	{
		num[i]=rand()%1000;
	}
	//���ԭ����
	printf("ԭ����Ϊ��\n");
	PrintArry(num, len, 6, 10);
	printf("\n");
	//����ƶ�
	printf("����������ƶ���λ����\n");
	scanf("%d",&m);
	move(num,len,0,m);
	//����ƶ��������
	printf("�ƶ��������Ϊ��\n");
	PrintArry(num, len, 5, 12);
	printf("\n");
	return 0;
}

int move(int *num, int len, int n, int m)
{
	int i, j;
	int *temp = malloc(sizeof(int)*len);
	if (temp == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return 0;
	}
	//��������
	for (i = 0; i < len; i++)
	{
		temp[i] = num[i];
	}
	//�ж��Ƿ�����ƶ�
	if (len - n<m)
	{
		printf("δ���ƶ�\n");
		return 0;
	}
	//�ƶ�
	for (i = 0; i<len; i++)
	{
		j = i + m;
		if (j >= len)
		{
			j -= len;
		}
		num[j] = temp[i];
	}
	free(temp);
}

void PrintArry(int *num, int len, int n, int m)
{
	int i;
	char str[10];
	sprintf(str, "%c%d%c\0", '%', n, 'd');
	//strcat(str,"d");
	for (i = 0; i < len; i++)
	{
		printf(str, num[i]);
		if ((i + 1) % m == 0)
		{
			printf("\n");
		}
	}
}