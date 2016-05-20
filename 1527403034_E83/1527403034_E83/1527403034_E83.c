/*文件名：1527403034_E83.c
*作者：王俊
*时间：2016年1月21日
*功能：
*备注：
*/
#include<stdio.h>
#include<stdlib.h>
struct _student
{
	char ID[15];
	char name[20];
	int grade;
	int scores[3];
};
typedef struct _student student;
typedef struct Node
{
	student data;
	struct Node*next;
}node;
/*
功能：读取文件
参数：char *addr
返回值：node *
*/
node *ReadFile(char *addr);
/*
功能：输出学生信息
参数：node *head
返回值：int
*/
int PrintList(node *head);
/*
功能：按平均成绩从大到小排序
参数：node *head
返回值：int
*/
int SortList(node *head);
/*
功能：将数据输出到文件
参数：node *head
char *addr
返回值：int
*/
int WriteToFile(node *head,char *addr);
/*
功能：删除平均成绩小于score的学生
参数：node *head
double score
返回值：int
*/
int DeleteStudent(node *head,double score);
/*
功能：销毁链表
参数：node *head
返回值：int
*/
int DestroyList(node *head);
int main()
{
	node *head;
	head=ReadFile("c:\\cdata\\E83_data.bin");
	printf("原数据\n");
	PrintList(head);
	SortList(head);
	printf("排序后数据\n");
	PrintList(head);
	DeleteStudent(head,40);
	printf("删除部分后的数据\n");
	PrintList(head);
	WriteToFile(head, "c:\\cdata\\E83_delresult.txt");
	printf("已经删除小于四十分的学生，并输出到文件\n");
	DestroyList(head);
	system("pause");
	return 0;
}

node * ReadFile(char * addr)
{
	FILE *fin;
	node *head;
	node *cur;
	int len;
	int i;
	fin = fopen(addr, "rb");
	if (fin == NULL)
	{
		printf("文件打开失败\n");
		return NULL;
	}
	//分配头节点
	head = (node *)malloc(sizeof(node));
	if (head == NULL)
	{
		printf("头节点分配失败\n");
		return NULL;
	}
	//初始化头节点
	head->next = NULL;
	//计算文件长度
	fseek(fin, 0, SEEK_END);
	len=ftell(fin);
	fseek(fin, 0, SEEK_SET);
	cur = head;
	for (i = 0; i < len / sizeof(student); i++)
	{
		cur->next = (node *)malloc(sizeof(node));
		if (cur->next==NULL)
		{
			printf("节点新建失败\n");
			return NULL;
		}
		cur = cur->next;
		cur->next = NULL;
		fread(&(cur->data), sizeof(student), 1, fin);
	}
	fclose(fin);
	return head;
}

int PrintList(node * head)
{
	node *cur = head->next;
	printf("%-20s%-25s%-3s%-6s%-6s%-6s\n","学号","姓名","年级","成绩一","成绩二","成绩三");
	while (cur!=NULL)
	{
		printf("%-20s%-25s%-3d%6d%6d%6d\n",cur->data.ID,cur->data.name,cur->data.grade,cur->data.scores[0], cur->data.scores[1], cur->data.scores[2]);
		cur = cur->next;
	}
	return 0;
}

double GetAverage(student data)
{
	return (data.scores[0] + data.scores[1] + data.scores[2]) / 3;
}
int SortList(node * head)
{
	node *i, *j;
	node *max;
	student temp;
	i = head->next;
	while (i->next != NULL)
	{
		j = i;
		max = i;
		while (j != NULL)
		{
			if (GetAverage(j->data) > GetAverage(max->data))
			{
				max = j;
			}
			j = j->next;
		}
		temp = i->data;
		i->data = max->data;
		max->data = temp;
		i = i->next;
	}

	return 0;
}

int WriteToFile(node * head,char *addr)
{
	FILE *fout;
	node *cur = head;
	fout = fopen(addr,"w");
	if(fout==NULL)
	{
		printf("文件打开失败\n");
		return 1;
	}
	//fprintf(fout,"%-20s%-25s%-3s%-6s%-6s%-6s\n", "学号", "姓名", "年级", "成绩一", "成绩二", "成绩三");
	while (cur != NULL)
	{
		fprintf(fout,"%-20s%-25s%-3d%6d%6d%6d\n", cur->data.ID, cur->data.name, cur->data.grade, cur->data.scores[0], cur->data.scores[1], cur->data.scores[2]);
		cur = cur->next;
	}
	fclose(fout);
	return 0;
}

int DeleteStudent(node * head, double score)
{
	node *cur = head;
	node *temp;
	while (cur->next!=NULL)
	{
		if (GetAverage(cur->next->data) < score)
		{
			temp = cur->next;
			cur->next = cur->next->next;
			free(temp);
			continue;
		}
		cur = cur->next;
	}
	return 0;
}

int DestroyList(node * head)
{
	node *temp;
	while (head!=NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	return 0;
}
