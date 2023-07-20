#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct 
{
	char AF[130];
	int data;
}Fold;

void Encode(Fold *S,char *p1,char *q2,char *str);
void Sort(Fold *S,int num);
void Print_Fold(Fold *S,int elem);

int main()
{
	//输入的范围是2^8,如果数据超过这个范围需要修改该值
	char Str[260],Seq1[9],Seq2[9];
	scanf("%s",Str);
	scanf("%s",Seq1);
	scanf("%s",Seq2);
	Fold Af_Str[strlen(Str)];
	int i;
	Encode(Af_Str,Seq1,Seq2,Str);
	return 0;
}

//加密函数
void Encode(Fold *S,char *p1,char *q2,char *str) 
{
	strcpy(S[0].AF,str);
	S[0].data=0;
	int i,j,k;
	//第i次折叠
	for(i=0;i<strlen(p1);i++)
	{
		if(p1[i]=='0'&&q2[i]=='0')
		{
			//循环行折叠
			for(j=0;j<pow(2,i);j++)
			{
				int t=pow(2,i);
				//行间字折叠
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第一个for循环解决新增结构体字符串
				{
					S[t+j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)/2-1-k];
				}
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第二个for循环解决被对折结构体字符串
				{
					S[t-1-j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)/2+k];
				}
				S[t+j].AF[k]='\0';
				S[t-1-j].AF[k]='\0';
				S[t+j].data=j;//新增字符串数组序数
				S[t-1-j].data=2*t-1-j;//被对折字符串数组序数
			}
		}

		if(p1[i]=='0'&&q2[i]=='1')
		{
			//循环行折叠
			for(j=0;j<pow(2,i);j++)
			{
				int t=pow(2,i);
				//行间字折叠
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第一个for循环解决新增结构体字符串
				{
					S[t+j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)/2-1-k];
				}
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第二个for循环解决被对折结构体字符串
				{
					S[t-1-j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)/2+k];
				}
				S[t+j].AF[k]='\0';
				S[t-1-j].AF[k]='\0';
				S[t+j].data=t+j;//新增字符串数组序数
			}
		}

		if(p1[i]=='1'&&q2[i]=='0')
		{
			//循环行折叠
			for(j=0;j<pow(2,i);j++)
			{
				int t=pow(2,i);
				//行间字折叠
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第一个for循环解决新增结构体字符串
				{
					S[t+j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)-1-k];
				}
				S[t+j].AF[k]='\0';
				S[t-1-j].AF[k]='\0';
				S[t+j].data=j;//新增字符串数组序数
				S[t-1-j].data=2*t-1-j;//被对折字符串数组序数
			}
		}

		if(p1[i]=='1'&&q2[i]=='1')
		{
			//循环行折叠
			for(j=0;j<pow(2,i);j++)
			{
				int t=pow(2,i);
				//行间字折叠
				for(k=0;k<strlen(S[t-1-j].AF)/2;k++)//第一个for循环解决新增结构体字符串
				{
					S[t+j].AF[k]=S[t-1-j].AF[strlen(S[t-1-j].AF)-1-k];
				}
				S[t+j].AF[k]='\0';
				S[t-1-j].AF[k]='\0';
				S[t+j].data=t+j;//新增字符串数组序数
			}
		}
		//折叠一次，排一次序
		Sort(S,pow(2,i+1));
		Print_Fold(S,i);
	}
}

//结构排序函数
void Sort(Fold *S,int num)
{
	Fold temp;
	//此处可优化，我为了省时间用的冒泡排序，可以改为快排
	int i,j;
	for(i=0;i<num-1;i++)
	{
		for(j=0;j<num-1;j++)
		{
			if(S[j].data>S[j+1].data)
			{
				temp=S[j];
				S[j]=S[j+1];
				S[j+1]=temp;
			}
		}
	}
}

//结构体打印函数
void Print_Fold(Fold *S,int elem)
{
	int i;
	printf("第%d次加密后为:\n",elem);
	for(i=0;i<pow(2,elem);i++)
	{
		printf("%s\n",S[i].AF);
	}
}
