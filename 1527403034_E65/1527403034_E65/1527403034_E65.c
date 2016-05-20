/*文件名：1527403034_E65.c
*作者：王俊
*时间：2015年12月23日
*功能：
*备注：
*/
#include<stdio.h>
/*
功能：计算由字符串中数字能构成的最大整数和最小整数
参数：char str[]
	int* max
	int* min
返回值：无
*/
void MaxMin(char str[], int* max, int* min)
{
	int num[6];
	int num2[6];
	int temp;
	int len;
	int i,j;

	for (i = 0; str[i] != 0;i++)
	{
		num[i] = str[i] - '0';
	}
	len = i;
	//暂存
	for (i = 0; i < len; i++)
	{
		num2[i] = num[i];
	}
	//排序
	for (i = 0; i < len; i++)
	{
		for (j = len - 1; j >i; j--)
		{
			if (num2[j] > num2[j - 1])
			{
				temp=num2[j];
				num2[j] = num2[j - 1];
				num2[j - 1] = temp;
			}
		}
	}
	//最大数
	for (i = 0; i < len; i++)
	{
		*max = (*max) * 10 + num2[i];
	}
	//最小值
	*min = num[0];
	for (i = 0; i < len; i++)
	{
		if (num[i] < *min)
		{
			*min = num[i];
		}
	}
}
int main()
{
	char str[6];
	int max=0;
	int min=0;
	//输入
	printf("请输入一个字符串\n");
	gets(str);
	//计算
	MaxMin(str,&max,&min);
	//输出
	printf("最大值为：\n%d\n",max);
	printf("最小值为：\n%d\n", min);
	return 0;
}