/*�ļ�����1527403034_E65.c
*���ߣ�����
*ʱ�䣺2015��12��23��
*���ܣ�
*��ע��
*/
#include<stdio.h>
/*
���ܣ��������ַ����������ܹ��ɵ������������С����
������char str[]
	int* max
	int* min
����ֵ����
*/
void MaxMin(char str[], int* max, int* min)
{
	int num[6];
	int num2[6];
	int temp;
	int len;
	int i,j;

	for (i = 0; str[i] != 0;i++)
	{
		num[i] = str[i] - '0';
	}
	len = i;
	//�ݴ�
	for (i = 0; i < len; i++)
	{
		num2[i] = num[i];
	}
	//����
	for (i = 0; i < len; i++)
	{
		for (j = len - 1; j >i; j--)
		{
			if (num2[j] > num2[j - 1])
			{
				temp=num2[j];
				num2[j] = num2[j - 1];
				num2[j - 1] = temp;
			}
		}
	}
	//�����
	for (i = 0; i < len; i++)
	{
		*max = (*max) * 10 + num2[i];
	}
	//��Сֵ
	*min = num[0];
	for (i = 0; i < len; i++)
	{
		if (num[i] < *min)
		{
			*min = num[i];
		}
	}
}
int main()
{
	char str[6];
	int max=0;
	int min=0;
	//����
	printf("������һ���ַ���\n");
	gets(str);
	//����
	MaxMin(str,&max,&min);
	//���
	printf("���ֵΪ��\n%d\n",max);
	printf("��СֵΪ��\n%d\n", min);
	return 0;
}