/*�ļ�����1527403034_E31.c
*���ߣ�����
*ʱ�䣺2015��11��19��
*���ܣ���֪�������� int arry[]={12, 23, 34, 56, 78,98,256,789}�Ӽ�������һ�����������ö��ֲ��ҷ����������ҳ�������
���������±��������Ļ�ϣ����������û�и���������� ���޴����� ����
*��ע��
*/
#include<stdio.h>
int main()
{
	int arry[]={12, 23, 34, 56, 78,98,256,789};
	int num;
	int len=8;
	int start,end,index;

	start=0;
	end=len-1;
	index=len/2;

	//����
	printf("������һ������:\n");
	scanf("%d",&num);

	//���ַ�����
	while(start!=end)
	{
		if(num>arry[index])
		{
			start=index+1;
			index=(start+end)/2;
		}
		else if(num<arry[index])
		{
			end=index-1;
			index=(start+end)/2;
		}
		else
		{
			printf("�д��������±�Ϊ%d\n",index);
			break;
		}
	}
	//���������
	if(start==end)
	{
		printf("�����ڴ�������\n");
	}
	return 0;
}