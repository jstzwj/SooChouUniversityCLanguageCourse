/*�ļ�����1527403034_E32.c
*���ߣ�����
*ʱ�䣺2015��11��19��
*���ܣ���֪int arry[]={12, 23, 34, 56, 78,98,256,789}�����д�����ڲ�ʹ����������������������������Ԫ�ء�
*��ע��
*/
#include<stdio.h>
#define N 8
int main()
{
	int arry[]={12, 23, 34, 56, 78,98,256,789};
	int i;
	int m,n;
	//��ʼ��
	m=0;
	n=N-1;
	//����
	while((m!=n)&&(n-m!=1))
	{
		i=arry[m];
		arry[m]=arry[n];
		arry[n]=i;

		m++;
		n--;
	}
	//���
	printf("������Ϊ��\n");
	for(i=0;i<N;i++)
	{
		
		printf("%-4d",arry[i]);
	}
	printf("\n");
	return 0;
}