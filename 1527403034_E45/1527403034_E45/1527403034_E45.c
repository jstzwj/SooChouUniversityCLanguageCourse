/*�ļ�����1527403034_E45.c
*���ߣ�����
*ʱ�䣺2015��12��2��
*���ܣ���1000���ڵ�����������ÿ��8���������Ļ�ϣ���Ҫ��ɸ������ дһ���ж������Ƿ��������ĺ�����
*��ע��
*/
#include<stdio.h>
#include<math.h>
#define N 1000
/*
	���ܣ����2��ĳ����֮�������������ÿ��8��
	������int limit �Ͻ�
	����ֵ��0	�������
			1	limit��Χ����ȷ
*/
int PrintPrimeNumber(int limit);
int main()
{
	PrintPrimeNumber(N);
	return 0;
}

int PrintPrimeNumber(int limit)
{
	int i,j;
	int count=0;
	if(limit>0)
	{
		//�ж��Ƿ�Ϊ����
		for(i=2;i<=limit;i++)
		{
			for(j=2;j<i;j++)
			{
				if((i%j)==0)
				{
					break;
				}
			}
			if(j==i)
			{
				count++;
				printf("%5d",i);
				if(count%8==0)
				{
					printf("\n");
				}
				
			}

		}
		return 0;
	}
	else
	{
		return 1;
	}
}