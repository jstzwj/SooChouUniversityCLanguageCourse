/*�ļ�����1527403034_E69.c
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
����ֵ��char*		�ַ����׵�ַ
*/
char* delchar(char *p,int k,int n);
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
	delchar(str,k,n);
	//���
	puts(str);
	return 0;
}

char* delchar(char *p,int k,int n)
{
	int i;
	int len;
	len=strlen(p);
	if(k<0||k>=len)
	{
		printf("ɾ����λ�ó�����Χ");
		return p;
	}
	if(n>len-k+1)
	{
		n=len-k+1;
	}
	for(i=k+n-1;p[i]!=0;i++)
	{
		p[i-n]=p[i];
	}
	p[i-n]=p[i];
	return p;
}