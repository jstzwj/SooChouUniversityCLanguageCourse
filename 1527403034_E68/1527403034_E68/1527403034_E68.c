/*�ļ�����1527403034_E68.c
*���ߣ�����
*ʱ�䣺2015��12��24��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<string.h>
/*
���ܣ������ַ���s��k��ʼn���ַ�����һ���ַ�����
������char* a		��������ַ���
	char* b		��������ַ���
	int k		
	int n
����ֵ��int ��Ϊ0������ʧ��
*/
int copychar(char *a,char* b,int k,int n);
int main()
{
	char str[40];
	char str_cpy[40];
	int k,n;
	//����
	printf("������һ���ַ�����\n");
	gets(str);
	printf("������Ҫ�ںδ���ʼ����(1~len):\n");
	scanf("%d",&k);
	printf("������Ҫ���ƶ����ַ�:\n");
	scanf("%d",&n);
	//����
	if(copychar(str,str_cpy,k,n)==1)
	{
		printf("���벻����Ҫ��\n");
		return 0;
	}
	//���
	puts(str_cpy);
	return 0;
}

int copychar(char *a,char* b,int k,int n)
{
	int i,j;
	int len;
	len=strlen(a);
	if(k>len||k<=0)
	{
		return 1;
	}
	j=0;
	for(i=k-1;i<k+n-1;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		b[j]=a[i];
		j++;
	}
	b[j]=0;
	return 0;
}