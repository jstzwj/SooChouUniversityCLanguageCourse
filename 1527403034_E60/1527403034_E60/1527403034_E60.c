/*�ļ�����1527403034_E60.c
*���ߣ�����
*ʱ�䣺2015��12��14��
*���ܣ�������ʮ����ת������
*��ע��
*/
#include "stdio.h"
/*
	���ܣ�������ʮ����ת������
	������int num		ʮ������
			char str[]		��������
	����ֵ����
*/

void ToBinary(int num,char str[]);
int main()
{
	int num;
	char str[sizeof(int)*8];
	//����
	printf("������һ������\n");
	scanf("%d",&num);
	//ת��
	ToBinary(num,str);
	//���
	printf("ת��Ϊ������Ϊ��%s\n",str);
	return 0;
}
void ToBinary(int num,char str[])
{
	int i=0;
	int temp=num;
	int len=0;
	while(temp>0)
	{
		temp/=2;
		len++;
	}
	while(num>0)
	{
		if(num%2==1)
		{
			str[len-i-1]='1';
			num=(num-1)/2;
		}
		else
		{
			str[len-i-1]='0';
			num/=2;
		}
		i++;
	}
	str[len]=0;
}
