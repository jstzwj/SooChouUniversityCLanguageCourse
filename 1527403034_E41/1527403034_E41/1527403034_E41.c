/*�ļ�����1527403034_E41.c
*���ߣ�����
*ʱ�䣺2015��11��25��
*���ܣ��Ӽ���������������֡���ĸ���ַ��������������ֹ���һ��������������������ֳ���6������ӵ�7�����ֿ�ʼ����һ���µ������� ���д������ȡ�ַ����е����������� ���磺������ַ���Ϊs123abd345234869de ������ȡ�������У�123 ��345234 �� 869 ��
*��ע��
*/
#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char str[N];//�洢�ַ���
	int integer[N]={0};//�洢����
	int integer_eff_flag=-1;
	int num_flag=0;//���ֱ��
	int count=0;//���λ��
	int i,j;
	//����
	printf("������һ���ַ���\n");
	gets(str);
	//��ȡ����
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			if(num_flag==0)
			{
				integer_eff_flag++;
				count=0;
			}
			num_flag=1;
			integer[integer_eff_flag]=integer[integer_eff_flag]*10+str[i]-'0';
			if(count==5)
			{
				count=0;
				integer_eff_flag++;
			}
			count++;
		}
		else if(str[i]>='a'&&str[i]<='z')
		{
			num_flag=0;
		}
		else
		{
			printf("����������������ĸ������ַ�\n");
			break;
		}

	}
	//���
	for(i=0;i<=integer_eff_flag;i++)
	{
		printf("%10d",integer[i]);
	}
	printf("\n");

	return 0;
}