/*�ļ�����1527403034_E03.c
*���ߣ�����
*ʱ�䣺2015��10��16��
*���ܣ��Ӽ�������һ��������� r ���� r Ϊ�뾶������Ӧ��Բ���ܳ������������Ӧ���������ͱ����
*��ע��
*/
#include<stdio.h>
int main()
{
	float r=0;//����뾶
	float circle_c,circle_s;//����Բ�ܳ����뾶
	float ball_s,ball_v;//��������������
	//����뾶
	printf("������뾶��");
	scanf("%f",&r);
	//��Բ���ܳ������
	circle_c=2*3.14*r;
	circle_s=3.14*r*r;
	//�����������
	ball_s=4.0*3.14*r*r;
	ball_v=4.0/3.0*3.14*r*r*r;
	printf("Բ���ܳ�Ϊ%3f\nԲ�����Ϊ%3f\n������%3f\n������%3f\n",circle_c,circle_s,ball_s,ball_v);
	return 0;
}