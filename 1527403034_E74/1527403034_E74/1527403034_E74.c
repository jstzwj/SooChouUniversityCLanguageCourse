/*�ļ�����1527403034_E74.c
*���ߣ�����
*ʱ�䣺2016��1��4��
*���ܣ�
*��ע��
*/
#define LISTSIZE 50
struct Item
{
	char name[20];
	char tel[15];
	char mobile[15];
	char postcode[10];
	char address[50];
};
typedef struct Item item;
#include<stdio.h>
#include<string.h>
/*���ܣ�ͨѶ¼¼��
������item[]
	item *
	int limit
����ֵ��int 
*/
int WriteIn(item list[],int * plist,int limit);
/*���ܣ�ͨѶ¼ɾ��
������item[]
	item **
	int limit
����ֵ��int
*/
int Delete(item list[], int * plist, int limit);
/*���ܣ�ͨѶ¼���
������item[]
item **
int limit
����ֵ��int
*/
int PrintfAll(item list[], int * plist, int limit);
/*���ܣ�ͨѶ¼�޸�
������item[]
item **
int limit
����ֵ��int
*/
int Change(item list[], int * plist, int limit);
/*���ܣ�ͨѶ¼��ѯ
������item[]
item **
int limit
����ֵ��int
*/
int Search(item list[], int * plist, int limit);
int main()
{
	item list[LISTSIZE];
	int plist=0;
	int cho;
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
				WriteIn(list, &plist, LISTSIZE);
				break;
			case 2:
				Delete(list, &plist, LISTSIZE);
				break;
			case 3:
				Change(list, &plist, LISTSIZE);
				break;
			case 4:
				Search(list, &plist, LISTSIZE);
				break;
			case 5:
				return 0;
				break;
			default:
				printf("�����ڴ�ѡ�\n");
				break;
		}
		printf("----------������ͨѶ¼ȫ�����ݣ�----------\n");
		PrintfAll(list, &plist, LISTSIZE);
		system("pause");
		system("cls");
	}
	
	return 0;
}

int WriteIn(item list[], int * plist, int limit)
{
	if (*plist>= LISTSIZE)
	{
		printf("ͨѶ¼��������\n");
		return 1;
	}
	//����
	printf("��ʼ¼�����ݣ�\n");
	printf("���������֣�\n");
	scanf("%s",list[*plist].name);
	printf("������绰���룺\n");
	scanf("%s", list[*plist].tel);
	printf("�������ƶ��绰���룺\n");
	scanf("%s", list[*plist].mobile);
	printf("�������ʱࣺ\n");
	scanf("%s", list[*plist].postcode);
	printf("������ͨѶ��ַ��Ϣ��\n");
	scanf("%s", list[*plist].address);
	(*plist)++;
	return 0;
}

int Delete(item list[], int * plist, int limit)
{
	item temp;
	int psearch=0;
	if (*plist >= LISTSIZE)
	{
		printf("ͨѶ¼��������\n");
		return 1;
	}
	//����
	printf("������Ҫɾ������Ŀ������\n");
	scanf("%s",temp.name);
	//����
	while (psearch != *plist)
	{
		if (strcmp(list[psearch].name,temp.name)==0)
		{
			break;
		}
		psearch++;
	}
	if (psearch == *plist)
	{
		printf("�Ҳ�������\n");
		return 1;
	}
	else
	{
		//ɾ��
		while (psearch <= *plist - 2)
		{
			list[psearch] = list[psearch + 1];
			psearch++;
		}
	}
	(*plist)--;
	return 0;
}

int PrintfAll(item list[], int * plist, int limit)
{
	int psearch = 0;
	if (*plist>= LISTSIZE)
	{
		printf("ͨѶ¼��������\n");
		return 1;
	}
	while (psearch<*plist)
	{
		printf("��%d��:\n",psearch+1);
		printf("������%s\n�绰���룺%s\n�ƶ��绰��%s\n�ʱࣺ%s\nͨѶ��ַ��%s\n"
			, list[psearch].name
			, list[psearch].tel
			, list[psearch].mobile
			, list[psearch].postcode
			, list[psearch].address);
		psearch++;
	}
	return 0;
}

int Change(item list[], int * plist, int limit)
{
	item temp;
	int psearch = 0;
	if (*plist >= LISTSIZE)
	{
		printf("ͨѶ¼��������\n");
		return 1;
	}
	//����
	printf("������Ҫ�޸ĵ���Ŀ������\n");
	scanf("%s", temp.name);
	//����
	while (psearch != *plist)
	{
		if (strcmp(list[psearch].name,temp.name)==0)
		{
			break;
		}
		psearch++;
	}
	if (psearch == *plist)
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
		scanf("%s", list[psearch].name);
		printf("������绰���룺\n");
		scanf("%s", list[psearch].tel);
		printf("�������ƶ��绰���룺\n");
		scanf("%s", list[psearch].mobile);
		printf("�������ʱࣺ\n");
		scanf("%s", list[psearch].postcode);
		printf("������ͨѶ��ַ��Ϣ��\n");
		scanf("%s", list[psearch].address);
	}
	return 0;
}

int Search(item list[], int * plist, int limit)
{
	item temp;
	int psearch = 0;
	if (*plist >= LISTSIZE)
	{
		printf("ͨѶ¼��������\n");
		return 1;
	}
	//����
	printf("������Ҫ��ѯ����Ŀ������\n");
	scanf("%s", temp.name);
	//����
	while (psearch != *plist)
	{
		if (strcmp(list[psearch].name,temp.name)==0)
		{
			break;
		}
		psearch++;
	}
	if (psearch == *plist)
	{
		printf("�Ҳ�������\n");
		return 1;
	}
	else
	{
		//���
		printf("��%d��:\n", psearch + 1);
		printf("������%s\n�绰���룺%s\n�ƶ��绰��%s\n�ʱࣺ%s\nͨѶ��ַ��%s\n"
			, list[psearch].name
			, list[psearch].tel
			, list[psearch].mobile
			, list[psearch].postcode
			, list[psearch].address);
	}
	return 0;
}
