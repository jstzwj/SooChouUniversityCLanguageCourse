/*�ļ�����1527403034_E02.c
*���ߣ�����
*���ڣ�2015��10��16��
*���ܣ������û������ 3 ��������ƽ��ֵ���͡����ֵ����Сֵ�����������Ļ��
*��ע��
*/
#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,sum,max,min;
	float average;
	//������������
	printf("������3��������\n");
	scanf("%d%d%d",&a,&b,&c);
	//����ƽ��ֵ
	average=(a+b+c)/3.0;
	//�������ֵ
	if(a>b)
	{
		if(a>c)
		{
			max=a;
		}
		else
		{
			max=c;
		}
	}
	else 
	{
		if(b>c)
		{
			max=b;
		}
		else
			{
				max=c;
		}
	}
	//������Сֵ
	if(a>b)
	{
		if(b>c)
			{
			min=c;
		}
		else {
			min=b;
		}
	}
	else
	{
		if(a>c)
			{
				min=c;
		}
		else 
			{
				min=a;
		}
	}
	//�����
	sum=a+b+c;
	printf("ƽ��ֵ��%-8.4f\n���ֵ��%6d\n��Сֵ��%6d\n�ͣ�%6d\n",average,max,min,sum);
return 0;
}
