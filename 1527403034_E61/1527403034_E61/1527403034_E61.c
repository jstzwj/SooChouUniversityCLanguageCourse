/*�ļ�����1527403034_E61.c
*���ߣ�����
*ʱ�䣺2015��12��17��
*���ܣ�������һ������Ԫ�ص���������
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#define N 30
/*
	���ܣ�������Ԫ�������������
	������int * p:��������
		  int n:������ЧԪ�صĸ���
	����ֵ����
*/
void sort(int * p,int n);

int main()
{
	int *num;
	int n=10;
	int i;
	//����
	printf("����������Ԫ�ظ�����\n");
	scanf("%d",&n);
	num=(int *)malloc(sizeof(int)*n);
	if(num==NULL)
	{
		printf("�ڴ����ʧ��\n");
		return 1;
	}
	printf("�����������Ԫ�أ�\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	//����
	sort(num,n);
	//���
	printf("������Ϊ��\n");
	for(i=0;i<n;i++)
	{
	printf("%5d",num[i]);
	}
	printf("\n");
	free(num);
	return 0;
}
//ѡ������(��С����)
void sort(int * p,int n)
{
	int i,j;
	int temp;
	int min;

	for(i=0;i<n-1;i++)
	{
		min=n-1;
		for(j=i;j<n;j++)
		{
			if(p[min]>p[j])
			{
				min=j;
			}
		}
		temp=p[min];
		p[min]=p[i];
		p[i]=temp;
	}
}