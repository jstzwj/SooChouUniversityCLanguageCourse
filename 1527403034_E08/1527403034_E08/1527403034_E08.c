/*==========================================
*文件名:1527403034_E08.c
*作者:王俊
*时间:2015.10.21
*功能:语句】从键盘输入三个浮点变量 a、b和c用公式法求解ax2+bx+c=0，，并将结果输出到屏幕上。请根据 b2−4ac的值，合理给出方程的根。
*备注:
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double a=0,b=0,c=0,result=0,temp=0;
	//输入方程三个参数的值
	printf("请输入方程三个参数的值\n");
	//输入三个参数
	scanf("%lf%lf%lf",&a,&b,&c);
	temp=b*b-4*a*c;
	//判断方程是否无解
	if(temp<0)
	{
	printf("方程无解\n");
	}
	//判断方程是一解还是两解，并计算方程的解
	if(temp==0)
	{
		result=(-b+sqrt(b*b-4*a*c))/(2.0*a);
	printf("方程有一解，解为%f\n",result);
	}
	//计算方程的解
	if(temp>0)
	{
		printf("方程有两解\n");
		result=(-b+sqrt(b*b-4*a*c))/(2.0*a);
	printf("解为%f\n",result);
		result=(-b-sqrt(b*b-4*a*c))/(2.0*a);
	printf("另一解为%f\n",result);
	}


return 0;
}