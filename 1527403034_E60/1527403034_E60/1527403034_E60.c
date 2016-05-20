/*文件名：1527403034_E60.c
*作者：王俊
*时间：2015年12月14日
*功能：正整数十进制转二进制
*备注：
*/
#include "stdio.h"
/*
	功能：正整数十进制转二进制
	参数：int num		十进制数
			char str[]		二进制数
	返回值：无
*/

void ToBinary(int num,char str[]);
int main()
{
	int num;
	char str[sizeof(int)*8];
	//输入
	printf("请输入一个整数\n");
	scanf("%d",&num);
	//转换
	ToBinary(num,str);
	//输出
	printf("转换为二进制为：%s\n",str);
	return 0;
}
void ToBinary(int num,char str[])
{
	int i=0;
	int temp=num;
	int len=0;
	while(temp>0)
	{
		temp/=2;
		len++;
	}
	while(num>0)
	{
		if(num%2==1)
		{
			str[len-i-1]='1';
			num=(num-1)/2;
		}
		else
		{
			str[len-i-1]='0';
			num/=2;
		}
		i++;
	}
	str[len]=0;
}
