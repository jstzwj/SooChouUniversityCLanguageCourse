/*�ļ�����1527403034_E52.c
*���ߣ�����
*ʱ�䣺2015��12��8��
*���ܣ�����д��ĸת��ΪСд��ĸ����Сд��ĸת��Ϊ��д��ĸ
*��ע��
*/
#include<stdio.h>
/*
	���ܣ�����д��ĸת��ΪСд��ĸ����Сд��ĸת��Ϊ��д��ĸ
	������char str[];��ת���ĵ��ַ���
	����ֵ����
*/
void ExCapitalLowercase(char str[]);
int main()
{
	char str[20];
	//����
	printf("������һ���ַ���\n");
	gets(str);
	//���ת������ַ���
	ExCapitalLowercase(str);
	puts(str);
	return 0;
}
void ExCapitalLowercase(char str[])
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]=str[i]-'a'+'A';
		}
		else if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]=str[i]+'a'-'A';
		}
	}
}