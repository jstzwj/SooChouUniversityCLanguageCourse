/*文件名：1527403034_E30.c
*作者：王俊
*时间：2015年11月19日
*功能：已知int arry[]={35,46,57,13,24,35,99,68,13,79,88,46} ， 请将数组中重复的元素去除，并按从小到大顺序排列输出。
*备注：
*/
#include<stdio.h>
int main()
{
	int arry[]={35,46,57,13,24,35,99,68,13,79,88,46};
	int i,j,k;
	int len;
	int temp;
	len=12;
	//去除重复元素
	for(i=0;i<len-1;i++)
	{
		for(j=i+1;j<len;j++)
		{
			if(arry[i]==arry[j])
			{
				for(k=j+1;k<len;k++)
				{
					arry[k-1]=arry[k];
				}
				len--;
				i--;
			}
		}
	}
	//排序
	for(i=len-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(arry[j]>arry[j+1])
			{
				temp=arry[j];
				arry[j]=arry[j+1];
				arry[j+1]=temp;
			}

		}
	}
	//输出
	for(i=0;i<len;i++)
	{
		printf("%-4d",arry[i]);
	}
	printf("\n");
	return 0;
}