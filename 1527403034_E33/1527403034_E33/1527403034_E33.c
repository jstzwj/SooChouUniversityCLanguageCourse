/*�ļ�����1527403034_E33.c
*���ߣ�����
*ʱ�䣺2015��11��19��
*���ܣ���֪int arry[]={98, 23, 56, 78, 34, 256, 12, 789}����ʹ��ѡ�񷨶�����Ԫ�ذ������ֵ֮�ʹӴ�С����
*��ע��
*/
#include<stdio.h>
int main()
{
	int arry[]={98,23,56,78,34,256,12,789};
	int value[8]={0};
	int len;
	int temp,temp2;
	int i,j,max;
	len=8;
	//�����λ���ĺ�
	for(i=0;i<len;i++)
	{
		temp=arry[i];
		while(temp>0)
		{
			value[i]=value[i]*10+temp%10;
			temp/=10;
		}
	}
	//ѡ��������������
	for(i=0;i<len-1;i++)
	{
		max=i;
		for(j=i;j<len;j++)
		{
			if(value[max]<value[j])
			{
				max=j;
			}
		}
		temp=value[max];
		temp2=arry[max];
		for(j=max;j>i;j--)
		{
			value[j]=value[j-1];
			arry[j]=arry[j-1];
		}
		value[i]=temp;
		arry[i]=temp2;
	}
	//���
	for(i=0;i<len;i++)
	{
		printf("%5d",arry[i]);
	}
	printf("\n");
	return 0;
}