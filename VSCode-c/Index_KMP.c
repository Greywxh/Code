//先写出kmp,再用kmp去查找替换
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void Build_Next(char S[]);

int main(void)
{
	char str1[10]="abaabcacab";
	Build_Next(str1);
	system("pause");
	return 0;
}

void Build_Next(char S[])
{
	char next[11]={'0'};//next数组
	int prefix_len=0;//共同前后缀
	int i=1;
	while (i<strlen(S))
	{
		if(S[prefix_len]==S[i])
		{
			prefix_len++;
			next[i]=prefix_len;
			i++;
		}
		else
		{
			if(prefix_len==0)
			{
				next[i]=0;
				i++;
			}
			else
			{
				prefix_len=next[prefix_len-1];
			}
		}
	}
	for (i=0;i<10;i++)
	{
		printf("%d",next[i]);
	}
}