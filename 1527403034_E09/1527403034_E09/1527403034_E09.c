/*==========================================
*文件名:1527403034_E09.c
*作者:王俊
*时间:2015.10.21
*功能:根据用户的输入3个顶点坐标计算三角形的面积和周长，如果不能构成三角形提示错误。
*备注:
*/
#include<stdio.h>
#include<math.h>
int main()
{
	double x1=0,y1=0,d1=0;
	double x2=0,y2=0,d2=0;
	double x3=0,y3=0,d3=0;
	//定义三个点的坐标和每两点之间的距离
	double c,s,p;
	//定义周长面积
	printf("请输入三角形第一个点坐标：\n");
	scanf("%lf%lf",&x1,&y1);
	//输入第一个点
	printf("请输入三角形第二个点坐标：\n");
	scanf("%lf%lf",&x2,&y2);
	//输入第二个点
	printf("请输入三角形第三个点坐标：\n");
	scanf("%lf%lf",&x3,&y3);
	//输入第三个点
	//求两点之间的距离
	d1=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
	d2=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
	d3=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
	
	//计算是否为三角形
	if((d1+d2==d3)||(d1+d3==d2)||(d2+d3==d1)){
		printf("不是三角形\n");
		return 0;
	}
	//求周长
	c=fabs(d1)+fabs(d2)+fabs(d3);
	//求面积
	p=(d1+d2+d3)/2;
	s=sqrt(p*(p-d1)*(p-d2)*(p-d3));
	//输出
	printf("周长为%f\n",c);
	printf("面积为%f\n",s);
	return 0;
}