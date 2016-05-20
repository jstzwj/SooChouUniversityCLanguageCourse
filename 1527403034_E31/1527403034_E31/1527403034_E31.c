/*文件名：1527403034_E31.c
*作者：王俊
*时间：2015年11月19日
*功能：已知有序数组 int arry[]={12, 23, 34, 56, 78,98,256,789}从键盘输入一个整数，请用二分查找法在数组中找出该整数
，并将其下标输出到屏幕上，如果数组中没有该整数则输出 “无此整数 ”。
*备注：
*/
#include<stdio.h>
int main()
{
	int arry[]={12, 23, 34, 56, 78,98,256,789};
	int num;
	int len=8;
	int start,end,index;

	start=0;
	end=len-1;
	index=len/2;

	//输入
	printf("请输入一个整数:\n");
	scanf("%d",&num);

	//二分法查找
	while(start!=end)
	{
		if(num>arry[index])
		{
			start=index+1;
			index=(start+end)/2;
		}
		else if(num<arry[index])
		{
			end=index-1;
			index=(start+end)/2;
		}
		else
		{
			printf("有此整数，下标为%d\n",index);
			break;
		}
	}
	//输出不存在
	if(start==end)
	{
		printf("不存在此整数！\n");
	}
	return 0;
}