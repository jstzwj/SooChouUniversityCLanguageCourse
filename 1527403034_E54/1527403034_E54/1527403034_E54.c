/*�ļ�����1527403034_E54.c
*���ߣ�����
*ʱ�䣺2015��12��8��
*���ܣ����ɡ�0��-��9���ַ����ɵ��ַ���ת��Ϊ����
*��ע��
*/
#include<stdio.h>
/*
	���ܣ����ɡ�0��-��9���ַ����ɵ��ַ���ת��Ϊ����
	������char str[];	�ַ���
	����ֵ��int num;������-1Ϊ���Ϸ��ַ���
*/
int StrToNum(char str[]);
int main()
{
	char str[50];
	int temp;
	//����
	printf("������һ���ַ�����\n");
	gets(str);
	//ת�����
	temp=StrToNum(str);
	if(temp!=-1)
	{
		//���
		printf("ת����Ϊ%d\n",temp);
	}
	else
	{
		printf("�ַ������Ϸ�\n");
	}
	return 0;
}

int StrToNum(char str[])
{
	int num=0;
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			num=num*10+str[i]-'0';
		}
		else
		{
			return -1;
		}
	}
	return num;
}