/*�ļ�����1527403034_E62.c
*���ߣ�����
*ʱ�䣺2015��12��17��
*���ܣ���61��Ļ������������в���һ������
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
/*
	���ܣ�����������Ԫ�������в���һ����
	������int * p:��������
		  int *n:������ЧԪ�صĸ���
		  int num:�������
	����ֵ����
*/
void insert(int * p,int *n,int num);
int main()
{
	int *num;
	int n=10;
	int i;
	int insert_num;
	//����
	printf("����������Ԫ�ظ�����\n");
	scanf("%d",&n);
	num=(int *)malloc(sizeof(int)*(n+1));		//�����һ��int
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
	/*-------------------------------------------------*/
	//����
	printf("������һ��Ҫ���������е���:\n");
	scanf("%d",&insert_num);
	//����
	insert(num,&n,insert_num);
	//���
	printf("�������ֺ���Ϊ��\n");
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

void insert(int * p,int *n,int num)
{
	int i=0;
	int j;
	while(p[i]<num)
	{
		i++;
	}
	j=i;
	for(i=*n;i>j;i--)
	{
		p[i]=p[i-1];
	}
	p[i]=num;
	(*n)++;
}