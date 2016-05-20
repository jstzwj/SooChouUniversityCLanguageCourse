/*�ļ�����1527403034_E72.c
*���ߣ�����
*ʱ�䣺2016��1��1��
*���ܣ�
*��ע��
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
/*����������������ܺ���*/
/*
	���ܣ��½�����
	��������
	����ֵ��node *
*/
node * NewList();

/*
���ܣ��ӳ�����
������node *head	���ĸ�����ӳ�
	node nextnode	����Ľڵ�
����ֵ��int *
*/
node * AddList(node * const head,node nextnode);

/*
���ܣ���������
������node *	��Ҫ���ٵ�����
����ֵ��int
*/
int DestroyList(node * head);

/*
���ܣ�������n�����ֵ��������
������int n
����ֵ��node *
*/
node * CreateNList(int n);

/*
���ܣ�������������е�����
������int n		ÿ������ռn��
int k	ÿ��k������
����ֵ��int
*/
int PrintAllList(node *head,int k,int n);

/*
���ܣ���������С��������
������node * head
����ֵ��node * head
*/
node * SortList(node *head);


/*
���ܣ�ɾ��������3��5�Ľڵ�
������node * head
����ֵ��node * head
*/
node * Del35List(node *head);

int main()
{
	node *head;
	node current;
	int n;
	int a, b;
	printf("������Ҫ������ɶ೤������\n");
	scanf("%d",&n);
	printf("������ÿ�������������Ŀ������ռ������\n");
	scanf("%d%d", &a,&b);
	//��������
	head=CreateNList(n);
	//������ʧ�ܼ��
	if (head == NULL)
	{
		printf("������ʧ��\n");
		system("pause");
		return 1;
	}
	//�������
	printf("ԭ����Ϊ��\n");
	PrintAllList(head, a, b);
	printf("\n");
	//��������
	SortList(head);
	//�������
	printf("���������Ϊ��\n");
	PrintAllList(head, a, b);
	printf("\n");
	//ɾ������
	Del35List(head);
	//�������
	printf("ɾ��3��5������Ϊ��\n");
	PrintAllList(head, a, b);
	printf("\n");
	//�ͷ�����
	DestroyList(head);
	//system("pause");
	return 0;
}

node * NewList()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	//ʧ�ܷ��ؿ�ָ��
	if (head == NULL)
	{
		return NULL;
	}
	//��ͷ�ڵ㸳��ֵ
	head->num = 0;
	head->next = NULL;
	return head;
}

node * AddList(node * const head, node nextnode)
{
	node *current=head;
	node *temp;
	//�ҵ�ĩβ
	while (current!=NULL)
	{
		current = current->next;
	}
	//�ӳ�����
	temp = (node *)malloc(sizeof(node));
	//ʧ�ܴ���
	if(temp==NULL)
	{
		printf("����ӳ�ʧ��\n");
		return NULL;
	}
	//��⴫��Ķ����Ƿ�ָ��NULL
	if (nextnode.next != NULL)
	{
		printf("�˽ڵ��next������NULL�����Զ�ת��ΪNULL\n");
	}
	//���ƶ���
	temp->num = nextnode.num;
	temp->next = NULL;
	//����ȥ
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
	//��������ͷ
	head = NewList();
	//������ʧ�ܼ��
	if (head == NULL)
	{
		printf("������ʧ��\n");
		system("pause");
		return NULL;
	}
	//�����ֵ
	srand((unsigned)time(NULL));
	current = head;
	for (i = 0; i < n;i++)
	{
		nextnode = (node *)malloc(sizeof(node));
		//ʧ�ܼ��
		if (nextnode==NULL)
		{
			printf("�������ӽ��ʧ��\n");
			return NULL;
		}
		//�����ֵ
		nextnode->num = rand();
		nextnode->next = NULL;
		//��������
		current->next = nextnode;
		//�ƶ�current
		current = nextnode;
	}
	return head;
}

int PrintAllList(node *head,int k, int n)
{
	node *current;
	char str[50];
	int i=0;
	//�������
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
	//ð������
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
		//����
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
		//��������
		while (temp > 0)
		{
			if (temp % 10 == 3 || temp % 10 == 5)
			{
				break;
			}
			temp = temp / 10;
		}
		//ɾ���ڵ�
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
	//��������
	while (temp > 0)
	{
		if (temp % 10 == 3 || temp % 10 == 5)
		{
			break;
		}
		temp = temp / 10;
	}
	//ɾ���ڵ�
	if (temp > 0)
	{
		last->next = NULL;
		free(current);
	}
	return head;
}
