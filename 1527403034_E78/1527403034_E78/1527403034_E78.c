/*�ļ�����1527403034_E78.c
*���ߣ�����
*ʱ�䣺2016��1��16��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
/*
���ܣ��ϲ��ļ�
������char * from1
char * from2
char * to
����ֵ��int 
*/
int LinkFile(char * from1,char * from2,char *to);
int main()
{
	printf("���ںϲ�\n");
	LinkFile("c:\\cdata\\E78_data1.txt", "c:\\cdata\\E78_data1.txt", "c:\\cdata\\E78_result.txt");
	return 0;
}

int LinkFile(char * from1, char * from2, char * to)
{
	FILE *fin1;
	FILE *fin2;
	FILE *fout;
	char temp;
	fin1 = fopen(from1,"r");
	if (fin1==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 1;
	}
	fin2 = fopen(from2,"r");
	if (fin2 == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 1;
	}
	fout = fopen(to, "w");
	if (fout == NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 1;
	}
	//���ļ�һ���Ƶ�Ŀ���ļ�
	while ((temp=fgetc(fin1))!=EOF)
	{
		fputc(temp, fout);
	}
	//���ļ������Ƶ�Ŀ���ļ�
	while ((temp = fgetc(fin2)) != EOF)
	{
		fputc(temp, fout);
	}
	return 0;
}
