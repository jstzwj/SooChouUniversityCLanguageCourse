/*�ļ�����1527403034_E76.c
*���ߣ�����
*ʱ�䣺2016��1��16��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
/*
���ܣ���һ���ı��ļ����Ƶ���һ��λ��
������char *from
	char * to
����ֵ��int
*/
int CopyFile(char *from,char *to)
{
	FILE *fin;
	FILE *fout;
	char temp;
	//���ļ�
	fin=fopen(from,"r");
	//������
	if (fin==NULL)
	{
		printf("���ļ���������\n");
		return 1;
	}
	fout = fopen(to,"w");
	//������
	if (fout == NULL)
	{
		printf("�����ļ���������\n");
		return 1;
	}
	//��������
	while ((temp=fgetc(fin))!=EOF)
	{
		fputc(temp,fout);
	}
	//�ر��ļ�
	fclose(fin);
	fclose(fout);
}


int main()
{
	//�����ļ�
	printf("��E76_data.txt���Ƶ�E76_result.txt\n");
	if (CopyFile("c:\\cdata\\E76_data.txt","c:\\cdata\\E76_result.txt")!=1)
	{
		printf("���Ƴɹ���\n");
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}
	system("pause");
	return 0;
}