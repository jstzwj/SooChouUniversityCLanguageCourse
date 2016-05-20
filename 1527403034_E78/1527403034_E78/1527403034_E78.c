/*文件名：1527403034_E78.c
*作者：王俊
*时间：2016年1月16日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
/*
功能：合并文件
参数：char * from1
char * from2
char * to
返回值：int 
*/
int LinkFile(char * from1,char * from2,char *to);
int main()
{
	printf("正在合并\n");
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
		printf("文件打开失败！\n");
		return 1;
	}
	fin2 = fopen(from2,"r");
	if (fin2 == NULL)
	{
		printf("文件打开失败！\n");
		return 1;
	}
	fout = fopen(to, "w");
	if (fout == NULL)
	{
		printf("文件打开失败！\n");
		return 1;
	}
	//将文件一复制到目标文件
	while ((temp=fgetc(fin1))!=EOF)
	{
		fputc(temp, fout);
	}
	//将文件二复制到目标文件
	while ((temp = fgetc(fin2)) != EOF)
	{
		fputc(temp, fout);
	}
	return 0;
}
