/*�ļ�����1527403034_E40.c
*���ߣ�����
*ʱ�䣺2015��11��23��
*���ܣ���ʹ���ַ������������ж�s1���Ƿ�������ַ���s2
*��ע��
*/
#include<stdio.h>
#define N 100
int main()
{
	char s1[N];
	char s2[N];
	int i,j;
	int exist=0;
	//�����ַ���
	printf("������һ���ַ�����\n");
	gets(s1);
	printf("������һ�������ҵ����ַ�����\n");
	gets(s2);
	//�ж��Ƿ����
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]==s2[0])
		{
			j=i;
			while(1)
			{

				if(s2[j-i]=='\0')
				{
					exist=1;
					break;
				}
				else if(s1[j]=='\0')
				{
					break;
				}
				else if(s1[j]!=s2[j-i])
				{
					break;
				}
				
				j++;
			}
		}
	}
	if(exist==1)
	{
		printf("���ڸ����ַ���\n");
	}
	else
	{
		printf("�����ڸ����ַ���\n");
	}
	return 0;
}