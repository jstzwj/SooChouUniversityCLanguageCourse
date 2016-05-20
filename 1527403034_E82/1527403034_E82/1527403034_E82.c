/*文件名：1527403034_E82.c
*作者：王俊
*时间：2016年1月20日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int num;
	struct Node *next;
}node;
/*
功能：从文件读整数到链表
参数：char * addr
返回值：node *head
*/
node * ReadToList(char *addr);
/*
功能：排序整数
参数：node * head
返回值：int
*/
int SortList(node*head);
/*
功能：将链表输出到文件
参数：char * addr
	node * head
返回值：int
*/
int WriteToFile(char *addr,node *head);
/*
功能：删除第k个整数，返回最终整数
参数：node *head
返回值：int
*/
int GetNum(node *head,int k);
int main()
{
	node *head;
	int k;
	head = ReadToList("c:\\cdata\\E82_data.bin");
	SortList(head);
	WriteToFile("c:\\cdata\\E82_result.txt", head);
	printf("已排序后输出到文件\n");
	printf("请输入隔多少个数字删除一个数：\n");
	scanf("%d", &k);
	printf("经过题目中操作后得到的数为%d\n",GetNum(head,k));
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
		printf("文件打开失败\n");
		return 1;
	}
	fseek(fin,0,SEEK_END);
	len=ftell(fin);
	fseek(fin, 0, SEEK_SET);
	head = (node *)malloc(sizeof(node));
	if (head==NULL)
	{
		printf("头节点分配失败！\n");
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
			printf("节点分配失败！\n");
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
		printf("文件打开失败\n");
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
