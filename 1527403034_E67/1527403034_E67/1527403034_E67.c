/*�ļ�����1527403034_E67.c
*���ߣ�����
*ʱ�䣺2015��12��24��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<string.h>
/*
���ܣ�ȥ���ַ���s��k��ʼn���ַ�
������char* p		��������ַ���
	int k		
	int n
����ֵ��int ��Ϊ0��ɾ��ʧ��
*/
int delchar(char *p,int k,int n);
int main()
{
	char str[40];
	int k,n;
	//����
	printf("������һ���ַ�����\n");
	gets(str);
	printf("������Ҫ�ںδ�ɾ��(1~%d):\n",strlen(str));
	scanf("%d",&k);
	printf("������Ҫɾ�������ַ�:\n");
	scanf("%d",&n);
	//ɾ��
	if(delchar(str,k,n)==1)
	{
		printf("���벻����Ҫ��\n");
		return 0;
	}
	//���
	puts(str);
	return 0;
}

int delchar(char *p,int k,int n)
{
	int i;
	int len;
	len=strlen(p);
	if(k<0||k>=len)
	{
		printf("ɾ����λ�ó�����Χ");
		return 1;
	}
	if(n>len-k+1)
	{
		printf("ɾ�����ַ���������Χ");
		return 1;
	}
	for(i=k+n-1;p[i]!=0;i++)
	{
		p[i-n]=p[i];
	}
	p[i-n]=p[i];
	return 0;
}