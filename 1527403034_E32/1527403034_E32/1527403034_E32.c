/*文件名：1527403034_E32.c
*作者：王俊
*时间：2015年11月19日
*功能：已知int arry[]={12, 23, 34, 56, 78,98,256,789}，请编写程序，在不使用其他过度数组的情况下逆序所有元素。
*备注：
*/
#include<stdio.h>
#define N 8
int main()
{
	int arry[]={12, 23, 34, 56, 78,98,256,789};
	int i;
	int m,n;
	//初始化
	m=0;
	n=N-1;
	//逆序
	while((m!=n)&&(n-m!=1))
	{
		i=arry[m];
		arry[m]=arry[n];
		arry[n]=i;

		m++;
		n--;
	}
	//输出
	printf("逆序结果为：\n");
	for(i=0;i<N;i++)
	{
		
		printf("%-4d",arry[i]);
	}
	printf("\n");
	return 0;
}