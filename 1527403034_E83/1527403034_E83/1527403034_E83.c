/*�ļ�����1527403034_E83.c
*���ߣ�����
*ʱ�䣺2016��1��21��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
struct _student
{
	char ID[15];
	char name[20];
	int grade;
	int scores[3];
};
typedef struct _student student;
typedef struct Node
{
	student data;
	struct Node*next;
}node;
/*
���ܣ���ȡ�ļ�
������char *addr
����ֵ��node *
*/
node *ReadFile(char *addr);
/*
���ܣ����ѧ����Ϣ
������node *head
����ֵ��int
*/
int PrintList(node *head);
/*
���ܣ���ƽ���ɼ��Ӵ�С����
������node *head
����ֵ��int
*/
int SortList(node *head);
/*
���ܣ�������������ļ�
������node *head
char *addr
����ֵ��int
*/
int WriteToFile(node *head,char *addr);
/*
���ܣ�ɾ��ƽ���ɼ�С��score��ѧ��
������node *head
double score
����ֵ��int
*/
int DeleteStudent(node *head,double score);
/*
���ܣ���������
������node *head
����ֵ��int
*/
int DestroyList(node *head);
int main()
{
	node *head;
	head=ReadFile("c:\\cdata\\E83_data.bin");
	printf("ԭ����\n");
	PrintList(head);
	SortList(head);
	printf("���������\n");
	PrintList(head);
	DeleteStudent(head,40);
	printf("ɾ�����ֺ������\n");
	PrintList(head);
	WriteToFile(head, "c:\\cdata\\E83_delresult.txt");
	printf("�Ѿ�ɾ��С����ʮ�ֵ�ѧ������������ļ�\n");
	DestroyList(head);
	system("pause");
	return 0;
}

node * ReadFile(char * addr)
{
	FILE *fin;
	node *head;
	node *cur;
	int len;
	int i;
	fin = fopen(addr, "rb");
	if (fin == NULL)
	{
		printf("�ļ���ʧ��\n");
		return NULL;
	}
	//����ͷ�ڵ�
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("ͷ�ڵ����ʧ��\n");
		return NULL;
	}
	//��ʼ��ͷ�ڵ�
	head->next = NULL;
	//�����ļ�����
	fseek(fin, 0, SEEK_END);
	len=ftell(fin);
	fseek(fin, 0, SEEK_SET);
	cur = head;
	for (i = 0; i < len / sizeof(student); i++)
	{
		cur->next = (node *)malloc(sizeof(node));
		if (cur->next==NULL)
		{
			printf("�ڵ��½�ʧ��\n");
			return NULL;
		}
		cur = cur->next;
		cur->next = NULL;
		fread(&(cur->data), sizeof(student), 1, fin);
	}
	fclose(fin);
	return head;
}

int PrintList(node * head)
{
	node *cur = head->next;
	printf("%-20s%-25s%-3s%-6s%-6s%-6s\n","ѧ��","����","�꼶","�ɼ�һ","�ɼ���","�ɼ���");
	while (cur!=NULL)
	{
		printf("%-20s%-25s%-3d%6d%6d%6d\n",cur->data.ID,cur->data.name,cur->data.grade,cur->data.scores[0], cur->data.scores[1], cur->data.scores[2]);
		cur = cur->next;
	}
	return 0;
}

double GetAverage(student data)
{
	return (data.scores[0] + data.scores[1] + data.scores[2]) / 3;
}
int SortList(node * head)
{
	node *i, *j;
	node *max;
	student temp;
	i = head->next;
	while (i->next != NULL)
	{
		j = i;
		max = i;
		while (j != NULL)
		{
			if (GetAverage(j->data) > GetAverage(max->data))
			{
				max = j;
			}
			j = j->next;
		}
		temp = i->data;
		i->data = max->data;
		max->data = temp;
		i = i->next;
	}

	return 0;
}

int WriteToFile(node * head,char *addr)
{
	FILE *fout;
	node *cur = head;
	fout = fopen(addr,"w");
	if(fout==NULL)
	{
		printf("�ļ���ʧ��\n");
		return 1;
	}
	//fprintf(fout,"%-20s%-25s%-3s%-6s%-6s%-6s\n", "ѧ��", "����", "�꼶", "�ɼ�һ", "�ɼ���", "�ɼ���");
	while (cur != NULL)
	{
		fprintf(fout,"%-20s%-25s%-3d%6d%6d%6d\n", cur->data.ID, cur->data.name, cur->data.grade, cur->data.scores[0], cur->data.scores[1], cur->data.scores[2]);
		cur = cur->next;
	}
	fclose(fout);
	return 0;
}

int DeleteStudent(node * head, double score)
{
	node *cur = head;
	node *temp;
	while (cur->next!=NULL)
	{
		if (GetAverage(cur->next->data) < score)
		{
			temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
			continue;
		}
		cur = cur->next;
	}
	return 0;
}

int DestroyList(node * head)
{
	node *temp;
	while (head!=NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return 0;
}
