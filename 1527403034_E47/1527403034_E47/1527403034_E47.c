/*�ļ�����1527403034_E47.c
*���ߣ�����
*ʱ�䣺2015��12��3��
*���ܣ���дһ������,�������ĸ�λ���ֶԵ�������д���Գ���,�ڲ��Ժ�������������������µ�����.���磺����123�����øú���֮��õ����Ϊ321
*��ע��
*/
#include<stdio.h>
/*
	����:��������
	����:int num	�����������
	����ֵ:int	����������
*/

int InvertSequence(int num);

int main()
{
	int num;
	//����
	printf("������һ������\n");
	scanf("%d",&num);
	//�������������������
	printf("����Ľ��Ϊ%d\n",InvertSequence(num));
	return 0;
}

int InvertSequence(int num)
{
	int result=0;
	//����
	while(num>0)
	{
		result=result*10+num%10;
		num/=10;
	}
	return result;
}