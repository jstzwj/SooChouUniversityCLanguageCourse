/*文件名：1527403034_E14.c
*作者：王俊
*时间：2015年10月24日
*功能：从键盘输入任意3个整数，按从小到大顺序输出。
*备注：
*/
#include<stdio.h>
int main()
{
	int a=0,b=0,c=0;
	//输入三个整数
	printf("请输入三个整数：\n");
	scanf("%d%d%d",&a,&b,&c);
	//进行大小比较
	if(a>b)
	{
		if(b>c)
		{
			printf("由小到大输出为：%d %d %d\n",c,b,a);
		}
		else
		{
			if(a>c)
			{
				printf("由小到大输出为：%d %d %d\n",b,c,a);
			}
			else
			{
				printf("由小到大输出为：%d %d %d\n",b,a,c);
			}
		}
	}
	else
	{
		if(b>c)
		{
			if(a>c)
			{
				printf("由小到大输出为：%d %d %d\n",c,a,b);
			}
			else
			{
				printf("由小到大输出为：%d %d %d\n",a,c,b);
			}
		}
		else
		{
			printf("由小到大输出为：%d %d %d\n",a,b,c);
		}
	}

	return 0;
}