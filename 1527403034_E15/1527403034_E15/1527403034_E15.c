/*文件名：1527403034_E15.c
*作者：王俊
*时间：2015年10月24日
*功能：输入一个整数表示存款金额，计算年后的本和利息总共有多少.
*备注：
*/
#include<stdio.h>
int main()
{
	int money=0;
	int result=0;
//输入存款金额
	printf("请输入存款金额(万元)：\n");
	scanf("%d",&money);
	//计算本息和
	switch(money/10)
	{
	case 0:result=(int)(1.015*money);break;
	case 1:result=(int)(1.02*money);break;
	case 2:result=(int)(1.02*money);break;
	case 3:result=(int)(1.02*money);break;
	case 4:result=(int)(1.02*money);break;
	case 5:result=(int)(1.03*money);break;
	case 6:result=(int)(1.03*money);break;
	case 7:result=(int)(1.03*money);break;
	case 8:result=(int)(1.03*money);break;
	case 9:result=(int)(1.03*money);break;
	default:result=(int)(1.035*money);break;
	}
	printf("一年后本金和利息一共有%d万元\n",result);
	return 0;
}