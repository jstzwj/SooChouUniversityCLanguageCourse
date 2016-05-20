/*�ļ�����1527403034_E81.c
*���ߣ�����
*ʱ�䣺2016��1��20��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#define LEN 20
/*
���ܣ���ȡ��������
������char *addr
	int arry[]
	int len
����ֵ��int
*/
int ReadNum(char *addr,int arry[],int len);
/*
���ܣ�������������
������
	int arry[]
	int len
����ֵ��int
*/
int SortNum( int arry[], int len);
/*
���ܣ������������
������
int arry[]
int len
����ֵ��int
*/
int WriteNum(char *addr, int arry[], int len);
int main()
{
	int arry[LEN];
	//��ȡ
	printf("��ȡ��\n");
	ReadNum("c:\\cdata\\E81_data.bin", arry, LEN);
	//����
	printf("������\n");
	SortNum(arry, LEN);
	//���
	printf("�����\n");
	WriteNum("c:\\cdata\\E81_result.txt", arry, LEN);
	return 0;
}

int ReadNum(char * addr, int arry[], int len)
{
	FILE * fin=NULL;
	int i=0;
	fin = fopen(addr, "rb");
	if (fin == NULL)
	{
		printf("�ļ���ȡʧ�ܣ�\n");
		return 1;
	}
	fread(arry, sizeof(int), len, fin);
	fclose(fin);
	return 0;
}

int SortNum(int arry[], int len)
{
	int i, j;
	int key;
	for (i = 1; i < len; i++)
	{
		key = arry[i];
		j = i - 1;
		while (j>=0&&arry[j]>key)
		{
			arry[j+1] = arry[j];
			j--;
		}
		arry[j + 1] = key;
	}
	return 0;
}

int WriteNum(char * addr, int arry[], int len)
{
	FILE * fout = NULL;
	int i = 0;
	fout = fopen(addr, "w");
	if (fout == NULL)
	{
		printf("�ļ���ȡʧ�ܣ�\n");
		return 1;
	}
	for (i = 0; i < len;i++)
	{
		fprintf(fout, "%d\n", arry[i]);
	}
	fclose(fout);
	return 0;
}
