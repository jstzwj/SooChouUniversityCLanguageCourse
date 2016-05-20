/*文件名：1527403034_E75.c
*作者：王俊
*时间：2016年1月4日
*功能：
*备注：
*/
#define LISTSIZE 50
typedef struct Item
{
	char name[20];
	char tel[15];
	char mobile[15];
	char postcode[10];
	char address[50];
}item;

typedef struct Node
{
	item data;
	struct Node * next;
}node;

#include<stdio.h>
#include<string.h>
/*功能:创建通讯录
参数：无
返回值：node *
*/
node * CreateList();

/*功能：通讯录录入
参数：node * head
返回值：int 
*/
int WriteIn(node *head);

/*功能：通讯录删除
参数：node * head
返回值：int
*/
int Delete(node * head);
/*功能：通讯录输出
参数：node * head
返回值：int
*/
int PrintfAll(node * head);
/*功能：通讯录修改
参数：node * head
返回值：int
*/
int Change(node * head);
/*功能：通讯录查询
参数：node * head
返回值：int
*/
int Search(node * head);
int main()
{
	node *head = NULL;
	int cho;
	head = CreateList();
	while (1)
	{
		//开始
		printf("通讯录\n");
		printf("1.输入\n");
		printf("2.删除\n");
		printf("3.修改\n");
		printf("4.查询\n");
		printf("5.退出\n");
		printf("请选择操作：\n");
		scanf("%d",&cho);
		switch (cho)
		{
			case 1:
				WriteIn(head);
				break;
			case 2:
				Delete(head);
				break;
			case 3:
				Change(head);
				break;
			case 4:
				Search(head);
				break;
			case 5:
				return 0;
				break;
			default:
				printf("不存在此选项！\n");
				break;
		}
		printf("----------以下是通讯录全部内容：----------\n");
		PrintfAll(head);
		system("pause");
		system("cls");
	}
	
	return 0;
}

node * CreateList()
{
	node * head;
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("头指针空间分配失败！\n");
		return 1;
	}
	head->next = NULL;
	return head;
}

int WriteIn(node *head)
{
	node *current=head;
	node *newnode=NULL;

	newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL)
	{
		printf("增加链表失败！\n");
		return 1;
	}
	newnode->next = NULL;
	//接上链表
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	//输入
	printf("开始录入数据：\n");
	printf("请输入名字：\n");
	scanf("%s",newnode->data.name);
	printf("请输入电话号码：\n");
	scanf("%s", newnode->data.tel);
	printf("请输入移动电话号码：\n");
	scanf("%s", newnode->data.mobile);
	printf("请输入邮编：\n");
	scanf("%s", newnode->data.postcode);
	printf("请输入通讯地址信息：\n");
	scanf("%s", newnode->data.address);
	return 0;
}

int Delete(node * head)
{
	node temp;
	node * current=head->next;
	node * last = head;

	//输入
	printf("请输入要删除的条目的名字\n");
	scanf("%s",temp.data.name);
	//搜索
	while (current!=NULL)
	{
		if (strcmp(current->data.name,temp.data.name)==0)
		{
			break;
		}
		current=current->next;
		last = last->next;
	}
	if (current == NULL)
	{
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//删除
		last->next = current->next;
		free(current);
		current = last->next;
	}
	return 0;
}

int PrintfAll(node * head)
{
	node * current = head->next;
	int i=0;
	while (current!=NULL)
	{
		printf("第%d条:\n",i+1);
		printf("人名：%s\n电话号码：%s\n移动电话：%s\n邮编：%s\n通讯地址：%s\n"
			, current->data.name
			, current->data.tel
			, current->data.mobile
			, current->data.postcode
			, current->data.address);
		current = current->next;
		i++;
	}
	return 0;
}

int Change(node * head)
{
	node temp;
	node * current = head;

	//输入
	printf("请输入要修改的条目的名字\n");
	scanf("%s", temp.data.name);
	//搜索
	while (current != NULL)
	{
		if (strcmp(current->data.name, temp.data.name) == 0)
		{
			break;
		}
		current = current->next;
	}
	if (current == NULL)
	{
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//修改
		printf("请重新输入数据：\n");
		printf("开始录入数据：\n");
		printf("请输入名字：\n");
		scanf("%s", current->data.name);
		printf("请输入电话号码：\n");
		scanf("%s", current->data.tel);
		printf("请输入移动电话号码：\n");
		scanf("%s", current->data.mobile);
		printf("请输入邮编：\n");
		scanf("%s", current->data.postcode);
		printf("请输入通讯地址信息：\n");
		scanf("%s", current->data.address);
	}
	return 0;
}

int Search(node * head)
{
	node temp;
	node * current = head;
	int i = 0;
	//输入
	printf("请输入要查询的条目的名字\n");
	scanf("%s", temp.data.name);
	//搜索
	while (current != NULL)
	{
		if (strcmp(current->data.name, temp.data.name) == 0)
		{
			break;
		}
		current = current->next;
		i++;
	}
	if (current == NULL)
	{
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//输出
		printf("第%d条:\n", i + 1);
		printf("人名：%s\n电话号码：%s\n移动电话：%s\n邮编：%s\n通讯地址：%s\n"
			, current->data.name
			, current->data.tel
			, current->data.mobile
			, current->data.postcode
			, current->data.address);
	}
	return 0;
}
