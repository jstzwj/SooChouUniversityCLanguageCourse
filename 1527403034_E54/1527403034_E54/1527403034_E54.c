/*文件名：1527403034_E54.c
*作者：王俊
*时间：2015年12月8日
*功能：将由‘0’-‘9’字符构成的字符串转换为整数
*备注：
*/
#include<stdio.h>
/*
	功能：将由‘0’-‘9’字符构成的字符串转换为整数
	参数：char str[];	字符串
	返回值：int num;整数，-1为不合法字符串
*/
int StrToNum(char str[]);
int main()
{
	char str[50];
	int temp;
	//输入
	printf("请输入一个字符串：\n");
	gets(str);
	//转换输出
	temp=StrToNum(str);
	if(temp!=-1)
	{
		//输出
		printf("转换后为%d\n",temp);
	}
	else
	{
		printf("字符串不合法\n");
	}
	return 0;
}

int StrToNum(char str[])
{
	int num=0;
	int i;
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			num=num*10+str[i]-'0';
		}
		else
		{
			return -1;
		}
	}
	return num;
}