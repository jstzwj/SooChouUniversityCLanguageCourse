/*�ļ�����1527403034_E55.c
*���ߣ�����
*ʱ�䣺2015��12��8��
*���ܣ���ʮ�����µĵ��ʽ����ֵ�����
*��ע��
*/
#include<stdio.h>
#include<string.h>
/*
	���ܣ��Ե��ʽ����ֵ�����
	������char str[];	�ַ���
	����ֵ����
*/
int DiractionarySort(char str[][10]);
int main()
{
	char str[12][10];
	int i;
	strcpy(str[0],"January");
	strcpy(str[1],"February");
	strcpy(str[2],"March");
	strcpy(str[3],"April");
	strcpy(str[4],"May");
	strcpy(str[5],"June");
	strcpy(str[6],"July");
	strcpy(str[7],"August");
	strcpy(str[8],"September");
	strcpy(str[9],"October");
	strcpy(str[10],"November");
	strcpy(str[11],"December");
	//�����ֵ�����
	DiractionarySort(str);
	//���
	for(i=0;i<12;i++)
	{
		puts(str[i]);
	}
	return 0;
}
int DiractionarySort(char str[][10])
{
	int i,j;
	char temp[11];
	for(i=0;i<12;i++)
	{
		for(j=10;j>=i;j--)
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[j+1]);
				strcpy(str[j+1],temp);
			}
		}
	}
	return 0;
}