/*文件名：1527403034_E01.c
*作者：王俊
*时间：2015年10月16日
*功能：从键盘输入两个正整数 a 和 b ，计算并输出 a / b 的商和余数
*备注：
*/
#include<stdio.h>
int main()
{
	int a,b;
	float c;
	/*输入整数a,b*/
	printf("请输入两个正整数：\n");
	scanf("%d%d",&a,&b);
	c=(float)a/(float)b;//将a与b的商赋给c
	a%=b;//将a与b的余数赋给a
	//输出
	printf("商为%6f\n余数为%6d\n",c,a);

return 0;
}