/*�ļ�����1527403034_E14.c
*���ߣ�����
*ʱ�䣺2015��10��24��
*���ܣ��Ӽ�����������3������������С����˳�������
*��ע��
*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	//������������
	printf("����������������\n");
	scanf("%d%d%d",&a,&b,&c);
	//���д�С�Ƚ�
	if(a>b)
	{
		if(b>c)
		{
			printf("��С�������Ϊ��%d %d %d\n",c,b,a);
		}
		else
		{
			if(a>c)
			{
				printf("��С�������Ϊ��%d %d %d\n",b,c,a);
			}
			else
			{
				printf("��С�������Ϊ��%d %d %d\n",b,a,c);
			}
		}
	}
	else
	{
		if(b>c)
		{
			if(a>c)
			{
				printf("��С�������Ϊ��%d %d %d\n",c,a,b);
			}
			else
			{
				printf("��С�������Ϊ��%d %d %d\n",a,c,b);
			}
		}
		else
		{
			printf("��С�������Ϊ��%d %d %d\n",a,b,c);
		}
	}

	return 0;
}