/*�ļ�����1527403034_E27.c
*���ߣ�����
*ʱ�䣺2015��11��13��
*���ܣ���ɸ����100֮�ڵ�����������ӡ������е�����ÿ5��һ�С�
*��ע��
*/
#include<stdio.h>
int main()
{
	int judge[101];
	int i=0,j=0;
	//��ʼ��
	for(i=0;i<=100;i++)
	{
		judge[i]=1;
	}
	//���������ж�
	judge[0]=judge[1]=0;
	judge[2]=1;
	for(i=3;i<=100;i++)
	{
		for(j=2;j<i;j++)
		{
			if((i%j)==0)
			{
				judge[i]=0;
				break;
			}
		}

	}

	//���
	j=0;
	for(i=0;i<=100;i++)
	{
		if(judge[i]==1)
		{
			printf("%6d",i);
			if((j+1)%5==0)
			{
				printf("\n");
			}
			j++;
		}
		
	}

	return 0;
}