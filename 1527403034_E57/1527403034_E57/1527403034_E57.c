/*�ļ�����1527403034_E57.c
*���ߣ�����
*ʱ�䣺2015��12��10��
*���ܣ��õݹ��������λ��
*��ע��
*/
#include<stdio.h>
/*
	���ܣ���������λ��
	������int num	����
	����ֵ��int λ��
*/
int CountDigit(int num);
int main()
{
	int num;
	//����
	printf("������һ������\n");
	scanf("%d",&num);
	//���㲢���
	printf("λ��Ϊ%d\n",CountDigit(num));
	return 0;
}

int CountDigit(int num)
{
	if(num>=-9&&num<=9)
	{
		return 1;
	}
	else
	{
		return CountDigit(num/10)+1;
	}
}