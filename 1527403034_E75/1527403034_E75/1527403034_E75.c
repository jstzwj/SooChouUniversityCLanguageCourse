/*�ļ�����1527403034_E75.c
*���ߣ�����
*ʱ�䣺2016��1��4��
*���ܣ�
*��ע��
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
/*����:����ͨѶ¼
��������
����ֵ��node *
*/
node * CreateList();

/*���ܣ�ͨѶ¼¼��
������node * head
����ֵ��int 
*/
int WriteIn(node *head);

/*���ܣ�ͨѶ¼ɾ��
������node * head
����ֵ��int
*/
int Delete(node * head);
/*���ܣ�ͨѶ¼���
������node * head
����ֵ��int
*/
int PrintfAll(node * head);
/*���ܣ�ͨѶ¼�޸�
������node * head
����ֵ��int
*/
int Change(node * head);
/*���ܣ�ͨѶ¼��ѯ
������node * head
����ֵ��int
*/
int Search(node * head);
int main()
{
	node *head = NULL;
	int cho;
	head = CreateList();
	while (1)
	{
		//��ʼ
		printf("ͨѶ¼\n");
		printf("1.����\n");
		printf("2.ɾ��\n");
		printf("3.�޸�\n");
		printf("4.��ѯ\n");
		printf("5.�˳�\n");
		printf("��ѡ�������\n");
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
				printf("�����ڴ�ѡ�\n");
				break;
		}
		printf("----------������ͨѶ¼ȫ�����ݣ�----------\n");
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
		printf("ͷָ��ռ����ʧ�ܣ�\n");
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
		printf("��������ʧ�ܣ�\n");
		return 1;
	}
	newnode->next = NULL;
	//��������
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	//����
	printf("��ʼ¼�����ݣ�\n");
	printf("���������֣�\n");
	scanf("%s",newnode->data.name);
	printf("������绰���룺\n");
	scanf("%s", newnode->data.tel);
	printf("�������ƶ��绰���룺\n");
	scanf("%s", newnode->data.mobile);
	printf("�������ʱࣺ\n");
	scanf("%s", newnode->data.postcode);
	printf("������ͨѶ��ַ��Ϣ��\n");
	scanf("%s", newnode->data.address);
	return 0;
}

int Delete(node * head)
{
	node temp;
	node * current=head->next;
	node * last = head;

	//����
	printf("������Ҫɾ������Ŀ������\n");
	scanf("%s",temp.data.name);
	//����
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
		printf("�Ҳ�������\n");
		return 1;
	}
	else
	{
		//ɾ��
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
		printf("��%d��:\n",i+1);
		printf("������%s\n�绰���룺%s\n�ƶ��绰��%s\n�ʱࣺ%s\nͨѶ��ַ��%s\n"
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

	//����
	printf("������Ҫ�޸ĵ���Ŀ������\n");
	scanf("%s", temp.data.name);
	//����
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
		printf("�Ҳ�������\n");
		return 1;
	}
	else
	{
		//�޸�
		printf("�������������ݣ�\n");
		printf("��ʼ¼�����ݣ�\n");
		printf("���������֣�\n");
		scanf("%s", current->data.name);
		printf("������绰���룺\n");
		scanf("%s", current->data.tel);
		printf("�������ƶ��绰���룺\n");
		scanf("%s", current->data.mobile);
		printf("�������ʱࣺ\n");
		scanf("%s", current->data.postcode);
		printf("������ͨѶ��ַ��Ϣ��\n");
		scanf("%s", current->data.address);
	}
	return 0;
}

int Search(node * head)
{
	node temp;
	node * current = head;
	int i = 0;
	//����
	printf("������Ҫ��ѯ����Ŀ������\n");
	scanf("%s", temp.data.name);
	//����
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
		printf("�Ҳ�������\n");
		return 1;
	}
	else
	{
		//���
		printf("��%d��:\n", i + 1);
		printf("������%s\n�绰���룺%s\n�ƶ��绰��%s\n�ʱࣺ%s\nͨѶ��ַ��%s\n"
			, current->data.name
			, current->data.tel
			, current->data.mobile
			, current->data.postcode
			, current->data.address);
	}
	return 0;
}
