/*文件名：1527403034_E03.c
*作者：王俊
*时间：2015年10月16日
*功能：从键盘输入一个浮点变量 r ，以 r 为半径，求相应的圆的周长和面积，求相应球体的体积和表面积
*备注：
*/
#include<stdio.h>
int main()
{
	float r=0;//定义半径
	float circle_c,circle_s;//定义圆周长，半径
	float ball_s,ball_v;//定义球面积，体积
	//输入半径
	printf("请输入半径：");
	scanf("%f",&r);
	//求圆的周长和面积
	circle_c=2*3.14*r;
	circle_s=3.14*r*r;
	//求球的面积体积
	ball_s=4.0*3.14*r*r;
	ball_v=4.0/3.0*3.14*r*r*r;
	printf("圆的周长为%3f\n圆的面积为%3f\n球的面积%3f\n球的体积%3f\n",circle_c,circle_s,ball_s,ball_v);
	return 0;
}