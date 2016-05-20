/*文件名：1527403034_E53.c
*作者：王俊
*时间：2015年12月8日
*功能：统计一个英文句子中单词的个数
*备注：
*/
#include<stdio.h>
/*
	功能：统计一个英文句子中单词的个数
	参数：char str[];	英文句子
	返回值：int num;单词个数
*/
int CountWord(char str[]);
int main()
{
	char str[80];
	//输入
	printf("请输入一个英文句子:\n");
	gets(str);
	//计算单词个数并输出
	printf("单词数为%d\n",CountWord(str));
	return 0;
}

int CountWord(char str[])
{
	int i;
	int flag=2;
	int count=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]==' ')
		{
			flag=0;
		}
		else
		{
			if(flag!=1)
				count++;
			flag=1;
		}
	}
	return count;
}