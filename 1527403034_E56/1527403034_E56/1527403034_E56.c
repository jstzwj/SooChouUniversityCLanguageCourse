/*文件名：1527403034_E56.c
*作者：王俊
*时间：2015年12月10日
*功能：将十进制正整数转换为二进制
*备注：
*/
#include<stdio.h>
/*
	作用：将十进制转换为二进制
	参数：int num	待转换的整数
		int result[] 保存二进制结果的数组
	返回值：无
*/
int ToBinary(int num,char result[]);
int main()
{
	int i;
	int len;
	int num;
	char result[sizeof(int)*8];
	//输入
	printf("请输入一个整数：\n");
	scanf("%d",&num);
	//转换为二进制
	len=ToBinary(num,result);
	//输出结果
	printf("转换为二进制的结果为：\n");
	puts(result);
	return 0;
}


int ToBinary(int num,char result[])
{
	int i;
	int len=0,temp;
	i=0;
	temp=num;
	//计算二进制结果的长度
	while(temp>0)
	{
		temp/=2;
		len++;
	}
	//转换为二进制
	while(num>0)
	{
		if(num%2==1)
		{
			result[len-i-1]='1';
		}
		else
		{
			result[len-i-1]='0';
		}
		num/=2;
		i++;
	}
	//加上字符串结束标记
	result[len]=0;
	return 0;
}