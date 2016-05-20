/*文件名：1527403034_E49.c
*作者：王俊
*时间：2015年12月3日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
/*
	功能：获取字符串中的整数
	参数：char str[]	整型数组
		int num[];	获取的数字
	返回值：num[]有效长度
*/
int GetNumFromStr(char str[],int num[]);
/*
	功能：对整型数组排序
	参数：int num[]	整型数组
		int len	长度
	返回值：无
*/
void Sort(int num[],int len);

int main()
{
	char str[N]={0};
	int num[N]={0};
	int i,j,k;

	//输入
	printf("请输入一串字符：\n");
	scanf("%s",str);
	//获取整数
	k=GetNumFromStr(str,num);
	//输出
	printf("提取的整数为：\n");
	for(i=0;i<k;i++)
	{
		printf("%8d",num[i]);
	}
	printf("\n");
	//排序
	Sort(num,k);
	//输出
	printf("排序后的整数为：\n");
	for(i=0;i<k;i++)
	{
		printf("%8d",num[i]);
	}
	printf("\n");
	return 0;
}


int GetNumFromStr(char str[],int num[])
{
	int flag=2;
	int count=0;
	int count2=0;
	int i;

	num[count]=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			if(count2==6)
			{
				count++;
				num[count]=0;
				count2=0;
			}
			if(flag==1)
			{
				count2=0;
				count++;
			}
			num[count]=num[count]*10+str[i]-'0';
			count2++;
			
			flag=0;
			
		}
		else
		{
			if(flag==0)
			{
				count2=0;
				flag=1;
			}
		}

	}

	return count+1;
}
//冒泡排序
void Sort(int num[],int len)
{
	int i,j;
	int temp;
	for(i=len-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}

		}
	}
}