#define MAX 60

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//二叉树的结点
typedef struct Tree
{
	char data;
	//struct Tree *Parent;
	struct Tree *LChild;
	struct Tree *RChild;
}BiTNode,*BiTree;
//链队列的结构体
typedef struct queue 
{
	BiTree data;
	struct queue *next;
}QNode,*point_QNode;
typedef struct 
{
	QNode *front;
	QNode *rear;
}LQueue,*point_LQueue;

void Build_Tree(BiTree *root);
void LRD(BiTree root);
void Build_LQueue(point_LQueue *s);
void In_LQueue(point_LQueue q,BiTree s);
BiTree Put_LQueue(point_LQueue q);
int Empty_LQueue(point_LQueue q);
void float_trave(BiTree root);


int main(void)
{
	BiTree root;
	printf("在输入扩展先序的时候，用*表示空\n");
	Build_Tree(&root);
	printf("后序遍历结果：");
	LRD(root);
	printf("\n层遍历  结果：");
	float_trave(root);
	return 0;
}

//扩展先序建立二叉树
void Build_Tree(BiTree *root)
{
	char ch=getchar();
	if(ch=='*')
	{
		(*root)=NULL;
	}
	else
	{
		(*root)=(BiTree)malloc(sizeof(BiTNode));
		(*root)->data=ch;
		Build_Tree(&((*root)->LChild));
		Build_Tree(&((*root)->RChild));
	}
}

//后序遍历二叉树
void LRD(BiTree root)
{
	if(root)
	{
		LRD(root->LChild);
		LRD(root->RChild);
		printf("%c",root->data);
	}
}

//按层遍历二叉树(非递归)
void float_trave(BiTree root)
{
	point_LQueue Q;
	Build_LQueue(&Q);
	BiTree p;
	In_LQueue(Q,root);
	while(Empty_LQueue(Q))
	{
		p=Put_LQueue(Q);
		printf("%c",p->data);
		if(p->LChild!=NULL)
		{
			In_LQueue(Q,p->LChild);
		}
		if(p->RChild!=NULL)
		{
			In_LQueue(Q,p->RChild);
		}
	}
}

//队列的建立
void Build_LQueue(point_LQueue *s)
{
	point_LQueue q;//头指针
	point_QNode  p;//头节点
	q=(point_LQueue)malloc(sizeof(LQueue));
	p=(point_QNode)malloc(sizeof(QNode));
	p->next=NULL;
	q->front=q->rear=p;
	*s=q;
}

//入队列操作
void In_LQueue(point_LQueue q,BiTree s)
{
	point_QNode p;
	p=(point_QNode)malloc(sizeof(QNode));
	p->data=s;
	p->next=NULL;
	q->rear->next=p;
	q->rear=p;
}

//出队列操作
BiTree Put_LQueue(point_LQueue q)
{
	point_QNode p=q->front->next;
	q->front->next=p->next;
	BiTree s=p->data;
	free(p);
	if(q->front->next==NULL)
	{
		q->rear=q->front;
	}
	return s;
}

//队列判空
int Empty_LQueue(point_LQueue q)
{
	if(q->front==q->rear) return 0;
	else return 1;
}