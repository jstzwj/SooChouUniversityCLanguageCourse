/*�ļ�����1527403034_E30.c
*���ߣ�����
*ʱ�䣺2015��11��19��
*���ܣ���֪int arry[]={35,46,57,13,24,35,99,68,13,79,88,46} �� �뽫�������ظ���Ԫ��ȥ����������С����˳�����������
*��ע��
*/
#include<stdio.h>
int main()
{
	int arry[]={35,46,57,13,24,35,99,68,13,79,88,46};
	int i,j,k;
	int len;
	int temp;
	len=12;
	//ȥ���ظ�Ԫ��
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(arry[i]==arry[j])
			{
				for(k=j+1;k<len;k++)
				{
					arry[k-1]=arry[k];
				}
				len--;
				i--;
			}
		}
	}
	//����
	for(i=len-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arry[j]>arry[j+1])
			{
				temp=arry[j];
				arry[j]=arry[j+1];
				arry[j+1]=temp;
			}

		}
	}
	//���
	for(i=0;i<len;i++)
	{
		printf("%-4d",arry[i]);
	}
	printf("\n");
	return 0;
}