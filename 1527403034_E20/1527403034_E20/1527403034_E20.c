/*文件名：1527403034_E20.c
*作者：王俊
*时间：2015年10月31日
*功能：现有1元、2元和5元的钱币若干，如果要用这些钱币去购买售价50元的商品，请问有多少不同的组合方式
*备注：
*/
#include<stdio.h>
int main()
{
	int num1=0,num2=0,num5=0,num=0;
	//枚举组合方式
	//一元硬币的组合
	for(num1=0;num1<=50;num1++)
	{
		//两元硬币的组合
		for(num2=0;num2<=25;num2++)
		{
			//五元硬币的组合
			for(num5=0;num5<=10;num5++)
			{
				if(num1+num2*2+num5*5==50)
				{
					num++;
				}
			}
		}	
	}
	//输出组合方式
	printf("有%d种组合方式\n",num);
	return 0;
}