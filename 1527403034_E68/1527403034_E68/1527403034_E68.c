/*文件名：1527403034_E68.c
*作者：王俊
*时间：2015年12月24日
*功能：
*备注：
*/
#include<stdio.h>
#include<string.h>
/*
功能：复制字符串s从k开始n个字符到另一个字符串中
参数：char* a		待处理的字符串
	char* b		待处理的字符串
	int k		
	int n
返回值：int 若为0，复制失败
*/
int copychar(char *a,char* b,int k,int n);
int main()
{
	char str[40];
	char str_cpy[40];
	int k,n;
	//输入
	printf("请输入一个字符串：\n");
	gets(str);
	printf("请输入要在何处开始复制(1~len):\n");
	scanf("%d",&k);
	printf("请输入要复制多少字符:\n");
	scanf("%d",&n);
	//复制
	if(copychar(str,str_cpy,k,n)==1)
	{
		printf("输入不符合要求\n");
		return 0;
	}
	//输出
	puts(str_cpy);
	return 0;
}

int copychar(char *a,char* b,int k,int n)
{
	int i,j;
	int len;
	len=strlen(a);
	if(k>len||k<=0)
	{
		return 1;
	}
	j=0;
	for(i=k-1;i<k+n-1;i++)
	{
		if(a[i]==0)
		{
			break;
		}
		b[j]=a[i];
		j++;
	}
	b[j]=0;
	return 0;
}