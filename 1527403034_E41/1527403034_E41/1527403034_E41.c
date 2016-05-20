/*文件名：1527403034_E41.c
*作者：王俊
*时间：2015年11月25日
*功能：从键盘输入个包含数字、字母的字符串，以连续数字构成一个整数，如果连续的数字超过6个，则从第7个数字开始构成一个新的整数。 请编写程序提取字符串中的所有整数。 例如：输入的字符串为s123abd345234869de ，则提取的整数有：123 ，345234 ， 869 。
*备注：
*/
#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	char str[N];//存储字符串
	int integer[N]={0};//存储整数
	int integer_eff_flag=-1;
	int num_flag=0;//数字标记
	int count=0;//标记位数
	int i,j;
	//输入
	printf("请输入一串字符：\n");
	gets(str);
	//提取整数
	for(i=0;str[i]!=0;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			if(num_flag==0)
			{
				integer_eff_flag++;
				count=0;
			}
			num_flag=1;
			integer[integer_eff_flag]=integer[integer_eff_flag]*10+str[i]-'0';
			if(count==5)
			{
				count=0;
				integer_eff_flag++;
			}
			count++;
		}
		else if(str[i]>='a'&&str[i]<='z')
		{
			num_flag=0;
		}
		else
		{
			printf("不能输入数字与字母以外的字符\n");
			break;
		}

	}
	//输出
	for(i=0;i<=integer_eff_flag;i++)
	{
		printf("%10d",integer[i]);
	}
	printf("\n");

	return 0;
}