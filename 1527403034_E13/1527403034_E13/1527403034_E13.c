/*�ļ�����1527403034_E13.c
*���ߣ�����
*ʱ�䣺2015��10��24��
*���ܣ�����һ��������5λ����������Ҫ��:��1)������Ǽ�λ������2���ֱ����ÿһλ���֣���3�����������ÿλ����,����ԭΪ321,Ӧ���123
*��ע��
*/
#include<stdio.h>
int main()
{
	int i=0;
	int num=0;
	int temp=1;
	int result=0;
	//����һ��������
	printf("������һ��������5λ����������\n");
	scanf("%d",&num);
	//�ж��Ƿ�С����λ
	if((num<100000)&&(num>0))
	{
	printf("��λ������Ϊ��\n");
	while(num!=0)
		{
			//��ȡÿһλ��
			temp=num%10;
			result=result*10+temp;
			num/=10;
			i++;
			//���ÿһλ��
			if(i==1)
			{
			printf("��λ����%d\n",temp);
			}
			if(i==2)
			{
			printf("ʮλ����%d\n",temp);
			}
			if(i==3)
			{
			printf("��λ����%d\n",temp);
			}
			if(i==4)
			{
			printf("ǧλ����%d\n",temp);
			}
			if(i==5)
			{
			printf("��λ����%d\n",temp);
			}
		}
	printf("��%dλ��\n",i);
	printf("��������Ľ��Ϊ%d\n",result);
	}
	else
	{
	printf("��������ֲ�����Ҫ��\n");
	}
return 0;
}