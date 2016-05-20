/*文件名：1527403034_E05.c
*作者：王俊
*时间：2015年10月16日
*功能：从键盘输入一个字符，输出这个字符对应的 ASCII 码。 
*备注：
*/
#include <stdio.h>
int main()
{
	char a;
	//输入字符
	printf("请输入一个字符：\n");
	scanf("%c",&a);
	printf("ASCII值为%d\n",a);
return 0;
}