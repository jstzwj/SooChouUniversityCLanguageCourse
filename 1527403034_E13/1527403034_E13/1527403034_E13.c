/*文件名：1527403034_E13.c
*作者：王俊
*时间：2015年10月24日
*功能：给出一个不多于5位的正整数，要求:（1)求出它是几位数；（2）分别输出每一位数字；（3）按逆序输出每位数字,例如原为321,应输出123
*备注：
*/
#include<stdio.h>
int main()
{
	int i=0;
	int num=0;
	int temp=1;
	int result=0;
	//输入一个正整数
	printf("请输入一个不多于5位的正整数：\n");
	scanf("%d",&num);
	//判断是否小于五位
	if((num<100000)&&(num>0))
	{
	printf("各位数依次为：\n");
	while(num!=0)
		{
			//获取每一位数
			temp=num%10;
			result=result*10+temp;
			num/=10;
			i++;
			//输出每一位数
			if(i==1)
			{
			printf("个位数是%d\n",temp);
			}
			if(i==2)
			{
			printf("十位数是%d\n",temp);
			}
			if(i==3)
			{
			printf("百位数是%d\n",temp);
			}
			if(i==4)
			{
			printf("千位数是%d\n",temp);
			}
			if(i==5)
			{
			printf("万位数是%d\n",temp);
			}
		}
	printf("是%d位数\n",i);
	printf("逆序输出的结果为%d\n",result);
	}
	else
	{
	printf("输入的数字不满足要求！\n");
	}
return 0;
}