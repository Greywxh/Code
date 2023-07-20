#define MAX 100
#include<stdio.h>
typedef struct 
{
	int row,col;
	int value;
}Triple;
typedef struct 
{
	Triple data[MAX+1];
	int rows,cols,nums;//行，列，非零总数
}TSM;

void Push_Data(TSM *p);
void Print_Data(TSM *p);
void Trans_Data(TSM *p,TSM *q);
void Add_A_And_B(TSM *p,TSM *q,TSM *pq);
void Del_A_And_B(TSM *p,TSM *q,TSM *pq);
void Multiply_A_And_B(TSM *p,TSM *q,TSM *pq);

int main(void)
{
	TSM A,B,C;
	Push_Data(&A);
	Push_Data(&B);
	
//	Del_A_And_B(&A,&B,&C);
//	Add_A_And_B(&A,&B,&C);
//	Print_Data(&A);
//	Trans_Data(&A,&B);

    Print_Data(&A);
	printf("\n");
	Print_Data(&B);
	printf("\n");
	Print_Data(&C);
	return 0;
}

void Push_Data(TSM *p)
{
	/*定义行列非零总数*/
	int LH_rows,LH_cols,LH_nums;
	scanf("%d %d %d",&LH_rows,&LH_cols,&LH_nums);
	p->rows=LH_rows;
	p->cols=LH_cols;
	p->nums=LH_nums;
	

	/*录入数据*/
	int i=0;
	int LH_row,LH_col,LH_value;
	for(i=0;i<LH_nums;i++)
	{
		scanf("%d %d %d",&p->data[i].row,&p->data[i].col,&p->data[i].value);		
	}	
}
void Print_Data(TSM *p)
{
	int i,j,elem=0;
	for(i=1;i<=p->rows;i++)//行打印
	{
		for(j=1;j<=p->cols;j++)//列打印
		{
			if(i==p->data[elem].row && j==p->data[elem].col)
			{
				printf("%5d",p->data[elem].value);
				elem++;
			}
			else
			{
				printf("    0");
			}
		}
		printf("\n");
	}
}
void Trans_Data(TSM *p,TSM *q)
{
	/*统计列数组*/
	int LH_Num[p->cols+1],i;
	//列数组置零操作
	for(i=1;i<=p->cols;i++)
	{
		LH_Num[i]=0;
	}
	for(i=0;i<p->nums;i++)
	{
		LH_Num[p->data[i].col]++;
	}
	//开始位置
	int LH_Position[p->nums+1];
	LH_Position[1]=1;
	for(i=2;i<=p->cols;i++)
	{
		LH_Position[i]=LH_Position[i-1]+LH_Num[i-1];
	}

	for(i=0;i<p->nums;i++)
	{
		int LH_col=p->data[i].col;
		int elem=LH_Position[LH_col]-1;
		q->data[elem].row=p->data[elem].col;
		q->data[elem].col=p->data[elem].row;
		q->data[elem].value=p->data[elem].value;
		LH_Position[LH_col]++;
	}
	q->cols=p->rows;
	q->rows=p->cols;
	q->nums=q->nums;
}
void Add_A_And_B(TSM *p,TSM *q,TSM *pq)
{
	int i,j,flag=0;
	int elem1=0,elem2=0,elem3=0;//1对于q用，2对于q用,3对于pa用
	
	for(i=1;i<=q->rows;i++)
	{
		for(j=1;j<=q->cols;j++)
		{
			if(q->data[elem1].row==i && q->data[elem1].col==j)
			{
				pq->data[elem3].value=0;
				pq->data[elem3].value+=q->data[elem1].value;
				elem1++;
				flag=1;
			}
			if(p->data[elem2].row==i && p->data[elem2].col==j)
			{
				if(flag==0) pq->data[elem3].value=0;
				pq->data[elem3].value+=p->data[elem2].value;
				elem2++;
				flag=1;
			}
			if(flag==1)
			{
				pq->data[elem3].row=i;
				pq->data[elem3].col=j;
				elem3++;
			}
			flag=0;
		}
	}
	pq->cols=q->cols;
	pq->rows=q->rows;
	pq->nums=elem3;
}
void Del_A_And_B(TSM *p,TSM *q,TSM *pq)
{
	int i,j,flag=0;
	int elem1=0,elem2=0,elem3=0;//1对于q用，2对于q用,3对于pa用
	
	for(i=1;i<=q->rows;i++)
	{
		for(j=1;j<=q->cols;j++)
		{
			if(p->data[elem2].row==i && p->data[elem2].col==j)
			{
				pq->data[elem3].value=0;
				pq->data[elem3].value=p->data[elem2].value;
				elem2++;
				flag=1;
			}
			if(q->data[elem1].row==i && q->data[elem1].col==j)
			{
				if(flag==0) pq->data[elem3].value=0;
				pq->data[elem3].value-=q->data[elem1].value;
				elem1++;
				flag=1;
			}
			if(flag==1)
			{
				pq->data[elem3].row=i;
				pq->data[elem3].col=j;
				elem3++;
			}
			flag=0;
		}
	}
	pq->cols=q->cols;
	pq->rows=q->rows;
	pq->nums=elem3;
}
void Multiply_A_And_B(TSM *p,TSM *q,TSM *pq)
{
	TSM LH;
	TSM *qp=&LH;
	Trans_Data(q,qp);//对q进行转置

/*
	//统计列数组
	int LH_p_Num[p->cols+1],i;
	//列数组置零操作
	for(i=1;i<=p->cols;i++)
	{
		LH_p_Num[i]=0;
	}
	for(i=0;i<p->nums;i++)
	{
		LH_p_Num[p->data[i].col]++;
	}
	//开始位置
	int LH_p_Position[p->nums+1];
	LH_p_Position[1]=1;
	for(i=2;i<=p->cols;i++)
	{
		LH_p_Position[i]=LH_p_Position[i-1]+LH_p_Num[i-1];
	}
	
	//统计列数组
	int LH_qp_Num[p->cols+1],i;
	//列数组置零操作
	for(i=1;i<=p->cols;i++)
	{
		LH_qp_Num[i]=0;
	}
	for(i=0;i<p->nums;i++)
	{
		LH_qp_Num[p->data[i].col]++;
	}
	//开始位置
	int LH_qp_Position[p->nums+1];
	LH_qp_Position[1]=1;
	for(i=2;i<=p->cols;i++)
	{
		LH_qp_Position[i]=LH_qp_Position[i-1]+LH_qp_Num[i-1];
	}
*/
	int i,j,k,data=0;
	int elem1=0,elem2=0,elem3=0;//1监视p，2监视qp，3监视pq
	pq->rows=p->rows;
	pq->cols=q->cols;
	for(i=1;i<=pq->rows;i++)
	{
		for(j=1;j<=pq->cols;j++)
		{
			for(k=1;k<=p->cols;k++)//控制当前的类成运算
			{
				if(p->data[elem1].row==i && p->data[elem1].col==k)
				{
					elem1++;
					if (qp->data[elem2].row==j && qp->data[elem2].col==k)
					{
						data+=p->data[elem1-1].value * qp->data[elem2].value;
						elem2++;
					}	
				}
			}
			pq->data[elem3].col=j;
			pq->data[elem3].row=i;
			pq->data[elem3].value=data;
			elem3++;
		}
	}
	pq->nums=elem3;
}
