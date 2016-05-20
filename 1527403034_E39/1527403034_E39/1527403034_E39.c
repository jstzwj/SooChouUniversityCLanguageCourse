/*文件名：1527403034_E39.c
*作者：王俊
*时间：2015年11月23日
*功能：从键盘输入一个字符串，将这字符串变成逆序并输出。如：输入字符串为“ abcdefg”，则逆序字符串为“ gfedcba”。
*备注：
*/
#include<stdio.h>
#include<string.h>
#define N 11
int main()
{
	char str[N];
	int i;
	int temp;
	int len;
	//输入字符串
	printf("请输入一串字符串:\n");
	gets(str);
	len=strlen(str);
	//逆序
	for(i=0;(i!=len-i-1)&&(i!=len-i);i++)
	{
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
	//输出
	printf("逆序输出结果为：\n");
	puts(str);
	return 0;
}