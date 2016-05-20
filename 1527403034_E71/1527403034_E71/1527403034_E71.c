/*�ļ�����1527403034_E71.c
*���ߣ�����
*ʱ�䣺2015��12��28��
*���ܣ�
*��ע��
*/
#include<stdio.h>
typedef struct
{
	int year;
	int month;
	int day;
} date;
/*
���ܣ��������ڲ�ֵ
������date1 
	date2
����ֵ��int ���ڲ�ֵ
*/
int CalDay(date a,date b)
{
	int monthtable[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int asta=0;		//a����׼������
	int bsta=0;		//b����׼������
	int yeardistance=0;
	int monthtemp=0;
	int i;
	//���ںϷ����ж�
	if (a.year % 4 == 0 && a.year % 100 != 0 || a.year % 400 == 0)
	{
		monthtable[2]++;
	}
	if (a.month>12||a.month<=0)
	{
		printf("���ڲ��Ϸ�!\n");
		return -1;
	}
	if (a.day > monthtable[a.month] || a.day <= 0)
	{
		printf("���ڲ��Ϸ�!\n");
		return -1;
	}
	monthtable[2]--;
	if (b.year % 4 == 0 && b.year % 100 != 0 || b.year % 400 == 0)
	{
		monthtable[2]++;
	}
	if (b.month>12 || b.month <= 0)
	{
		printf("���ڲ��Ϸ�!\n");
		return -1;
	}
	if (b.day > monthtable[b.month] || b.day <= 0)
	{
		printf("���ڲ��Ϸ�!\n");
		return -1;
	}
	monthtable[2]--;
	//����a��1.1������
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
	//����b��1.1������
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
	//�ж����
	if (a.year > b.year)
	{
		//����a��b֮������
		yeardistance = 0;
		for (i = b.year; i < a.year; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400==0)
			{
				yeardistance++;
			}
			yeardistance += 365;
		}
		//�������ڲ�
		return yeardistance + asta - bsta;
	}
	else if (a.year<b.year)
	{
		//����a��b֮������
		yeardistance = 0;
		for (i = a.year; i < b.year; i++)
		{
			if (i % 4 == 0 && i % 100 != 0 || i % 400==0)
			{
				yeardistance++;
			}
			yeardistance += 365;
		}
		//�������ڲ�
		return yeardistance + bsta - asta;
	}
	else
	{
		//�Ƚ��·�
		if (a.month > b.month)
		{
			//�������ڲ�
			return asta - bsta;
		}
		else
		{
			//�������ڲ�
			return (bsta - asta > 0) ? (bsta - asta): (asta - bsta);
		}
	}
}

int main()
{
	date date1,date2;
	int day;
	//����
	printf("�������һ�����ڣ�\n");
	scanf("%d%d%d",&date1.year,&date1.month,&date1.day);
	printf("������ڶ������ڣ�\n");
	scanf("%d%d%d", &date2.year, &date2.month, &date2.day);
	//�����������
	day=CalDay(date1,date2);
	//���
	if (day == -1)
	{
		return 1;
	}
	printf("�������%d��",day);
	return 0;
}