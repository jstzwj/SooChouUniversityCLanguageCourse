/*文件名：1527403034_E19.c
*作者：王俊
*时间：2015年10月29日
*功能：求Sn=a+aa+aa... 的值。其中a是一个数字。a和n都是由键盘输入
*备注：
*/
#include<stdio.h>
int main()
{
	int a=0,i=0,j=0,n=0;
	long s=0,Sn=0;
	printf("输入数字a与n:\n");
	scanf("%d%d",&a,&n);
	for(i=1;i<=n;i++)
	{
		s=s*10+a;
		Sn+=s;
	}
	printf("Sn的值为%ld\n",Sn);
	return 0;
}