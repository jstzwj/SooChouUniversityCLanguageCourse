/*文件名：1527403034_E72.c
*作者：王俊
*时间：2016年1月1日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct Node
{
	int num;
	struct Node * next;
};
typedef struct Node node;
/*以下是链表基本功能函数*/
/*
	功能：新建链表
	参数：无
	返回值：node *
*/
node * NewList();

/*
功能：加长链表
参数：node *head	给哪个链表加长
	node nextnode	加入的节点
返回值：int *
*/
node * AddList(node * const head,node nextnode);

/*
功能：销毁链表
参数：node *	需要销毁的链表
返回值：int
*/
int DestroyList(node * head);

/*
功能：创建有n个随机值结点的链表
参数：int n
返回值：node *
*/
node * CreateNList(int n);

/*
功能：输出链表中所有的整数
参数：int n		每个整数占n列
int k	每行k个整数
返回值：int
*/
int PrintAllList(node *head,int k,int n);

/*
功能：对链表由小到大排序
参数：node * head
返回值：node * head
*/
node * SortList(node *head);


/*
功能：删除含数字3和5的节点
参数：node * head
返回值：node * head
*/
node * Del35List(node *head);

int main()
{
	node *head;
	node current;
	int n;
	int a, b;
	printf("请输入要随机生成多长的链表\n");
	scanf("%d",&n);
	printf("请输入每行输出的整数数目与整数占的列数\n");
	scanf("%d%d", &a,&b);
	//创建链表
	head=CreateNList(n);
	//链表创建失败检测
	if (head == NULL)
	{
		printf("链表创建失败\n");
		system("pause");
		return 1;
	}
	//输出链表
	printf("原链表为：\n");
	PrintAllList(head, a, b);
	printf("\n");
	//排序链表
	SortList(head);
	//输出链表
	printf("排序后链表为：\n");
	PrintAllList(head, a, b);
	printf("\n");
	//删除链表
	Del35List(head);
	//输出链表
	printf("删除3和5后链表为：\n");
	PrintAllList(head, a, b);
	printf("\n");
	//释放链表
	DestroyList(head);
	//system("pause");
	return 0;
}

node * NewList()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	//失败返回空指针
	if (head == NULL)
	{
		return NULL;
	}
	//给头节点赋初值
	head->num = 0;
	head->next = NULL;
	return head;
}

node * AddList(node * const head, node nextnode)
{
	node *current=head;
	node *temp;
	//找到末尾
	while (current!=NULL)
	{
		current = current->next;
	}
	//加长链表
	temp = (node *)malloc(sizeof(node));
	//失败处理
	if(temp==NULL)
	{
		printf("链表加长失败\n");
		return NULL;
	}
	//检测传入的对象是否指向NULL
	if (nextnode.next != NULL)
	{
		printf("此节点的next并不是NULL，已自动转换为NULL\n");
	}
	//复制对象
	temp->num = nextnode.num;
	temp->next = NULL;
	//加上去
	current->next = temp;
	return NULL;
}

int DestroyList(node * head)
{
	node * current = head;
	node *temp;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	free(current);
	return 0;
}

node * CreateNList(int n)
{
	node *head;
	node *current;
	node *nextnode;
	int i;
	//创建链表头
	head = NewList();
	//链表创建失败检测
	if (head == NULL)
	{
		printf("链表创建失败\n");
		system("pause");
		return NULL;
	}
	//随机赋值
	srand((unsigned)time(NULL));
	current = head;
	for (i = 0; i < n;i++)
	{
		nextnode = (node *)malloc(sizeof(node));
		//失败检测
		if (nextnode==NULL)
		{
			printf("链表增加结点失败\n");
			return NULL;
		}
		//随机赋值
		nextnode->num = rand();
		nextnode->next = NULL;
		//接上链表
		current->next = nextnode;
		//移动current
		current = nextnode;
	}
	return head;
}

int PrintAllList(node *head,int k, int n)
{
	node *current;
	char str[50];
	int i=0;
	//控制输出
	sprintf(str,"%%%dd",n);
	current = head->next;
	while (current->next!=NULL)
	{
		printf(str,current->num);
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

node * SortList(node * head)
{
	node *i;
	node *j;
	node *min;
	node temp;
	//冒泡排序
	i = head->next;
	j = i->next;
	while (i->next!=NULL)
	{
		min = i;
		j = i->next;
		while (j->next != NULL)
		{
			if (j->num < min->num)
			{
				min = j;
			}
			j = j->next;
		}
		if (j->num < min->num)
		{
			min = j;
		}
		//交换
		temp.num = min->num;
		min->num = i->num;
		i->num = temp.num;

		i = i->next;
	}
	
	return head;
}

node * Del35List(node * head)
{
	node *current=head->next;
	node *last=head;
	int temp;
	while (current->next != NULL)
	{
		temp = current->num;
		//处理数字
		while (temp > 0)
		{
			if (temp % 10 == 3 || temp % 10 == 5)
			{
				break;
			}
			temp = temp / 10;
		}
		//删除节点
		if (temp > 0)
		{
			last->next = current->next;
			free(current);
			current = last->next;
		}
		else
		{
		current = current->next;
		last = last->next;
		}
	}

	temp = current->num;
	//处理数字
	while (temp > 0)
	{
		if (temp % 10 == 3 || temp % 10 == 5)
		{
			break;
		}
		temp = temp / 10;
	}
	//删除节点
	if (temp > 0)
	{
		last->next = NULL;
		free(current);
	}
	return head;
}
