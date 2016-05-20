/*文件名：1527403034_E76.c
*作者：王俊
*时间：2016年1月16日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
/*
功能：将一个文本文件复制到另一个位置
参数：char *from
	char * to
返回值：int
*/
int CopyFile(char *from,char *to)
{
	FILE *fin;
	FILE *fout;
	char temp;
	//打开文件
	fin=fopen(from,"r");
	//错误检测
	if (fin==NULL)
	{
		printf("打开文件发生错误！\n");
		return 1;
	}
	fout = fopen(to,"w");
	//错误检测
	if (fout == NULL)
	{
		printf("建立文件发生错误！\n");
		return 1;
	}
	//复制内容
	while ((temp=fgetc(fin))!=EOF)
	{
		fputc(temp,fout);
	}
	//关闭文件
	fclose(fin);
	fclose(fout);
}


int main()
{
	//复制文件
	printf("将E76_data.txt复制到E76_result.txt\n");
	if (CopyFile("c:\\cdata\\E76_data.txt","c:\\cdata\\E76_result.txt")!=1)
	{
		printf("复制成功！\n");
	}
	else
	{
		printf("复制失败！\n");
	}
	system("pause");
	return 0;
}