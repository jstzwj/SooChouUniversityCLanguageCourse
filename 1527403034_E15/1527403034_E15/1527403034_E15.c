/*�ļ�����1527403034_E15.c
*���ߣ�����
*ʱ�䣺2015��10��24��
*���ܣ�����һ��������ʾ�����������ı�����Ϣ�ܹ��ж���.
*��ע��
*/
#include<stdio.h>
int main()
{
	int money=0;
	int result=0;
//��������
	printf("����������(��Ԫ)��\n");
	scanf("%d",&money);
	//���㱾Ϣ��
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
	printf("һ��󱾽����Ϣһ����%d��Ԫ\n",result);
	return 0;
}