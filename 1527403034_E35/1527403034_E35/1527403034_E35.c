/*�ļ�����1527403034_E35.c
*���ߣ�����
*ʱ�䣺2015��11��20��
*���ܣ����������ʼ��һ��N*N�ľ��󣬲������������Խ���Ԫ�صĺ͡�
*��ע��
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main()
{
	int j,k;
	int matrix[N][N];
	int p_sum=0,n_sum=0;
	//�����ʼ��
	srand((unsigned int)time(NULL));
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++)
		{
			matrix[j][k]=rand()%10000;
		}
	}
	//���������Խ���Ԫ�صĺ�
	for(j=0;j<N;j++)
	{
		p_sum+=matrix[j][j];
		n_sum+=matrix[j][N-j];
	}
	//���
	printf("����Ϊ��\n");
	for(j=0;j<N;j++)
	{
		for(k=0;k<N;k++)
		{
			printf("%5d",matrix[j][k]);
		}
		printf("\n");
	}
	printf("���Խ��ߵĺ�Ϊ%d\n",p_sum);
	printf("���Խ��ߵĺ�Ϊ%d\n",n_sum);
	return 0;
}