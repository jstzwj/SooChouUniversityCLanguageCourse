/*文件名：1527403034_E73.c
*作者：王俊
*时间：2016年1月2日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int num;
	struct Node* next;
};
typedef struct Node node;

/*功能：创建链表
参数：无
返回值：node*
*/
node * CreateList();

/*功能：销毁链表
参数：node * head 链表头指针
返回值：int
*/
int DestroyList(node * head);

/*
功能：输出链表中所有的整数
参数：int n		每个整数占n列
int k	每行k个整数
返回值：int
*/
int PrintAllList(node *head, int k, int n);

/*
功能：删除所有偶数结点
参数：node * head
返回值：node *head
*/
node * DelEvenList(node *head);


/*
功能：删除所有链表值为n的结点
参数：node * head
返回值：int 若为-1则删除不成功
*/
int DelNList(node *head,int n);

int main()
{
	node *head;
	int k, n;
	int num;
	//创建链表
	head = CreateList();
	if (head == NULL)
	{
		return 1;
	}
	//输出链表
	printf("请输入每行输出的整数数目k与整数所占的列数\n");
	scanf("%d%d",&k,&n);
	printf("原链表为\n");
	PrintAllList(head,k,n);
	printf("\n");
	//system("pause");
	//删除偶数
	DelEvenList(head);
	//输出链表
	printf("删除偶数后为\n");
	PrintAllList(head, k, n);
	printf("\n");
	//system("pause");
	//删除
	printf("请输入需要删除的数字：\n");
	scanf("%d",&num);
	if (DelNList(head, num) == -1)
	{
		printf("删除失败\n");
	}
	//输出链表
	printf("删除后为\n");
	PrintAllList(head, k, n);
	printf("\n");
	//system("pause");
	//销毁链表
	DestroyList(head);
	return 0;
}

node * CreateList()
{
	node *head;
	node *current;
	node *newnode;
	int i;
	//创建链表
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("链表头创建失败\n");
		return NULL;
	}
	head->num = 0;
	head->next = NULL;
	//赋初始值
	i = 1;
	current = head;
	while (i * 3 < 100)
	{
		newnode = (node *)malloc(sizeof(node));
		if (newnode == NULL)
		{
			printf("链表节点创建失败\n");
			return NULL;
		}
		current->next = newnode;
		newnode->num = i * 3;
		//递增
		current = current->next;
		i = i + 1;
	}
	current->next = NULL;
	return head;
}

int DestroyList(node * head)
{
	node *current;
	node * temp;
	current = head;
	while (current->next != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	return 0;
}

int PrintAllList(node *head, int k, int n)
{
	node *current;
	char str[50];
	int i = 0;
	//控制输出
	sprintf(str, "%%%dd", n);
	current = head->next;
	while (current->next != NULL)
	{
		printf(str, current->num);
		if ((i + 1) % k == 0)
		{
			printf("\n");
		}
		i++;
		current = current->next;
	}
	printf(str, current->num);
	return 0;
}

node * DelEvenList(node * head)
{
	node * current;
	node * last;
	node * temp;
	current = head;
	last = head;
	if (current->next != NULL)
	{
		current = current->next;
	}
	else 
	{
		return 0;
	}
	while (current->next != NULL)
	{
		//删除
		if (current->num%2==0)
		{
			temp = current->next;
			last->next = current->next;
			free(current);
			current = temp;
			continue;
		}
		current = current->next;
		last = last->next;
	}
	//删除
	if (current->num % 2 == 0)
	{
		last->next = NULL;
	}
	return head;
}

int DelNList(node * head,int n)
{
	node * current;
	node * last;
	node * temp;
	current = head;
	last = head;
	if (current->next != NULL)
	{
		current = current->next;
	}
	else
	{
		return 0;
	}
	while (current->next != NULL)
	{
		//删除
		if (current->num == n)
		{
			temp = current->next;
			last->next = current->next;
			free(current);
			current = temp;
			//返回
			return 0;
		}
		current = current->next;
		last = last->next;
	}
	//删除
	if (current->num == n)
	{
		last->next = NULL;
		return 0;
	}
	return -1;
}
