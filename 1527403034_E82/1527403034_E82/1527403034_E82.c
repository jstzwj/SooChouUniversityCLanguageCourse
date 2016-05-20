/*�ļ�����1527403034_E82.c
*���ߣ�����
*ʱ�䣺2016��1��20��
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
���ܣ����ļ�������������
������char * addr
����ֵ��node *head
*/
node * ReadToList(char *addr);
/*
���ܣ���������
������node * head
����ֵ��int
*/
int SortList(node*head);
/*
���ܣ�������������ļ�
������char * addr
	node * head
����ֵ��int
*/
int WriteToFile(char *addr,node *head);
/*
���ܣ�ɾ����k��������������������
������node *head
����ֵ��int
*/
int GetNum(node *head,int k);
int main()
{
	node *head;
	int k;
	head = ReadToList("c:\\cdata\\E82_data.bin");
	SortList(head);
	WriteToFile("c:\\cdata\\E82_result.txt", head);
	printf("�������������ļ�\n");
	printf("����������ٸ�����ɾ��һ������\n");
	scanf("%d", &k);
	printf("������Ŀ�в�����õ�����Ϊ%d\n",GetNum(head,k));
	system("pause");
	return 0;
}

node * ReadToList(char * addr)
{
	FILE *fin;
	node *head;
	node *cur;
	int len;
	int i;

	fin = fopen(addr,"rb");
	if (fin==NULL)
	{
		printf("�ļ���ʧ��\n");
		return 1;
	}
	fseek(fin,0,SEEK_END);
	len=ftell(fin);
	fseek(fin, 0, SEEK_SET);
	head = (node *)malloc(sizeof(node));
	if (head==NULL)
	{
		printf("ͷ�ڵ����ʧ�ܣ�\n");
		fclose(fin);
		return NULL;
	}
	head->next = NULL;
	cur = head;
	for (i = 0; i < len / sizeof(int); i++)
	{
		cur->next = (node *)malloc(sizeof(node));
		if (cur->next==NULL)
		{
			printf("�ڵ����ʧ�ܣ�\n");
			fclose(fin);
			return NULL;
		}
		cur = cur->next;
		cur->next = NULL;
		fread(&cur->num,sizeof(int),1,fin);
	}
	fclose(fin);
	return head;
}

int SortList(node * head)
{
	node * i;
	node * j;
	node *key;
	int temp;
	i = head->next;
	while (i->next!=NULL)
	{
		j = i;
		key = i;
		while (j!=NULL)
		{
			if (key->num>j->num)
			{
				key = j;
			}
			j = j->next;
		}
		temp = key->num;
		key->num = i->num;
		i->num = temp;
		i = i->next;
	}
	return 0;
}

int WriteToFile(char * addr, node * head)
{
	node * cur=head->next;
	FILE *fout;
	fout = fopen(addr, "w");
	if (fout == NULL)
	{
		printf("�ļ���ʧ��\n");
		return 1;
	}
	while (cur!=NULL)
	{
		fprintf(fout, "%d\n", cur->num);
		cur = cur->next;
	}
	fclose(fout);
	return 0;
}

int GetNum(node * head,int k)
{
	int i = 1;
	node *cur = head;
	node *temp;
	while (!(cur->next->next==NULL&&cur==head))
	{
		while (i<k)
		{
			if (cur->next->next == NULL)
			{
				cur = head;
			}
			else
			{
				cur = cur->next;
			}
			i++;
		}
		temp = cur->next;
		cur->next = cur->next->next;
		free(temp);
	}
	i = (cur->next)->num;
	free(head);
	return i;
}
