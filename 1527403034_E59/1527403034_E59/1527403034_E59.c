/*�ļ�����1527403034_E59.c
*���ߣ�����
*ʱ�䣺2015��12��14��
*���ܣ���Ԫ���ܺ͡����ֵ����Сֵ��ƽ��ֵ
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
/*
	���ܣ���Ԫ���ܺ͡����ֵ����Сֵ��ƽ��ֵ
	������int num[]		�����������
	int n		������ЧԪ�ظ���
	double *sum		�ܺ�
	double *max		���ֵ
	double *min		��Сֵ
	double *average		ƽ��ֵ
	����ֵ����
*/
void func(int num[],int n,double *sum,double *max,double *min,double *average);
int main()
{
	int num[N];
	int i;
	double sum;
	double max;
	double min;
	double average;
	//�����ֵ
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		num[i]=rand();
	}
	//����
	func(num,N,&sum,&max,&min,&average);
	//���
	printf("ԭ����Ϊ��\n");
	for(i=0;i<N;i++)
	{
		printf("%6d",num[i]);
	}
	printf("\n");
	printf("�ܺ�Ϊ;%g\n",sum);
	printf("���ֵΪ;%g\n",max);
	printf("��СֵΪ;%g\n",min);
	printf("ƽ��ֵΪ;%g\n",average);
	return 0;
}

void func(int num[],int n,double *sum,double *max,double *min,double *average)
{
	int i;
	*sum=0;
	*max=num[0];
	*min=num[0];
	*average=0;
	for(i=0;i<n;i++)
	{
		*sum+=num[i];
		if(num[i]>*max)
		{
			*max=num[i];
		}
		if(num[i]<*min)
		{
			*min=num[i];
		}
		*average=*sum/n;
	}


}