/*�ļ�����1527403034_E44.c
*���ߣ�����
*ʱ�䣺2015��11��26��
*���ܣ�д�����������ֱ����������������Լ����С�������������������������������������������������ɼ������롣
*��ע��
*/
#include<stdio.h>
/*
	���ܣ������Լ��
	������int num1	
			int num2
	����ֵ�����Լ��
*/
int common_divisor(int num1,int num2);
/*
	���ܣ�����С������
	������int num1	
			int num2
	����ֵ����С������
*/
int common_multiple(int num1,int num2);
int main()
{
	int a,b;
	//����
	printf("����������������\n");
	scanf("%d%d",&a,&b);
	//����
	printf("���Լ��Ϊ%d\n",common_divisor(a,b));
	printf("��С������Ϊ%d\n",common_multiple(a,b));
	return 0;
}

int common_divisor(int num1,int num2)
{
	int temp;
	//��֤num1>num2
	if(num1<num2)
	{
		temp=num1;
		num1=num2;
		num2=temp;
	}
	//շת���
	do
	{
		temp=num1%num2;
		num1=num2;
		num2=temp;
	}
	while(temp!=0);
	return num1;
}

int common_multiple(int num1,int num2)
{
	int result=num1*num2/common_divisor(num1,num2);
	return result;
}