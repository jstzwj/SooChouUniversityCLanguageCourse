/*�ļ�����1527403034_E49.c
*���ߣ�����
*ʱ�䣺2015��12��3��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 50
/*
	���ܣ���ȡ�ַ����е�����
	������char str[]	��������
		int num[];	��ȡ������
	����ֵ��num[]��Ч����
*/
int GetNumFromStr(char str[],int num[]);
/*
	���ܣ���������������
	������int num[]	��������
		int len	����
	����ֵ����
*/
void Sort(int num[],int len);

int main()
{
	char str[N]={0};
	int num[N]={0};
	int i,j,k;

	//����
	printf("������һ���ַ���\n");
	scanf("%s",str);
	//��ȡ����
	k=GetNumFromStr(str,num);
	//���
	printf("��ȡ������Ϊ��\n");
	for(i=0;i<k;i++)
	{
		printf("%8d",num[i]);
	}
	printf("\n");
	//����
	Sort(num,k);
	//���
	printf("����������Ϊ��\n");
	for(i=0;i<k;i++)
	{
		printf("%8d",num[i]);
	}
	printf("\n");
	return 0;
}


int GetNumFromStr(char str[],int num[])
{
	int flag=2;
	int count=0;
	int count2=0;
	int i;

	num[count]=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			if(count2==6)
			{
				count++;
				num[count]=0;
				count2=0;
			}
			if(flag==1)
			{
				count2=0;
				count++;
			}
			num[count]=num[count]*10+str[i]-'0';
			count2++;
			
			flag=0;
			
		}
		else
		{
			if(flag==0)
			{
				count2=0;
				flag=1;
			}
		}

	}

	return count+1;
}
//ð������
void Sort(int num[],int len)
{
	int i,j;
	int temp;
	for(i=len-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(num[j]>num[j+1])
			{
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}

		}
	}
}