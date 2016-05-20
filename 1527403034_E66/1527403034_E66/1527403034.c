/*文件名：1527403034_E66.c
*作者：王俊
*时间：2015年12月23日
*功能：
*备注：
*/
#include<stdio.h>
/*
功能：判断字符串是否回文
参数：char str[]		待计算的字符串
返回值：是否回文
*/
int judge(char str[]);
int main()
{
	char str[50];
	//输入
	printf("请输入一个字符串：\n");
	gets(str);
	if (judge(str))
	{
		printf("是回文字符串\n");
	}
	else
	{
		printf("不是回文字符串\n");
	}
	return 0;
}

int judge(char str[])
{
	char *start, *end;
	int len;

	start = str;
	for (end = str; *end != 0;end ++)
	{
	}
	end--;
	while (start<end)
	{
		if (*start != *end)
		{
			return 0;
		}
		start++;
		end--;
	}
	return 1;
}