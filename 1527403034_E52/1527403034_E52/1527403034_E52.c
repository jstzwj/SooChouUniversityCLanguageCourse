/*文件名：1527403034_E52.c
*作者：王俊
*时间：2015年12月8日
*功能：将大写字母转换为小写字母，将小写字母转换为大写字母
*备注：
*/
#include<stdio.h>
/*
	功能：将大写字母转换为小写字母，将小写字母转换为大写字母
	参数：char str[];待转换的的字符串
	返回值：无
*/
void ExCapitalLowercase(char str[]);
int main()
{
	char str[20];
	//输入
	printf("请输入一个字符串\n");
	gets(str);
	//输出转换后的字符串
	ExCapitalLowercase(str);
	puts(str);
	return 0;
}
void ExCapitalLowercase(char str[])
{
	int i;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			str[i]=str[i]-'a'+'A';
		}
		else if(str[i]>='A'&&str[i]<='Z')
		{
			str[i]=str[i]+'a'-'A';
		}
	}
}