/*文件名：1527403034_E55.c
*作者：王俊
*时间：2015年12月8日
*功能：对十二个月的单词进行字典排序
*备注：
*/
#include<stdio.h>
#include<string.h>
/*
	功能：对单词进行字典排序
	参数：char str[];	字符串
	返回值：无
*/
int DiractionarySort(char str[][10]);
int main()
{
	char str[12][10];
	int i;
	strcpy(str[0],"January");
	strcpy(str[1],"February");
	strcpy(str[2],"March");
	strcpy(str[3],"April");
	strcpy(str[4],"May");
	strcpy(str[5],"June");
	strcpy(str[6],"July");
	strcpy(str[7],"August");
	strcpy(str[8],"September");
	strcpy(str[9],"October");
	strcpy(str[10],"November");
	strcpy(str[11],"December");
	//进行字典排序
	DiractionarySort(str);
	//输出
	for(i=0;i<12;i++)
	{
		puts(str[i]);
	}
	return 0;
}
int DiractionarySort(char str[][10])
{
	int i,j;
	char temp[11];
	for(i=0;i<12;i++)
	{
		for(j=10;j>=i;j--)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	return 0;
}