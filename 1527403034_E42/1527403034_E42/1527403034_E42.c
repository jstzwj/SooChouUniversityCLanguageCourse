/*文件名：1527403034_E42.c
*作者：王俊
*时间：2015年11月25日
*功能：从键盘输入个英文句子。以空格、逗号、句号、分号为分隔符，将这个句子中的单词割出来并显示在屏幕上。每个单词占一行。
*备注：
*/
#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char str[N];
	int len;
	char phrase[N][N]={0};
	int phrase_flag=-1;
	int i=0,j=0;
	int flag=0;
	//输入
	printf("请输入一个字符串\n");
	gets(str);
	len=strlen(str);
	//提取
	for(i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]==',')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]=='.')
		{
			flag=0;
			j=0;
			continue;
		}
		else if(str[i]==';')
		{
			flag=0;
			j=0;
			continue;
		}
		else
		{
			if(flag==0)
			{
				phrase_flag++;
			}
			flag=1;
			phrase[phrase_flag][j]=str[i];
			j++;
		}
	}
	//输出
	printf("单词分割结果为：\n");
	for(i=0;i<=phrase_flag;i++)
	{
		puts(phrase[i]);
	}
	return 0;
}