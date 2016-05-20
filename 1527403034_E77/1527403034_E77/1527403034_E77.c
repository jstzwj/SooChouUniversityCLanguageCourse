/*文件名：1527403034_E77.c
*作者：王俊
*时间：2016年1月16日
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
功能：读取文件写入链表
参数：char *adr
返回值：node * head
*/
node * ReadToList(char *adr);
/*
功能：对链表进行排序
参数：node *head
返回值：int
*/
int ListSort(node *head);
/*
功能：将链表写入文件
参数：node *head
	char * adr
返回值：int 
*/
int ListToFile(node *head, char *adr);
/*
功能：销毁链表
参数：node *head
返回值：int
*/
int DestroyList(node *head);
int main()
{
	node *head=NULL;
	//读取文件
	printf("读取文件建立链表中\n");
	head=ReadToList("c:\\cdata\\E77_data.txt");
	if (head == NULL)
	{
		return 0;
	}
	//排序
	printf("排序中\n");
	ListSort(head);
	//写入文件
	printf("写入文件中\n");
	ListToFile(head,"c:\\cdata\\E77_result.txt");
	//销毁链表
	printf("销毁链表中\n");
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
	//判断是否失败
	if (fin==NULL)
	{
		printf("文件打开失败！\n");
		return NULL;
	}
	//分配链表头节点
	head = (node *)malloc(sizeof(node));
	//判断分配是否成功
	if (head == NULL)
	{
		printf("头节点分配失败\n");
		return NULL;
	}
	cur = head;
	head->num = 0;
	head->next = NULL;
	//写入链表
	while (fscanf(fin,"%d",&temp.num)!=EOF)
	{
		newnode = (node*)malloc(sizeof(node));
		//判断分配是否成功
		if (newnode == NULL)
		{
			printf("节点分配失败\n");
			fclose(fin);
			return NULL;
		}
		*newnode = temp;
		cur->next = newnode;
		newnode->next = NULL;
		cur = cur->next;
	}
	//关闭文件
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
		//交换
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
	//打开文件
	fin = fopen(adr,"w");
	if (fin == NULL)
	{
		printf("文件写入失败！\n");
		return 1;
	}
	//输入数据
	while (cur != NULL)
	{
		fprintf(fin,"%d\n",cur->num);
		cur = cur->next;
	}
	//关闭文件
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
