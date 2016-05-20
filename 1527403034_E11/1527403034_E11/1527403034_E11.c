/*文件名：1527403034_E11.c
*作者：王俊
*时间：2015年10月23日
*功能：已知2013年1月1日是星期二，输入 2013 年的一个日期（月和日），判断这天是星期几。
*备注：
*/
#include<stdio.h>
int main()
{
	int month=0;
	int day=0;
	int week=0;
	//输入月份与日期
	printf("请输入月份与日期：\n");
	scanf("%d%d",&month,&day);
	//判断这个月份有多少天
	switch(month)
	{
	case 1:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		
		break;
	case 2:
		if((day>28)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*1+1;
		break;
	case 3:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*2-1;	
		break;
	case 4:
		if((day>30)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*3;
		break;
	case 5:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*4;
		break;
	case 6:
		if((day>30)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*5+1;
		break;
	case 7:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*6+1;
		break;
	case 8:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
	day+=30*7+2;
		break;
	case 9:
		if((day>30)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*8+3;
		break;
	case 10:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*9+3;
		break;
	case 11:
		if((day>30)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*10+4;
		break;
	case 12:
		if((day>31)||(day<1))
		{
			printf("此月没有这一天！\n");
			return 0;
		}
		day+=30*11+4;
		break;
	default:
		printf("没有这个月份\n");
		return 0;
	}

	//计算是星期几
	week=day%7+1;
	//输出
	switch(week)
	{
	case 1:printf("这一天是星期一\n");break;
	case 2:printf("这一天是星期二\n");break;
	case 3:printf("这一天是星期三\n");break;
	case 4:printf("这一天是星期四\n");break;
	case 5:printf("这一天是星期五\n");break;
	case 6:printf("这一天是星期六\n");break;
	case 7:printf("这一天是星期日\n");break;
	}
	return 0;
}