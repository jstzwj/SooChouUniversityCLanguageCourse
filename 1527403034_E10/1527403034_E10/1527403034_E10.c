/*�ļ�����1527403034_E10.c
*���ߣ�����
*ʱ�䣺2015��10��23��
*���ܣ����������꣬�����·�,�� switch ���ʵ����ʾ�����ж����졣
*��ע��
*/
#include<stdio.h>
int main()
{
	int month=0;
	int day=0;
	//�����·�
	printf("�������·ݣ�\n");
	scanf("%d",&month);
	//�ж�����·��ж�����
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
	//���
	printf("�������%d��\n",day);
	return 0;
}