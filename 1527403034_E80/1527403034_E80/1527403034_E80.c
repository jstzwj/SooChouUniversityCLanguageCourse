/*文件名：1527403034_E80.c
*作者：王俊
*时间：2016年1月19日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
	char num[15];
	char name[20];
	int grade;
}student;
typedef struct Node
{
	student data;
	struct Node *next;
}node;
/*
功能：读取数据到链表
参数：char *addr
返回值：node *head
*/
node * ReadFile(char *addr);
/*
功能：输出链表
参数：node *head
返回值：int
*/
int PrintList(node * head);
/*
功能：对链表排序
参数：node *head
返回值：int
*/
int SortList(node * head);
/*
功能：删除学号小于s1的学生
参数：node *head
返回值：int
*/
int DeleteStudent(node * head,char *s1);
int main()
{
	node *head;
	char s1[100];
	//读取文件
	head=ReadFile("c:\\cdata\\E80_data.txt");
	printf("读取文件的数据：\n");
	PrintList(head);
	//排序
	SortList(head);
	printf("按学号排序的结果：\n");
	PrintList(head);
	//删除
	printf("请输入删除学号小于多少的学生\n");
	scanf("%s", s1);
	DeleteStudent(head,s1);
	printf("删除后结果为：\n");
	PrintList(head);
	system("pause");
	return 0;
}

node * ReadFile(char * addr)
{
	node * head;
	node * cur;
	node * newnode;
	student temp;
	FILE * fin;
	fin = fopen(addr,"r");
	if (fin==NULL)
	{
		printf("文件打开失败\n");
		return NULL;
	}
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("分配头指针失败\n");
		return NULL;
	}
	head->next = NULL;
	cur = head;
	while (fscanf(fin,"%s%s%d",temp.num,temp.name,&temp.grade)!=EOF)
	{
		//分配
		newnode = (node *)malloc(sizeof(node));
		newnode->data = temp;
		newnode->next = NULL;
		cur->next = newnode;
		cur = cur->next;
	}
	//关闭文件
	fclose(fin);
	return head;
}

int PrintList(node * head)
{
	node *cur = head->next;
	while (cur!=NULL)
	{
		printf("学号：%15s姓名：%15s年级：%5d\n",cur->data.num,cur->data.name,cur->data.grade);
		cur = cur->next;
	}
	return 0;
}

int SortList(node * head)
{
	node * i=head->next;
	node * j;
	node * min;
	student temp;
	i = head->next;
	while (i->next!=NULL)
	{
		j = i;
		min=i;
		while (j!=NULL)
		{
			if (atoi(min->data.num)>atoi(j->data.num))
			{
				min=j;
			}
			j = j->next;
		}
		temp = min->data;
		min->data = i->data;
		i->data = temp;
		i = i->next;
	}
	return 0;
}

int DeleteStudent(node * head, char * s1)
{
	node * cur=head;
	node * nextnode;
	student temp;
	while (cur ->next!= NULL)
	{
		if (atoi(cur->next->data.num) < atoi(s1))
		{
			//删除
			nextnode = cur->next;
			cur->next = cur->next->next;
			free(nextnode);
			continue;
		}
		cur = cur->next;
	}
	return 0;
}
