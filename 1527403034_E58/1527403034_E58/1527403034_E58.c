/*�ļ�����1527403034_E58.c
*���ߣ�����
*ʱ�䣺2015��12��10��
*���ܣ����������������Լ������С������
*��ע��
*/
#include<stdio.h>
/*
	����:���������������Լ������С������
	������int num1;
		int num2;
		int *divisor	���Լ��
		int *multiple	��С������
	����ֵ����
*/
void DivisorAndMultiple(int num1,int num2,int *divisor,int *multiple);
int main()
{
	int a,b;
	int divisor,multiple;
	//����
	printf("����������������\n");
	scanf("%d%d",&a,&b);
	//����
	DivisorAndMultiple(a,b,&divisor,&multiple);
	//���
	printf("���Լ��Ϊ��%d����С������Ϊ��%d\n",divisor,multiple);
	return 0;
}

void DivisorAndMultiple(int num1,int num2,int *divisor,int *multiple)
{
	int temp;
	if(num1<num2)
	{
		temp=num1;
		num1=num2;
		num2=temp;
	}
	//�ݴ�˻�
	*multiple=num1*num2;
	while(num2>0)
	{
		temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	*divisor=num1;
	*multiple=*multiple/num1;
}