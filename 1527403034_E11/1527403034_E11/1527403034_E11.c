/*�ļ�����1527403034_E11.c
*���ߣ�����
*ʱ�䣺2015��10��23��
*���ܣ���֪2013��1��1�������ڶ������� 2013 ���һ�����ڣ��º��գ����ж����������ڼ���
*��ע��
*/
#include<stdio.h>
int main()
{
	int month=0;
	int day=0;
	int week=0;
	//�����·�������
	printf("�������·������ڣ�\n");
	scanf("%d%d",&month,&day);
	//�ж�����·��ж�����
	switch(month)
	{
	case 1:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		
		break;
	case 2:
		if((day>28)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*1+1;
		break;
	case 3:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*2-1;	
		break;
	case 4:
		if((day>30)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*3;
		break;
	case 5:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*4;
		break;
	case 6:
		if((day>30)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*5+1;
		break;
	case 7:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*6+1;
		break;
	case 8:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
	day+=30*7+2;
		break;
	case 9:
		if((day>30)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*8+3;
		break;
	case 10:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*9+3;
		break;
	case 11:
		if((day>30)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*10+4;
		break;
	case 12:
		if((day>31)||(day<1))
		{
			printf("����û����һ�죡\n");
			return 0;
		}
		day+=30*11+4;
		break;
	default:
		printf("û������·�\n");
		return 0;
	}

	//���������ڼ�
	week=day%7+1;
	//���
	switch(week)
	{
	case 1:printf("��һ��������һ\n");break;
	case 2:printf("��һ�������ڶ�\n");break;
	case 3:printf("��һ����������\n");break;
	case 4:printf("��һ����������\n");break;
	case 5:printf("��һ����������\n");break;
	case 6:printf("��һ����������\n");break;
	case 7:printf("��һ����������\n");break;
	}
	return 0;
}