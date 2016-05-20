/*�ļ�����1527403034_E73.c
*���ߣ�����
*ʱ�䣺2016��1��2��
*���ܣ�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int num;
	struct Node* next;
};
typedef struct Node node;

/*���ܣ���������
��������
����ֵ��node*
*/
node * CreateList();

/*���ܣ���������
������node * head ����ͷָ��
����ֵ��int
*/
int DestroyList(node * head);

/*
���ܣ�������������е�����
������int n		ÿ������ռn��
int k	ÿ��k������
����ֵ��int
*/
int PrintAllList(node *head, int k, int n);

/*
���ܣ�ɾ������ż�����
������node * head
����ֵ��node *head
*/
node * DelEvenList(node *head);


/*
���ܣ�ɾ����������ֵΪn�Ľ��
������node * head
����ֵ��int ��Ϊ-1��ɾ�����ɹ�
*/
int DelNList(node *head,int n);

int main()
{
	node *head;
	int k, n;
	int num;
	//��������
	head = CreateList();
	if (head == NULL)
	{
		return 1;
	}
	//�������
	printf("������ÿ�������������Ŀk��������ռ������\n");
	scanf("%d%d",&k,&n);
	printf("ԭ����Ϊ\n");
	PrintAllList(head,k,n);
	printf("\n");
	//system("pause");
	//ɾ��ż��
	DelEvenList(head);
	//�������
	printf("ɾ��ż����Ϊ\n");
	PrintAllList(head, k, n);
	printf("\n");
	//system("pause");
	//ɾ��
	printf("��������Ҫɾ�������֣�\n");
	scanf("%d",&num);
	if (DelNList(head, num) == -1)
	{
		printf("ɾ��ʧ��\n");
	}
	//�������
	printf("ɾ����Ϊ\n");
	PrintAllList(head, k, n);
	printf("\n");
	//system("pause");
	//��������
	DestroyList(head);
	return 0;
}

node * CreateList()
{
	node *head;
	node *current;
	node *newnode;
	int i;
	//��������
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("����ͷ����ʧ��\n");
		return NULL;
	}
	head->num = 0;
	head->next = NULL;
	//����ʼֵ
	i = 1;
	current = head;
	while (i * 3 < 100)
	{
		newnode = (node *)malloc(sizeof(node));
		if (newnode == NULL)
		{
			printf("����ڵ㴴��ʧ��\n");
			return NULL;
		}
		current->next = newnode;
		newnode->num = i * 3;
		//����
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
	//�������
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
		//ɾ��
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
	//ɾ��
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
		//ɾ��
		if (current->num == n)
		{
			temp = current->next;
			last->next = current->next;
			free(current);
			current = temp;
			//����
			return 0;
		}
		current = current->next;
		last = last->next;
	}
	//ɾ��
	if (current->num == n)
	{
		last->next = NULL;
		return 0;
	}
	return -1;
}
