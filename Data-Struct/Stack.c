#define MAX 60

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int SElemType;

//顺序栈的数据类型 结构体
typedef struct SeqStack
{
	SElemType data[MAX];// data用来存储栈中的元素
	int maxlen;//栈中最多有多少个元素
	int top;//栈顶元素的下标  -1 代表是一个空栈
}SeqStack;

SeqStack* InitStack(SeqStack *s);
void Clear_Stack(SeqStack *s);
int Stack_Is_Empty(SeqStack *s);
int Push_Stack(SeqStack *s ,SElemType x);
int Pop_Stack(SeqStack *s,SElemType *e);
int Get_Stack_Top(SeqStack *s,SElemType *e);

int main(void)
{
	int Stack_Len;//Stack_Len为栈的长度
	scanf("%d",&Stack_Len);
	SeqStack *s= InitStack(s);
	s->maxlen=Stack_Len;

	SElemType x;
	int m=1;
	while(m)
	{
		scanf("%d",&x);//此处的%d随栈的数据类型变化
		m=Push_Stack(s,x);
	}
	m=1;
	while(m)
	{
		SElemType a;
		m=Pop_Stack(s,&a);
		printf("%d ",a);//此处的%d随栈的数据类型变化
	}
	printf("\n");
	m=Stack_Is_Empty(s);	
	if(m==1)
		printf("栈已清空!\n");
	system("pause");
	return 0;
}

//初始化栈--1
SeqStack* InitStack(SeqStack *s)
{
	s->maxlen=0;
	s->top = -1;
	return s;
}

//置空栈--2
void Clear_Stack(SeqStack *s)
{
	if(s==NULL)
		return ;
	s->top=-1;
}

//判断一个栈是否为空--3
// 1 表示为空栈或不存在
// 0 表示非空栈
int Stack_Is_Empty(SeqStack *s)
{
	if(s==NULL || s->top ==-1 )
	{
		return 1;
	}
	return 0;
}

//入栈函数--4
//@s : 栈指针，表示那个栈
//@x: 要入栈的元素
//返回值 表示入栈是否成功
// 1 表成功 0 表失败
int Push_Stack(SeqStack *s ,SElemType x)
{
	//最大元素个数为1 s->top=0 
	if(s==NULL || s->top == s->maxlen-1)
	{
		return 0;
	}
	s->data[++s->top]=x;
	
	if(s->top==s->maxlen -1)
		return 0;
	else
		return 1;
}

//入栈函数--5
int Pop_Stack(SeqStack *s,SElemType *e) 
{
	if(s==NULL || s->top == -1)
	{
		return 0;
	}
	
	*e = s->data[s->top--];//3
 
	if(s->top == -1)
		return 0;
	else
		return 1;
}

//获取栈顶元素的但是不出栈--6
int Get_Stack_Top(SeqStack *s,SElemType *e)
{
	if(s==NULL || s->top == -1)
	{
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}

