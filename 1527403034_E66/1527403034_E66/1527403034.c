/*�ļ�����1527403034_E66.c
*���ߣ�����
*ʱ�䣺2015��12��23��
*���ܣ�
*��ע��
*/
#include<stdio.h>
/*
���ܣ��ж��ַ����Ƿ����
������char str[]		��������ַ���
����ֵ���Ƿ����
*/
int judge(char str[]);
int main()
{
	char str[50];
	//����
	printf("������һ���ַ�����\n");
	gets(str);
	if (judge(str))
	{
		printf("�ǻ����ַ���\n");
	}
	else
	{
		printf("���ǻ����ַ���\n");
	}
	return 0;
}

int judge(char str[])
{
	char *start, *end;
	int len;

	start = str;
	for (end = str; *end != 0;end ++)
	{
	}
	end--;
	while (start<end)
	{
		if (*start != *end)
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}