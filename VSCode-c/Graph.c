#define MAX_VEX 10//邻接矩阵最大顶点数
#define MAX_ARC 10//邻接矩阵最大边数
#define MaxVertexNum 30//遍历数组
#define VexType char
#define MAX_STACK 10

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//邻接矩阵结点定义
typedef struct
{
	VexType vex[MAX_VEX];
	int arcs[MAX_ARC][MAX_ARC];
	int vexnum, arcnum;
	float weight;//暂时用不到，可以不赋值
}AdjMatrix;

//邻接表结点定义
typedef struct ArcNode
{
	int adjvex;
	float weight;//暂时用不到，可以不赋值
	struct ArcNode* Next;
}TableNode;
typedef struct
{
	VexType vex;
	TableNode* head;
}TableHead;
typedef struct
{
	TableHead vex[MAX_VEX];
	int vexnum, arcnum;
}AdjTable;
//定义队列
typedef struct Queue
{
     int data[MaxVertexNum];//存放图的标号
     int front;
     int rear;
}Queue;
//定义栈
typedef struct
{
    int top;
    int num[MAX_STACK];
}Stack;

bool visited[MaxVertexNum];

//邻接矩阵/表定义+操作
int Matrix_Find_SerNum(AdjMatrix* G, VexType str);//1
int Table_Find_SerNum(AdjTable* G, VexType str);//2
void Create_AdjMatrix(AdjMatrix* G);//3
void Create_AdjTable(AdjTable* G);//4
void Print_Grape_AdjMatrix(AdjMatrix* G);//5
void Print_Grape_AdjTable(AdjTable G);//6
void BFSTraverse(AdjTable *G);//7
void DFSTraverse(AdjTable *G);//8
void DFS(AdjTable *G,int i);//9
void Print_Connect(AdjTable G);//10
bool Judge(bool visit[],int T);//11




//队列操作函数的定义
bool InitQueue(Queue *q);//12
bool IsEmpty(Queue *q);//13
bool EnQueue(Queue *q, int e);//14
bool Dequeue(Queue *q,int *e);//15

//栈操作函数的定义
Stack* init();//16
void push(Stack *s,int v);//17
int pop(Stack *s);//18
int check(Stack *s,int v);//19
void show(Stack* s);//20
int findfirst(AdjTable *G,int i);//21
int findnext(AdjTable *G,int i,int v);//22
void DFS_2(int B,int E,Stack* s,AdjTable *G);//23

int main(void)
{
	/*
	AdjMatrix Graph;
	Create_AdjMatrix(&Graph);
	Print_Grape_AdjMatrix(&Graph);
	*/
	AdjTable Graph;
	Create_AdjTable(&Graph);
	Print_Grape_AdjTable(Graph);
	BFSTraverse(&Graph);
	DFSTraverse(&Graph);
	Print_Connect(Graph);
	Stack *s;
	s=init();
	DFS_2(0,2,s,&Graph);
	system("pause");
	return 0;
}

