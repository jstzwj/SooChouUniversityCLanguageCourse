/*�ļ�����1527403034_E04.c
*���ߣ�����
*ʱ�䣺2015��10��16��
*���ܣ���д��������û������һ�� 3 λ�������� 3 �����ֵĺ�
*��ע��
*/
#include<stdio.h>
int main()
{
	int a,b,c;
	int number;
	int sum;
	//����3λ����
	printf("������3λ��������\n");
	scanf("%d",&number);
	a=number%10;
	b=(number/10)%10;
	c=number/100;
	sum=a+b+c;
	printf("��λ����λ��Ϊ%d\n",sum);
	return 0;
}