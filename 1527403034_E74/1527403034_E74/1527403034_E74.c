/*文件名：1527403034_E74.c
*作者：王俊
*时间：2016年1月4日
*功能：
*备注：
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
/*功能：通讯录录入
参数：item[]
	item *
	int limit
返回值：int 
*/
int WriteIn(item list[],int * plist,int limit);
/*功能：通讯录删除
参数：item[]
	item **
	int limit
返回值：int
*/
int Delete(item list[], int * plist, int limit);
/*功能：通讯录输出
参数：item[]
item **
int limit
返回值：int
*/
int PrintfAll(item list[], int * plist, int limit);
/*功能：通讯录修改
参数：item[]
item **
int limit
返回值：int
*/
int Change(item list[], int * plist, int limit);
/*功能：通讯录查询
参数：item[]
item **
int limit
返回值：int
*/
int Search(item list[], int * plist, int limit);
int main()
{
	item list[LISTSIZE];
	int plist=0;
	int cho;
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
				printf("不存在此选项！\n");
				break;
		}
		printf("----------以下是通讯录全部内容：----------\n");
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
		printf("通讯录已满！！\n");
		return 1;
	}
	//输入
	printf("开始录入数据：\n");
	printf("请输入名字：\n");
	scanf("%s",list[*plist].name);
	printf("请输入电话号码：\n");
	scanf("%s", list[*plist].tel);
	printf("请输入移动电话号码：\n");
	scanf("%s", list[*plist].mobile);
	printf("请输入邮编：\n");
	scanf("%s", list[*plist].postcode);
	printf("请输入通讯地址信息：\n");
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
		printf("通讯录已满！！\n");
		return 1;
	}
	//输入
	printf("请输入要删除的条目的名字\n");
	scanf("%s",temp.name);
	//搜索
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
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//删除
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
		printf("通讯录已满！！\n");
		return 1;
	}
	while (psearch<*plist)
	{
		printf("第%d条:\n",psearch+1);
		printf("人名：%s\n电话号码：%s\n移动电话：%s\n邮编：%s\n通讯地址：%s\n"
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
		printf("通讯录已满！！\n");
		return 1;
	}
	//输入
	printf("请输入要修改的条目的名字\n");
	scanf("%s", temp.name);
	//搜索
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
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//修改
		printf("请重新输入数据：\n");
		printf("开始录入数据：\n");
		printf("请输入名字：\n");
		scanf("%s", list[psearch].name);
		printf("请输入电话号码：\n");
		scanf("%s", list[psearch].tel);
		printf("请输入移动电话号码：\n");
		scanf("%s", list[psearch].mobile);
		printf("请输入邮编：\n");
		scanf("%s", list[psearch].postcode);
		printf("请输入通讯地址信息：\n");
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
		printf("通讯录已满！！\n");
		return 1;
	}
	//输入
	printf("请输入要查询的条目的名字\n");
	scanf("%s", temp.name);
	//搜索
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
		printf("找不到此人\n");
		return 1;
	}
	else
	{
		//输出
		printf("第%d条:\n", psearch + 1);
		printf("人名：%s\n电话号码：%s\n移动电话：%s\n邮编：%s\n通讯地址：%s\n"
			, list[psearch].name
			, list[psearch].tel
			, list[psearch].mobile
			, list[psearch].postcode
			, list[psearch].address);
	}
	return 0;
}
