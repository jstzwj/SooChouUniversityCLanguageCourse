/*文件名：1527403034_E40.c
*作者：王俊
*时间：2015年11月23日
*功能：不使用字符串处理函数，判断s1中是否存在子字符串s2
*备注：
*/
#include<stdio.h>
#define N 100
int main()
{
	char s1[N];
	char s2[N];
	int i,j;
	int exist=0;
	//输入字符串
	printf("请输入一个字符串：\n");
	gets(s1);
	printf("请输入一个待查找的子字符串：\n");
	gets(s2);
	//判断是否存在
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]==s2[0])
		{
			j=i;
			while(1)
			{

				if(s2[j-i]=='\0')
				{
					exist=1;
					break;
				}
				else if(s1[j]=='\0')
				{
					break;
				}
				else if(s1[j]!=s2[j-i])
				{
					break;
				}
				
				j++;
			}
		}
	}
	if(exist==1)
	{
		printf("存在该子字符串\n");
	}
	else
	{
		printf("不存在该子字符串\n");
	}
	return 0;
}