/*文件名：1527403034_E10.c
*作者：王俊
*时间：2015年10月23日
*功能：不考虑闰年，输入月份,用 switch 语句实现显示该月有多少天。
*备注：
*/
#include<stdio.h>
int main()
{
	int month=0;
	int day=0;
	//输入月份
	printf("请输入月份：\n");
	scanf("%d",&month);
	//判断这个月份有多少天
	switch(month)
	{
	case 1:day=31;break;
	case 2:day=28;break;
	case 3:day=31;break;
	case 4:day=30;break;
	case 5:day=31;break;
	case 6:day=30;break;
	case 7:day=31;break;
	case 8:day=31;break;
	case 9:day=30;break;
	case 10:day=31;break;
	case 11:day=30;break;
	case 12:day=31;break;
	}
	//输出
	printf("这个月有%d天\n",day);
	return 0;
}