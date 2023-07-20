#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef float DataType; //结点权值的数据类型
typedef char NameType;//结点名称的数据类型

//采用静态链表进行构建哈夫曼结点
typedef struct //单个结点
{
	NameType name;//名称
	DataType weight; //权值
	int parent; //父节点
	int lc, rc; //左右孩子
}Node,*HuffmanTree;

void Put_Data(HuffmanTree q,int T);
void Print_HuffTree(HuffmanTree q,int T); 
void Find_Min_Miner(HuffmanTree q,int n,int *s1,int *s2);
void Build_HuffTree(HuffmanTree q,int T);
void Create_HuffCode(HuffmanTree q,NameType s,int T,int flag);
void Encode_Char(HuffmanTree q,int T);
int main(void)
{
	int T;
	scanf("%d",&T);
	Node str[2*T];
	Put_Data(str,T);
	Build_HuffTree(str,T);
	Print_HuffTree(str,T);
	int i;
	for(i=1;i<=T;i++)	Create_HuffCode(str,str[i].name,T,1);
	printf("\n");
	Encode_Char(str,T);
	return 0;
}

//哈夫曼编码的生成--按照字母名称查找并生成编码
void Create_HuffCode(HuffmanTree q,NameType s,int T,int flag)
{
	int i,j,jk=0,number,str1[10];
	for(i=0;i<10;i++) str1[i]=-1;
	for(i=1;i<=T;i++)
	{
		if(q[i].name==s) break;
	}
	while(q[i].parent)
	{
		j=q[i].parent;
		if(q[j].lc==i)  str1[jk]=0;
		else   str1[jk]=1;
		i=j;jk++;
	}
	char str2[jk];
	for(i=0;i<jk;i++)  str2[i]=str1[jk-i-1]+48;
	str2[jk]='\0';
	if(flag)
	{
		printf("%c %s\n",s,str2);
	}
	else
	{
		printf("%s",str2);
	}
	
}

//哈夫曼树的建立
void Build_HuffTree(HuffmanTree q,int T)
{
	int i;
	for(i=T+1;i<2*T;i++)
	{
		int s1,s2;
		Find_Min_Miner(q,i-1,&s1,&s2);
		q[i].weight=q[s1].weight+q[s2].weight;
		q[s1].parent=q[s2].parent=i;
		q[i].lc=s1;
		q[i].rc=s2;
		q[i].name='N';
		q[i].parent=0;
	}	
}

//数据输入函数
//前提是输入的n个字符不能重复
void Put_Data(HuffmanTree q,int T)
{
	int i=1;
	getchar();
	while(i<=T)
	{
		scanf("%c %f",&q[i].name,&q[i].weight);
		getchar();
		q[i].lc=q[i].rc=q[i].parent=0;
		i++;
	}
}

//静态链表数据查看
void Print_HuffTree(HuffmanTree q,int T)
{
	int i;
	printf("哈夫曼树为:\n");
	printf("下标   名称   权值     父结点   左孩子   右孩子\n");
	for(i=1;i<2*T;i++)
	{
		printf("%-4d   %-4c   %-6.2lf   %-6d   %-6d   %-6d\n",i,q[i].name,q[i].weight,q[i].parent,q[i].lc,q[i].rc);
	}
	printf("\n");
}

//筛选最小的两个数
void Find_Min_Miner(HuffmanTree q,int n,int *s1,int *s2)
{
	//s1,s2是当前哈夫曼表的截至n的最小值和次小值,且s1<s2
	int i,s;
	for(i=1;i<=n;i++)
	{
		if(q[i].parent==0)
		{
			s=i;
			break;
		}
	}
	for(i=s+1;i<=n;i++)
	{
		if(q[i].parent==0 && q[i].weight < q[s].weight)  s=i;
	}
	*s1=s;
	for(i=1;i<=n;i++)
	{
		if(q[i].parent==0 && i!= *s1)
		{
			s=i;
			break;
		}
	}
	for(i=s+1;i<=n;i++)
	{
		if(q[i].parent==0 && q[i].weight<q[s].weight && i!=*s1)  s=i;
	}
	*s2=s;
}

void Encode_Char(HuffmanTree q,int T)
{
	int i;
	for(i=1;i<=T;i++)
	{
		Create_HuffCode(q,q[i].name,T,0);
	}
}
/*
8
a 0.05
b 0.29
c 0.07
d 0.08
e 0.14
f 0.23
g 0.03
h 0.11
*/