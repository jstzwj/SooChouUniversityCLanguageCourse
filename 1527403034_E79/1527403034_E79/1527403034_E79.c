/*�ļ�����1527403034_E79.c
*���ߣ�����
*ʱ�䣺2016��1��18��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#define LIMIT 50
typedef struct Student
{
	char num[15];
	char name[20];
	int grade;
}student;
/*
���ܣ����ļ���ȡ������
������char * addr
	student *des
	int limit
	int *top
����ֵ��int 0�ɹ� 1ʧ��
*/
int ReadInfo(char * addr,student *des,int limit,int *top);
/*
���ܣ��������
������student * des
	int limit
	int *top
����ֵ��int 0�ɹ� 1ʧ��
*/
int PrintInfo(student * des, int limit,int *top);
/*
���ܣ���ѧ��������Ϣ
������student * des
	int limit
	int *top
����ֵ��int 0�ɹ� 1ʧ��
*/
int SortNum(student * des, int limit,int *top);
/*
���ܣ�ɾ��ѧ��Сs1��ֵ
������student * des
	int limit
	char * s1
	int *top
����ֵ��int 0�ɹ� 1ʧ��
*/
int DeleteStudent(student * des, int limit,char *s1, int *top);
int main()
{
	student info[LIMIT];
	int top=0;
	char s1[100];
	//��ȡ�ļ�
	ReadInfo("c:\\cdata\\E79_data.txt",info,LIMIT,&top);
	printf("��ȡ�ļ������ݣ�\n");
	PrintInfo(info,LIMIT,&top);
	//����
	SortNum(info,LIMIT,&top);
	printf("��ѧ������Ľ����\n");
	PrintInfo(info, LIMIT, &top);
	//ɾ��
	printf("������ɾ��ѧ��С�ڶ��ٵ�ѧ��\n");
	scanf("%s",s1);
	DeleteStudent(info, LIMIT, s1, &top);
	printf("ɾ������Ϊ��\n");
	PrintInfo(info, LIMIT, &top);
	system("pause");
	return 0;
}

int ReadInfo(char * addr, student * des, int limit, int *top)
{
	FILE * fout;
	int i = 0;
	fout=fopen(addr,"r");
	if (fout == NULL)
	{
		printf("�ļ���ʧ��!\n");
		return 1;
	}
	while (fscanf(fout, "%s%s%d", des[i].num, des[i].name, &des[i].grade)!=EOF)
	{
		if (i >= limit)
		{
			printf("���ݹ��࣬�ڴ�����\n");
			return 1;
		}
		i++;
		(*top)++;
	}
	fclose(fout);
	return 0;
}

int PrintInfo(student * des, int limit, int *top)
{
	int i = 0;
	if (*top >= limit)
	{
		printf("����������\n");
		return 1;
	}
	for (i = 0; i < *top;i++)
	{
		printf("ѧ�ţ�%15s������%20s�꼶��%4i\n",des[i].num,des[i].name,des[i].grade);
	}
	return 0;
}

int SortNum(student * des, int limit, int *top)
{
	student temp;
	int i, j;
	if (*top >= limit)
	{
		printf("����������\n");
		return 1;
	}
	for (i = 0; i < *top-1;i++)
	{
		for (j = *top - 1; j > i; j--)
		{
			if (atoi(des[j].num) < atoi(des[j - 1].num))
			{
				temp = des[j];
				des[j] = des[j - 1];
				des[j - 1] = temp;
			}
		}
	}
	return 0;
}

int DeleteStudent(student * des, int limit, char * s1, int *top)
{
	int i;
	int j;
	if (*top >= limit)
	{
		printf("����������\n");
		return 1;
	}
	for (i = 0; i < *top;i++)
	{
		if (atoi(des[i].num)<atoi(s1))
		{
			for (j = i + 1; j < *top;j++)
			{
				des[j - 1] = des[j];
			}
			(*top)--;
			i--;
		}
	}
	return 0;
}
