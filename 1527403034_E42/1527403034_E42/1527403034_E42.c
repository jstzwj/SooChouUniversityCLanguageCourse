/*�ļ�����1527403034_E42.c
*���ߣ�����
*ʱ�䣺2015��11��25��
*���ܣ��Ӽ��������Ӣ�ľ��ӡ��Կո񡢶��š���š��ֺ�Ϊ�ָ���������������еĵ��ʸ��������ʾ����Ļ�ϡ�ÿ������ռһ�С�
*��ע��
*/
#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char str[N];
	int len;
	char phrase[N][N]={0};
	int phrase_flag=-1;
	int i=0,j=0;
	int flag=0;
	//����
	printf("������һ���ַ���\n");
	gets(str);
	len=strlen(str);
	//��ȡ
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]==',')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]=='.')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]==';')
		{
			flag=0;
			j=0;
			continue;
		}
		else
		{
			if(flag==0)
			{
				phrase_flag++;
			}
			flag=1;
			phrase[phrase_flag][j]=str[i];
			j++;
		}
	}
	//���
	printf("���ʷָ���Ϊ��\n");
	for(i=0;i<=phrase_flag;i++)
	{
		puts(phrase[i]);
	}
	return 0;
}