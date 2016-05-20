/*文件名：1527403034_E81.c
*作者：王俊
*时间：2016年1月20日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#define LEN 20
/*
功能：读取所有整数
参数：char *addr
	int arry[]
	int len
返回值：int
*/
int ReadNum(char *addr,int arry[],int len);
/*
功能：排序所有整数
参数：
	int arry[]
	int len
返回值：int
*/
int SortNum( int arry[], int len);
/*
功能：输出所有整数
参数：
int arry[]
int len
返回值：int
*/
int WriteNum(char *addr, int arry[], int len);
int main()
{
	int arry[LEN];
	//读取
	printf("读取中\n");
	ReadNum("c:\\cdata\\E81_data.bin", arry, LEN);
	//排序
	printf("排序中\n");
	SortNum(arry, LEN);
	//输出
	printf("输出中\n");
	WriteNum("c:\\cdata\\E81_result.txt", arry, LEN);
	return 0;
}

int ReadNum(char * addr, int arry[], int len)
{
	FILE * fin=NULL;
	int i=0;
	fin = fopen(addr, "rb");
	if (fin == NULL)
	{
		printf("文件读取失败！\n");
		return 1;
	}
	fread(arry, sizeof(int), len, fin);
	fclose(fin);
	return 0;
}

int SortNum(int arry[], int len)
{
	int i, j;
	int key;
	for (i = 1; i < len; i++)
	{
		key = arry[i];
		j = i - 1;
		while (j>=0&&arry[j]>key)
		{
			arry[j+1] = arry[j];
			j--;
		}
		arry[j + 1] = key;
	}
	return 0;
}

int WriteNum(char * addr, int arry[], int len)
{
	FILE * fout = NULL;
	int i = 0;
	fout = fopen(addr, "w");
	if (fout == NULL)
	{
		printf("文件读取失败！\n");
		return 1;
	}
	for (i = 0; i < len;i++)
	{
		fprintf(fout, "%d\n", arry[i]);
	}
	fclose(fout);
	return 0;
}
