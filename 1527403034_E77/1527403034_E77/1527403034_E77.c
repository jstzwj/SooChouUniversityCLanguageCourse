/*�ļ�����1527403034_E77.c
*���ߣ�����
*ʱ�䣺2016��1��16��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int num;
	struct Node *next;
}node;
/*
���ܣ���ȡ�ļ�д������
������char *adr
����ֵ��node * head
*/
node * ReadToList(char *adr);
/*
���ܣ��������������
������node *head
����ֵ��int
*/
int ListSort(node *head);
/*
���ܣ�������д���ļ�
������node *head
	char * adr
����ֵ��int 
*/
int ListToFile(node *head, char *adr);
/*
���ܣ���������
������node *head
����ֵ��int
*/
int DestroyList(node *head);
int main()
{
	node *head=NULL;
	//��ȡ�ļ�
	printf("��ȡ�ļ�����������\n");
	head=ReadToList("c:\\cdata\\E77_data.txt");
	if (head == NULL)
	{
		return 0;
	}
	//����
	printf("������\n");
	ListSort(head);
	//д���ļ�
	printf("д���ļ���\n");
	ListToFile(head,"c:\\cdata\\E77_result.txt");
	//��������
	printf("����������\n");
	DestroyList(head);
	return 0;
}

node * ReadToList(char * adr)
{
	FILE * fin=NULL;
	node *head = NULL;
	node *cur=head;
	node *newnode = NULL;
	node temp;
	fin = fopen(adr,"r");
	//�ж��Ƿ�ʧ��
	if (fin==NULL)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return NULL;
	}
	//��������ͷ�ڵ�
	head = (node *)malloc(sizeof(node));
	//�жϷ����Ƿ�ɹ�
	if (head == NULL)
	{
		printf("ͷ�ڵ����ʧ��\n");
		return NULL;
	}
	cur = head;
	head->num = 0;
	head->next = NULL;
	//д������
	while (fscanf(fin,"%d",&temp.num)!=EOF)
	{
		newnode = (node*)malloc(sizeof(node));
		//�жϷ����Ƿ�ɹ�
		if (newnode == NULL)
		{
			printf("�ڵ����ʧ��\n");
			fclose(fin);
			return NULL;
		}
		*newnode = temp;
		cur->next = newnode;
		newnode->next = NULL;
		cur = cur->next;
	}
	//�ر��ļ�
	fclose(fin);
	return head;
}

int ListSort(node * head)
{
	node * p1=head;
	node * p2 = NULL;
	node *min = NULL;
	int temp;
	while (p1->next!=NULL)
	{
		p2 = p1->next;
		min = p2;
		while (p2 != NULL)
		{
			if (min->num > p2->num)
			{
				min = p2;
			}
			p2 = p2->next;
		}
		//����
		p1 = p1->next;
		temp = min->num;
		min->num = p1->num;
		p1->num = temp;
	}
	return 0;
}

int ListToFile(node * head, char * adr)
{
	node *cur=head->next;
	FILE *fin = NULL;
	//���ļ�
	fin = fopen(adr,"w");
	if (fin == NULL)
	{
		printf("�ļ�д��ʧ�ܣ�\n");
		return 1;
	}
	//��������
	while (cur != NULL)
	{
		fprintf(fin,"%d\n",cur->num);
		cur = cur->next;
	}
	//�ر��ļ�
	fclose(fin);
	return 0;
}

int DestroyList(node * head)
{
	node *cur=head;
	node *nextnode;
	while (cur != NULL)
	{
		nextnode = cur->next;
		free(cur);
		cur = nextnode;
	}
	return 0;
}
