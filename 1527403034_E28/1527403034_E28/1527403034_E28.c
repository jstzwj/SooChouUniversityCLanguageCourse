/*�ļ�����1527403034_E28.c
*���ߣ�����
*ʱ�䣺2015��11��13��
*���ܣ���ѡ�񷨶�10�������������ǰ�������������������ʼ���顣
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main()
{
	int a[N];
	int i,j,k,temp;
	int min;

	//�����ʼ������
	srand((unsigned int)time(NULL));
	for(i=0;i<N;i++)
	{
		a[i]=rand();
	}
	//�������ǰ���
	for(i=0;i<N;i++)
	{
		printf("%10d",a[i]);
	}
	printf("\n");
	//ѡ������
	for(j=0;j<N-1;j++)
	{
		min=j;
		for(i=j;i<N;i++)
		{
			if(a[i]<a[min])
			{
				min=i;
			}
		}
		temp=a[min];
		for(k=min;k>j;k--)
		{
			a[k]=a[k-1];
		}

		a[j]=temp;
	}
	//������������
	for(i=0;i<N;i++)
	{
		printf("%10d",a[i]);
	}
	printf("\n");
	return 0;
}