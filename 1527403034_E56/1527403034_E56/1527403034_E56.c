/*�ļ�����1527403034_E56.c
*���ߣ�����
*ʱ�䣺2015��12��10��
*���ܣ���ʮ����������ת��Ϊ������
*��ע��
*/
#include<stdio.h>
/*
	���ã���ʮ����ת��Ϊ������
	������int num	��ת��������
		int result[] ��������ƽ��������
	����ֵ����
*/
int ToBinary(int num,char result[]);
int main()
{
	int i;
	int len;
	int num;
	char result[sizeof(int)*8];
	//����
	printf("������һ��������\n");
	scanf("%d",&num);
	//ת��Ϊ������
	len=ToBinary(num,result);
	//������
	printf("ת��Ϊ�����ƵĽ��Ϊ��\n");
	puts(result);
	return 0;
}


int ToBinary(int num,char result[])
{
	int i;
	int len=0,temp;
	i=0;
	temp=num;
	//��������ƽ���ĳ���
	while(temp>0)
	{
		temp/=2;
		len++;
	}
	//ת��Ϊ������
	while(num>0)
	{
		if(num%2==1)
		{
			result[len-i-1]='1';
		}
		else
		{
			result[len-i-1]='0';
		}
		num/=2;
		i++;
	}
	//�����ַ����������
	result[len]=0;
	return 0;
}