/*文件名：1527403034_E26.c
*作者：王俊
*时间：2015年11月3日
*功能:编写程序找出 所有三位数中的包含字3的所有素数，并输出的所有素数，并输出到屏幕上，要求每行输出8个素数，每占6列。
*备注：
*/
#include<stdio.h>
int main()
{
	int a=0,num=0,i=0,count=0;
	//枚举三位数
	for(num=100;num<=999;num++)
	{
		//判断素数
		for(i=2;i<num;i++)
		{
			//求余判断约数
			if(num%i==0)
			{
				break;
			}
			//暂存num的值
			a=num;
			//判断存不存在数字3
				while(a>0)			
				{
				if(a%10==3)
					{
					break;
					}
					a/=10;
				}
				//输出
				if((a!=0)&&(i==num-1))
				{
					count++;
				printf("%6d",num);
				if(count%8==0)
				{
					printf("\n");
				}
				
				}
		}
	}
	printf("\n");
	return 0;
}