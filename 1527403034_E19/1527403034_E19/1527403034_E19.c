/*�ļ�����1527403034_E19.c
*���ߣ�����
*ʱ�䣺2015��10��29��
*���ܣ���Sn=a+aa+aa... ��ֵ������a��һ�����֡�a��n�����ɼ�������
*��ע��
*/
#include<stdio.h>
int main()
{
	int a=0,i=0,j=0,n=0;
	long s=0,Sn=0;
	printf("��������a��n:\n");
	scanf("%d%d",&a,&n);
	for(i=1;i<=n;i++)
	{
		s=s*10+a;
		Sn+=s;
	}
	printf("Sn��ֵΪ%ld\n",Sn);
	return 0;
}