/*文件名：1527403034_E71.c
*作者：王俊
*时间：2015年12月28日
*功能：
*备注：
*/
#include<stdio.h>
typedef struct
{
	int year;
	int month;
	int day;
} date;
/*
功能：计算日期差值
参数：date1 
	date2
返回值：int 日期差值
*/
int CalDay(date a,date b)
{
	int monthtable[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int asta=0;		//a到基准的日期
	int bsta=0;		//b到基准的日期
	int yeardistance=0;
	int monthtemp=0;
	int i;
	//日期合法化判断
	if (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0)
	{
		monthtable[2]++;
	}
	if (a.month>12||a.month<=0)
	{
		printf("日期不合法!\n");
		return -1;
	}
	if (a.day > monthtable[a.month] || a.day <= 0)
	{
		printf("日期不合法!\n");
		return -1;
	}
	monthtable[2]--;
	if (b.year % 4 == 0 && b.year % 100 != 0 || b.year % 400 == 0)
	{
		monthtable[2]++;
	}
	if (b.month>12 || b.month <= 0)
	{
		printf("日期不合法!\n");
		return -1;
	}
	if (b.day > monthtable[b.month] || b.day <= 0)
	{
		printf("日期不合法!\n");
		return -1;
	}
	monthtable[2]--;
	//计算a到1.1的日期
	monthtemp = 0;
	for (i = 1; i < a.month;i++)
	{
		if ((a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400==0)&&i==2)
		{
			monthtemp++;
		}
		monthtemp += monthtable[i];
	}
	asta = monthtemp+a.day;
	//计算b到1.1的日期
	monthtemp = 0;
	for (i = 1; i < b.month; i++)
	{
		if ((b.year % 4 == 0 && b.year % 100 != 0 || b.year % 400==0) && i == 2)
		{
			monthtemp++;
		}
		monthtemp += monthtable[i];
	}
	bsta = monthtemp+b.day;
	//判断年份
	if (a.year > b.year)
	{
		//计算a与b之间天数
		yeardistance = 0;
		for (i = b.year; i < a.year; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400==0)
			{
				yeardistance++;
			}
			yeardistance += 365;
		}
		//计算日期差
		return yeardistance + asta - bsta;
	}
	else if (a.year<b.year)
	{
		//计算a与b之间天数
		yeardistance = 0;
		for (i = a.year; i < b.year; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400==0)
			{
				yeardistance++;
			}
			yeardistance += 365;
		}
		//计算日期差
		return yeardistance + bsta - asta;
	}
	else
	{
		//比较月份
		if (a.month > b.month)
		{
			//计算日期差
			return asta - bsta;
		}
		else
		{
			//计算日期差
			return (bsta - asta > 0) ? (bsta - asta): (asta - bsta);
		}
	}
}

int main()
{
	date date1,date2;
	int day;
	//输入
	printf("请输入第一个日期：\n");
	scanf("%d%d%d",&date1.year,&date1.month,&date1.day);
	printf("请输入第二个日期：\n");
	scanf("%d%d%d", &date2.year, &date2.month, &date2.day);
	//计算相差日期
	day=CalDay(date1,date2);
	//输出
	if (day == -1)
	{
		return 1;
	}
	printf("日期相差%d天",day);
	return 0;
}