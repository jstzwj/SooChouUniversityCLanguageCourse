/*�ļ�����1527403034_E43.c
*���ߣ�����
*ʱ�䣺2015��11��25��
*���ܣ��Ӽ�����������Ӣ�ĵ��ʣ���������󳤶Ȳ�����15����ĸ�����д��������е��ʰ��ճ��ȴӴ�С����
*��ע��
*/
#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int i=0,j=0;
	char word[N][16]={0};
	int len[N]={0};
	int word_len=0;
	char senten[N*18]={0};
	int temp;
	char temp2[16];
	//����
	printf("���������ɵ��ʣ�\n");
	gets(senten);
	//��ȡ����
	for(i=0;senten[i]!='\0';i++)
	{
		word[word_len][j]=senten[i];
		j++;
		len[word_len]++;
		if(senten[i]==' '&&senten[i+1]!=' ')
		{
			word_len++;
			j=0;
		}
	}
	//ð������
	for(i=0;i<=word_len;i++)
	{
		for(j=i;j>0;j--)
		{
			if(len[j]>len[j-1])
			{
				temp=len[j];
				len[j]=len[j-1];
				len[j-1]=temp;
				strcpy(temp2,word[j]);
				strcpy(word[j],word[j-1]);
				strcpy(word[j-1],temp2);
			}
		}
	}
	//���
	printf("������Ϊ��\n");
	for(i=0;i<=word_len;i++)
	{
		puts(word[i]);
	}
	return 0;
}