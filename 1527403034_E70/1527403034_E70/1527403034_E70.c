/*�ļ�����1527403034_E70.c
*���ߣ�����
*ʱ�䣺2015��12��24��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<string.h>
/*
���ܣ������ַ���
������char* s1		��������ַ���
	char* s2
����ֵ��int �Ƿ��д��ַ���
*/
int findchar(char * s1,char * s2);
int main()
{
	char str1[40];
	char str2[40];
	int temp;
	//����
	printf("�������һ���ַ�����\n");
	gets(str1);
	printf("������ڶ����ַ�����\n");
	gets(str2);
	//����
	temp = findchar(str1,str2);
	if ( temp!= -1)
	{
		printf("�ַ���1�����ַ���2����һ����ʼλ��Ϊ%d\n", temp);
	}
	else
	{
		printf("�ַ���1�������ַ���2\n");
	}
	return 0;
}

int findchar(char * s1,char * s2)
{
	int i,j;
	int len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0;i<len1;i++)
	{
		if(s1[i]==s2[0])
		{
			for(j=i;s1[j]!=0&&s2[j]!=0;j++)
			{
				if (s1[i + j] != s2[j])
				{
					return -1;
				}
			}
			if (j == len2)
			{
				break;
			}
		}
	}
	return i;
}