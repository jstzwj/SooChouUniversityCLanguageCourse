/*�ļ�����1527403034_E39.c
*���ߣ�����
*ʱ�䣺2015��11��23��
*���ܣ��Ӽ�������һ���ַ����������ַ����������������磺�����ַ���Ϊ�� abcdefg�����������ַ���Ϊ�� gfedcba����
*��ע��
*/
#include<stdio.h>
#include<string.h>
#define N 11
int main()
{
	char str[N];
	int i;
	int temp;
	int len;
	//�����ַ���
	printf("������һ���ַ���:\n");
	gets(str);
	len=strlen(str);
	//����
	for(i=0;(i!=len-i-1)&&(i!=len-i);i++)
	{
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
	//���
	printf("����������Ϊ��\n");
	puts(str);
	return 0;
}