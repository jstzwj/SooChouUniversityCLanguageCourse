/*�ļ�����1527403034_E53.c
*���ߣ�����
*ʱ�䣺2015��12��8��
*���ܣ�ͳ��һ��Ӣ�ľ����е��ʵĸ���
*��ע��
*/
#include<stdio.h>
/*
	���ܣ�ͳ��һ��Ӣ�ľ����е��ʵĸ���
	������char str[];	Ӣ�ľ���
	����ֵ��int num;���ʸ���
*/
int CountWord(char str[]);
int main()
{
	char str[80];
	//����
	printf("������һ��Ӣ�ľ���:\n");
	gets(str);
	//���㵥�ʸ��������
	printf("������Ϊ%d\n",CountWord(str));
	return 0;
}

int CountWord(char str[])
{
	int i;
	int flag=2;
	int count=0;
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]==' ')
		{
			flag=0;
		}
		else
		{
			if(flag!=1)
				count++;
			flag=1;
		}
	}
	return count;
}