/*�ļ�����1527403034_E80.c
*���ߣ�����
*ʱ�䣺2016��1��19��
*���ܣ�
*��ע��
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
���ܣ���ȡ���ݵ�����
������char *addr
����ֵ��node *head
*/
node * ReadFile(char *addr);
/*
���ܣ��������
������node *head
����ֵ��int
*/
int PrintList(node * head);
/*
���ܣ�����������
������node *head
����ֵ��int
*/
int SortList(node * head);
/*
���ܣ�ɾ��ѧ��С��s1��ѧ��
������node *head
����ֵ��int
*/
int DeleteStudent(node * head,char *s1);
int main()
{
	node *head;
	char s1[100];
	//��ȡ�ļ�
	head=ReadFile("c:\\cdata\\E80_data.txt");
	printf("��ȡ�ļ������ݣ�\n");
	PrintList(head);
	//����
	SortList(head);
	printf("��ѧ������Ľ����\n");
	PrintList(head);
	//ɾ��
	printf("������ɾ��ѧ��С�ڶ��ٵ�ѧ��\n");
	scanf("%s", s1);
	DeleteStudent(head,s1);
	printf("ɾ������Ϊ��\n");
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
		printf("�ļ���ʧ��\n");
		return NULL;
	}
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("����ͷָ��ʧ��\n");
		return NULL;
	}
	head->next = NULL;
	cur = head;
	while (fscanf(fin,"%s%s%d",temp.num,temp.name,&temp.grade)!=EOF)
	{
		//����
		newnode = (node *)malloc(sizeof(node));
		newnode->data = temp;
		newnode->next = NULL;
		cur->next = newnode;
		cur = cur->next;
	}
	//�ر��ļ�
	fclose(fin);
	return head;
}

int PrintList(node * head)
{
	node *cur = head->next;
	while (cur!=NULL)
	{
		printf("ѧ�ţ�%15s������%15s�꼶��%5d\n",cur->data.num,cur->data.name,cur->data.grade);
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
			//ɾ��
			nextnode = cur->next;
			cur->next = cur->next->next;
			free(nextnode);
			continue;
		}
		cur = cur->next;
	}
	return 0;
}
