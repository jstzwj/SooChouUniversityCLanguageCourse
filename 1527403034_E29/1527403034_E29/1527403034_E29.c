/*�ļ�����1527403034_E29.c
*���ߣ�����
*ʱ�䣺2015��11��16��
*���ܣ���֪int arry[10]={13,24,35,46,57,68,79,88,93} ���뽫�û������һ�����ְ��մ�С����˳����ڶ�Ӧλ�ú������.
*��ע��
*/
#include<stdio.h>
int main()
{
	int temp,i,j;
	int arry[10]={13,24,35,46,57,68,79,88,93} ;
	//����
	printf("������һ������\n");
	scanf("%d",&temp);
	//����
	for(i=0;i<=8;i++)
	{
		if(temp<arry[i])
		{
			for(j=8;j>=i;j--)
			{
				arry[j+1]=arry[j];
			}
			arry[i]=temp;
			break;
		}
	}
	//���
	for(i=0;i<=9;i++)
	{
		printf("%-5d",arry[i]);
	}
	printf("\n");
	return 0;
}