/*文件名：1527403034_E79.c
*作者：王俊
*时间：2016年1月18日
*功能：
*备注：
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
功能：从文件读取到数组
参数：char * addr
	student *des
	int limit
	int *top
返回值：int 0成功 1失败
*/
int ReadInfo(char * addr,student *des,int limit,int *top);
/*
功能：输出数据
参数：student * des
	int limit
	int *top
返回值：int 0成功 1失败
*/
int PrintInfo(student * des, int limit,int *top);
/*
功能：按学号排序信息
参数：student * des
	int limit
	int *top
返回值：int 0成功 1失败
*/
int SortNum(student * des, int limit,int *top);
/*
功能：删除学号小s1的值
参数：student * des
	int limit
	char * s1
	int *top
返回值：int 0成功 1失败
*/
int DeleteStudent(student * des, int limit,char *s1, int *top);
int main()
{
	student info[LIMIT];
	int top=0;
	char s1[100];
	//读取文件
	ReadInfo("c:\\cdata\\E79_data.txt",info,LIMIT,&top);
	printf("读取文件的数据：\n");
	PrintInfo(info,LIMIT,&top);
	//排序
	SortNum(info,LIMIT,&top);
	printf("按学号排序的结果：\n");
	PrintInfo(info, LIMIT, &top);
	//删除
	printf("请输入删除学号小于多少的学生\n");
	scanf("%s",s1);
	DeleteStudent(info, LIMIT, s1, &top);
	printf("删除后结果为：\n");
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
		printf("文件打开失败!\n");
		return 1;
	}
	while (fscanf(fout, "%s%s%d", des[i].num, des[i].name, &des[i].grade)!=EOF)
	{
		if (i >= limit)
		{
			printf("数据过多，内存已满\n");
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
		printf("数组已满！\n");
		return 1;
	}
	for (i = 0; i < *top;i++)
	{
		printf("学号：%15s姓名：%20s年级：%4i\n",des[i].num,des[i].name,des[i].grade);
	}
	return 0;
}

int SortNum(student * des, int limit, int *top)
{
	student temp;
	int i, j;
	if (*top >= limit)
	{
		printf("数组已满！\n");
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
		printf("数组已满！\n");
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
