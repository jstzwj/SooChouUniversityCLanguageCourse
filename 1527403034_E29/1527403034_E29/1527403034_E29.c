/*文件名：1527403034_E29.c
*作者：王俊
*时间：2015年11月16日
*功能：已知int arry[10]={13,24,35,46,57,68,79,88,93} ，请将用户输入的一个数字按照从小到大顺序插在对应位置后出整组.
*备注：
*/
#include<stdio.h>
int main()
{
	int temp,i,j;
	int arry[10]={13,24,35,46,57,68,79,88,93} ;
	//输入
	printf("请输入一个数字\n");
	scanf("%d",&temp);
	//插入
	for(i=0;i<=8;i++)
	{
		if(temp<arry[i])
		{
			for(j=8;j>=i;j--)
			{
				arry[j+1]=arry[j];
			}
			arry[i]=temp;
			break;
		}
	}
	//输出
	for(i=0;i<=9;i++)
	{
		printf("%-5d",arry[i]);
	}
	printf("\n");
	return 0;
}