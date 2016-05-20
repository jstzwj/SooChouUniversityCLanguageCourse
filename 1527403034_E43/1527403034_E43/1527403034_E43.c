/*文件名：1527403034_E43.c
*作者：王俊
*时间：2015年11月25日
*功能：从键盘输入若干英文单词，所有中最大长度不超过15个字母，请编写程序对所有单词按照长度从大到小排序。
*备注：
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
	//输入
	printf("请输入若干单词：\n");
	gets(senten);
	//提取单词
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
	//冒泡排序
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
	//输出
	printf("排序结果为：\n");
	for(i=0;i<=word_len;i++)
	{
		puts(word[i]);
	}
	return 0;
}