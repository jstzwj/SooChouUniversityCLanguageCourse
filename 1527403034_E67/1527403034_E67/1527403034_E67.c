/*文件名：1527403034_E67.c
*作者：王俊
*时间：2015年12月24日
*功能：
*备注：
*/
#include<stdio.h>
#include<string.h>
/*
功能：去除字符串s从k开始n个字符
参数：char* p		待处理的字符串
	int k		
	int n
返回值：int 若为0，删除失败
*/
int delchar(char *p,int k,int n);
int main()
{
	char str[40];
	int k,n;
	//输入
	printf("请输入一个字符串：\n");
	gets(str);
	printf("请输入要在何处删除(1~%d):\n",strlen(str));
	scanf("%d",&k);
	printf("请输入要删除多少字符:\n");
	scanf("%d",&n);
	//删除
	if(delchar(str,k,n)==1)
	{
		printf("输入不符合要求\n");
		return 0;
	}
	//输出
	puts(str);
	return 0;
}

int delchar(char *p,int k,int n)
{
	int i;
	int len;
	len=strlen(p);
	if(k<0||k>=len)
	{
		printf("删除的位置超出范围");
		return 1;
	}
	if(n>len-k+1)
	{
		printf("删除的字符数超出范围");
		return 1;
	}
	for(i=k+n-1;p[i]!=0;i++)
	{
		p[i-n]=p[i];
	}
	p[i-n]=p[i];
	return 0;
}