void Create_AdjMatrix(AdjMatrix* G)
{
	printf("请输入图的结点：");
	gets(G->vex);
	//gets_s可以等价换成gets,下同
	G->vexnum = strlen(G->vex);
	for (int i = 0; i < G->vexnum; i++)
		for (int j = 0; j < G->vexnum; j++)
			G->arcs[i][j] = 0;
	printf("请输入图的节点间关系数：");
	scanf("%d", &G->arcnum);
	getchar();
	for (int i = 0; i < G->arcnum; i++)
	{
		VexType Temp_Relat[2];
		printf("请输入第%d组关系:", i + 1);
		gets(Temp_Relat);
		int row = Matrix_Find_SerNum(G, Temp_Relat[0]);
		int col = Matrix_Find_SerNum(G, Temp_Relat[1]);
		G->arcs[row][col] = G->arcs[col][row] = 1;
	}
}
void Create_AdjTable(AdjTable* G)
{
	printf("请输入图的结点数:");
	scanf("%d",&G->vexnum);
	getchar();
	VexType Temp_Vex[MAX_VEX];
	printf("请输入图的结点:");
	gets(Temp_Vex);
	for (int i = 0; i < G->vexnum; i++)
	{
		G->vex[i].vex = Temp_Vex[i];
		G->vex[i].head = NULL;
	}
	printf("请输入图的节点关系数:");
	scanf("%d", &G->arcnum);
	getchar();
	for (int i = 0; i < G->arcnum; i++)
	{
		printf("请输入第%d个关系:", i+1);
		VexType Temp_Relat[2];
		gets(Temp_Relat);
		int row = Table_Find_SerNum(G, Temp_Relat[0]);
		int col = Table_Find_SerNum(G, Temp_Relat[1]);
		TableNode* left = (TableNode*)malloc(sizeof(TableNode));
		TableNode* right = (TableNode*)malloc(sizeof(TableNode));
		left->adjvex = row;//0
		right->adjvex = col;//1
		//头插法建立
		left->Next=G->vex[col].head;
		G->vex[col].head=left;
		right->Next=G->vex[row].head;
		G->vex[row].head=right;
	}
}
int Matrix_Find_SerNum(AdjMatrix* G, VexType str)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (G->vex[i] == str)
			return i;
	}
	return 0;
}
int Table_Find_SerNum(AdjTable* G, VexType str)
{
	for (int i = 0; i < G->vexnum; i++)
	{
		if (str == G->vex[i].vex)
			return i;
	}
	return 0;
}
void Print_Grape_AdjMatrix(AdjMatrix* G)
{
	puts(G->vex);
	printf("  ");
	for (int i = 0; i < G->vexnum; i++)
		printf("%c ", G->vex[i]);
	printf("\n");
	for (int i = 0; i < G->vexnum; i++)
	{
		printf("%c ", G->vex[i]);
		for (int j = 0; j < G->vexnum; j++)
		{
			printf("%d ", G->arcs[i][j]);
		}
		printf("\n");
	}
}
void Print_Grape_AdjTable(AdjTable G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%c", G.vex[i].vex);
		for(TableNode *p=G.vex[i].head;p;p=p->Next)
		{
			printf("->%d",p->adjvex);
		}
		printf("->NULL\n");
	}
}
bool InitQueue(Queue *q)
{
     q->front=0;
     q->rear=0;
     return true;
}
bool IsEmpty(Queue *q)
{
    if(q->front==q->rear)return true;
    return false;
}
bool EnQueue(Queue *q, int e)
{
    if((q->rear+1)%MaxVertexNum==q->front)return false;
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MaxVertexNum;
    return true;
}
bool Dequeue(Queue *q,int *e)
{
    if(q->front==q->rear)return false;
    *e=q->data[q->front];
    q->front=(q->front+1)%MaxVertexNum;
    return true;
}
void BFSTraverse(AdjTable *G)
{
	printf("广搜结果如下:");
    //初始化visited数组
    for(int i=0;i<G->vexnum;i++)
     visited[i]=false;
    Queue q;
    InitQueue(&q);//初始化队列

    for(int i=0;i<G->vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=true;
            printf("%c->",G->vex[i].vex);//遍历当前元素
            EnQueue(&q,i);
        }
        while(!IsEmpty(&q))
        {
            int k;
            Dequeue(&q,&k);
            TableNode* t=G->vex[k].head;//拿到相邻第一个边结点
            while(t)
            {
                if(!visited[t->adjvex])
                {
                    visited[t->adjvex]=true;
                    printf("%c->",G->vex[t->adjvex].vex);//遍历当前结点并且入队
                    EnQueue(&q,t->adjvex);
                }
                t=t->Next;//向右移动
            }
        }
    }
	printf("NULL\n");
}
void DFSTraverse(AdjTable *G)
{
	printf("深搜结果如下:");
    for(int i=0;i<G->vexnum;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<G->vexnum;i++)
    {
        if(!visited[i]) DFS(G,i);
    }
	printf("NULL\n");
}
void DFS(AdjTable *G,int i)
{
    visited[i]=true;
    printf("%c->",G->vex[i].vex);
    TableNode *p=G->vex[i].head;
    while(p)
    {
        if(!visited[p->adjvex])
        {
            DFS(G,p->adjvex);
        }
        p=p->Next;
    }
}
void Print_Connect(AdjTable G)
{
	printf("连通分支打印如下:\n");
	for(int i=0;i<G.vexnum;i++)
	{
		visited[i]=false;
	}
	for(int i=0,j=0;Judge(visited,G.vexnum)&& i<G.vexnum;i++)
	{
		if(!visited[i])
		{
			printf("第%d个连通分支:",j+1);
			DFS(&G,i);
			printf("NULL\n");
			j++;
		}
	}
}
bool Judge(bool visit[],int T)
{
	for(int i=0;i<T;i++)
	{
		if(!visit[i])
		{
			return true;
		}
	}
	return false;
}
Stack* init()
{
    Stack *s;
    s = (Stack*)malloc(sizeof(Stack));
    if(s==NULL)
    {
        printf("分配失败\n");
        return 0;
    }
    s->top=-1;
    return s;
}
void push(Stack *s,int v)
{
    if(s->top == MAX_STACK -1)
        return;
    s->num[++s->top] = v;
}
int pop(Stack *s)
{
    if(s->top == -1)
        return 0;
    else
        return s->num[s->top--];
}
int check(Stack *s,int v)
{
    int i;
    for(i=0;i<=s->top;i++)
    {
        if(v==s->num[i])
            return 1;
    }
    return 0;
}
void show(Stack* s)
{
    int m = s->top;
    int a = 0;
    while(a<=m)
    {
        printf("%d",s->num[a++]);
    }
    printf("\n");
}
int findfirst(AdjTable *G,int i)
{
    TableNode *p;
    if(G->vex[i].head)
    {
        p=G->vex[i].head;
        return p->adjvex;
    }
    else 
    {        
        return -1;
    }
}
int findnext(AdjTable *G,int i,int v)
{
    TableNode *p,*q;
    if(G->vex[v].head)
    {
        p=G->vex[v].head;
        while(p->adjvex!=i)
            p=p->Next;
        q = p->Next;
        if(q)
        {
            //printf("下一个顶点是%d\n",q->data);
            return q->adjvex;
        }
        else
             return -1;
    }
    else 
        return -1;
}
void DFS_2(int B,int E,Stack* s,AdjTable *G)
{
    int i;
    push(s,B);
    if(E==B)
	{
        show(s);
        pop(s);
        return;
    }
    for(i=findfirst(G,B);i!=-1;i=findnext(G,i,B))
	{
        //show(s);
        if(check(s,i)&&i!=E)
            continue;
        DFS_2(i,E,s,G);
    }
    pop(s);
}


