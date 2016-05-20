/*文件名：1527403034_E70.c
*作者：王俊
*时间：2015年12月24日
*功能：
*备注：
*/
#include<stdio.h>
#include<string.h>
/*
功能：查找字符串
参数：char* s1		待处理的字符串
	char* s2
返回值：int 是否含有此字符串
*/
int findchar(char * s1,char * s2);
int main()
{
	char str1[40];
	char str2[40];
	int temp;
	//输入
	printf("请输入第一个字符串：\n");
	gets(str1);
	printf("请输入第二个字符串：\n");
	gets(str2);
	//查找
	temp = findchar(str1,str2);
	if ( temp!= -1)
	{
		printf("字符串1包含字符串2，第一个起始位置为%d\n", temp);
	}
	else
	{
		printf("字符串1不包含字符串2\n");
	}
	return 0;
}

int findchar(char * s1,char * s2)
{
	int i,j;
	int len1,len2;
	len1=strlen(s1);
	len2=strlen(s2);
	for(i=0;i<len1;i++)
	{
		if(s1[i]==s2[0])
		{
			for(j=i;s1[j]!=0&&s2[j]!=0;j++)
			{
				if (s1[i + j] != s2[j])
				{
					return -1;
				}
			}
			if (j == len2)
			{
				break;
			}
		}
	}
	return i;
}