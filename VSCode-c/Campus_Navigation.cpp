#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define inf 99999999
using namespace std;
void kaishidaohang();
void daohanglan();
int map[20][20],book[20],dis[20];
 
struct A		
{
	char name[100];
	char jieshao[800];
}q[15];
 
void cuntu() 
{
	int i,j;
	strcpy(q[1].name,"西一门");
	strcpy(q[1].jieshao,"学生进出的门");
	strcpy(q[2].name,"操场");
	strcpy(q[2].jieshao,"含羽毛球场和乒乓球场");
	strcpy(q[3].name,"逸夫楼");
	strcpy(q[3].jieshao,"上课和办公的楼"); 
	strcpy(q[4].name,"安美公寓");
	strcpy(q[4].jieshao,"女生公寓，分为安美北和安美南");
	strcpy(q[5].name,"安悦公寓");
	strcpy(q[5].jieshao,"男生公寓，分为安悦北和安悦南"); 
	strcpy(q[6].name,"菜鸟驿站");
	strcpy(q[6].jieshao,"可以接收绝大多数快递");
	strcpy(q[7].name,"餐厅");
	strcpy(q[7].jieshao,"东区食堂，有民族餐厅和东升餐厅");
	strcpy(q[8].name,"天桥");
	strcpy(q[8].jieshao,"连接东西区的桥");
	strcpy(q[9].name,"西二门");
	strcpy(q[9].jieshao,"家属区进出的门");
	strcpy(q[10].name,"家属区");
	strcpy(q[10].jieshao,"教师及其家属住宅区");

	for(i=1;i<=14;i++)
		for(j=1;j<=14;j++)
		{
			if(i==j)
				map[i][j]=0;
			else
				map[i][j]=inf;
		}
	map[1][3]=40;map[1][7]=60;map[1][8]=70;
	map[2][3]=10;
	map[3][4]=10;
	map[4][5]=10;
	map[5][6]=20;
	map[6][7]=35;
	map[7][8]=25;
	map[8][9]=15;
	map[9][10]=30;

	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			map[j][i]=map[i][j];

}
 
void liebiao() 
{
	system("cls");		
	printf("\n\n\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t\t * *                     *校园状况*                      * *\n");
	printf("\t\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t\t * *                          <2>操场                    * *\n");
	printf("\t\t\t\t\t * * <1>                        ||                       * *\n");
	printf("\t\t\t\t\t * * 西                         ||                       * *\n");
	printf("\t\t\t\t\t * * 一  =====================逸夫楼<3>                   * *\n");
	printf("\t\t\t\t\t * * 门      ||                 ||                       * *\n");
	printf("\t\t\t\t\t * *         ||                 ||=====安美公寓<4>        * *\n");
	printf("\t\t\t\t\t * *         ||                 ||                       * *\n");
	printf("\t\t\t\t\t * *         ||                 ||=====安悦公寓<5>        * *\n");
	printf("\t\t\t\t\t * *         ||                 ||                       * *\n");
	printf("\t\t\t\t\t * *         ||                 ||                       * *\n");
	printf("\t\t\t\t\t * *         ||                 ||==========<6>菜鸟驿站   * *\n");
	printf("\t\t\t\t\t * *         ||                 ||                       * *\n");
	printf("\t\t\t\t\t * *         ||   <7>   东      ||                       * *\n");
	printf("\t\t\t\t\t * *         ||   民族  升========                        * *\n");
	printf("\t\t\t\t\t * *         ||== 餐厅  餐                               * *\n");
	printf("\t\t\t\t\t * *<8>      ||         厅                               * *\n");
	printf("\t\t\t\t\t * *天       ||                                          * *\n");
	printf("\t\t\t\t\t * *桥 ======||                                          * *\n");
	printf("\t\t\t\t\t * *         ||                                          * *\n");
	printf("\t\t\t\t\t * *西       ||                                          * *\n");
	printf("\t\t\t\t\t * *二 =======================<10>家属区                 * *\n");
	printf("\t\t\t\t\t * *门                                                   * *\n");
	printf("\t\t\t\t\t * *<9>                                                  * *\n");
	printf("\t\t\t\t\t * *                                                     * *\n");
	printf("\t\t\t\t\t * ******************************************************* *\n");
	printf("\t\t\t\t\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
}
 
//查询方式 
int chaxunfangshi(int x)
{
	int i;
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t                  *  请输入查询方式*\n\n");
	printf("\t\t\t\t\t                  1、输入景点编号查询\n\n");
	printf("\t\t\t\t\t                  2、输入景点名称查询\n\n");
	printf("\t\t\t\t\t                  0、返回上一界面\n\n\n\n\n\n\n");
	scanf("%d",&i);
	return i;
} 
 
//查询景点编号 
int bianhao(char s[])
{
	int f=0,i;
	for(i=1;i<=26;i++)
	{
		if(strcmp(q[i].name,s)==0)
			return i;
	}
	return -1;
}

//用
void Dijkstra(int v0,int s)
{
	int min,i,j,u,v;
	int p[110],l[110];
	memset(p,-1,sizeof(p));
	memset(l,0,sizeof(l));
	memset(book,0,sizeof(book));
	for(i=1;i<=26;i++)
	{
		dis[i]=map[v0][i];
		if(dis[i]<inf)			 
			p[i]=v0;
	}
		
	book[v0]=1;
	
	for(i=1;i<11;i++)
	{
		min=inf;
		for(j=1;j<=11;j++)	
		{
			if(book[j]==0&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		book[u]=1;			//标记该点 
		for(v=1;v<=11;v++)
		{
			if(book[v]==0&&dis[v]>dis[u]+map[u][v])
			{
				p[v]=u;	
				dis[v]=dis[u]+map[u][v];
			}
		}
	}
	v=s;
	i=1;
	while(p[v]!=v0)
	{
		
		l[i++]=p[v];
		v=p[v];
	}
	printf("\n");
	u=i-1;
	printf("路线为：\n");
	printf("%s--->",q[v0].name);
	for(i=u;i>=1;i--)
		printf("%s--->",q[l[i]].name); 
	printf("%s\n",q[s].name);
	printf("最短路径长度为：%d 米\n",dis[s]);
}
 
//导航界面 
void kaishidaohang()
{
	int x,m,n,u,v,i,j;
	char c[100];
	system("cls");			//清屏 
	printf("\n\n\n");
	printf("\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\t\t\t\t ■                                                    ■\n");
	printf("\t\t\t\t ■欢 迎 使 用 西 安 邮 电 大 学 东 区 校 园 导 航 系 统 \n");
	printf("\t\t\t\t ■                                                    ■\n");
	printf("\t\t\t\t ■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("\n\n\n");
	printf("\t\t\t                      1、查阅所有地点;               \n\n");
	printf("\t\t\t                      2、查询任意地点信息;           \n\n");
	printf("\t\t\t                 3、查询任意两景点间的最短路径;       \n\n");
	printf("\t\t\t                      4、返回至主界面;               \n\n");
	printf("\n\n\n");
	
	while(1) 
	{
		scanf("%d",&x);
		if(x==1)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					printf("请输入当前所在地点编号：\n"); 
					scanf("%d",&n);
					while(1)
					{
						if(n>=1&&n<=10)
						{
							for(i=1;i<=10;i++)
							{
								if(i!=n)
									Dijkstra(n,i);
							}
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n该地点不存在！请重新输入地点编号：\n");
							scanf("%d",&n);
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					printf("请输入当前所在地点名称：\n");
					scanf("%s",c);
					n=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							for(i=1;i<=26;i++)
							{
								if(i!=n)
									Dijkstra(n,i);
							}
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n该地点不存在！请重新输入地点名称：\n");
							scanf("%s",c);
							n=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d",&v);
				}
			}
			break;
		}
		else if(x==2)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					printf("请输入地点编号：\n"); 
					scanf("%d",&n);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							printf("\n\n%s\n\n%s\n\n",q[n].name,q[n].jieshao);
							printf("按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n该地点不存在！请重新输入地点编号：\n");
							scanf("%d",&n);
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					printf("请输入地点名称：\n");
					scanf("%s",c);
					n=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26)
						{
							printf("\n\n%s\n\n%s\n\n",q[n].name,q[n].jieshao);
							printf("按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n该地点不存在！请重新输入地点名称：\n");
							scanf("%s",c);
							n=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d",&v);
				}
			}
			break;
		}
		else if(x==3)
		{
			v=chaxunfangshi(x);
			while(1)
			{
				if(v==1)
				{
					liebiao();
					printf("请输入起点地点编号：\n");
					scanf("%d",&n);
					printf("\n请输入终点地点编号：\n");
					scanf("%d",&m);
					while(1)
					{
						if(n>=1&&n<=10&&m>=1&&m<=10&&n!=m)
						{
							Dijkstra(n,m);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点地点编号：\n");
							scanf("%d",&n);
							printf("\n请输入终点地点编号：\n");
							scanf("%d",&m);
						}
					}
					break;
				}
				else if(v==2)
				{
					liebiao();
					printf("请输入起点地点名称：\n");
					scanf("%s",c);
					n=bianhao(c);
					printf("\n请输入终点地点名称：\n");
					scanf("%s",c);
					m=bianhao(c);
					while(1)
					{
						if(n>=1&&n<=26&&m>=1&&m<=26&&n!=m)
						{
							Dijkstra(n,m);
							printf("\n\n按回车键返回至导航系统界面\n\n");
							getchar();getchar();
							kaishidaohang();
							break;
						}
						else
						{
							printf("\n输入不合法！请重新输入！\n\n");
							printf("请输入起点地点名称：\n");
							scanf("%s",c);
							n=bianhao(c);
							printf("\n请输入终点地点名称：\n");
							scanf("%s",c);
							m=bianhao(c);
						}
					}
					break;
				}
				else if(v==0)
				{
					kaishidaohang();
					break;
				}
				else
				{
					printf("\n\n输入错误请重新输入！\n\n");
					scanf("%d",&v);
				}
			}
			break;
		}
		else if(x==4)
		{
			daohanglan();
			break;
		}
		else
		{
			printf("\n\n输入错误！请重新输入！\n");
		}
	}
	
}
 
//导航栏主界面 
void daohanglan()
{
	system("cls");		//清屏 
	int m;
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t\t    *----------------------主界面------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------1、进入导航系统---------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------2、退出程序-------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	scanf("%d",&m);
	while(1)
	{
		if(m==1)
		{
			kaishidaohang();
			break;
		}
		else if(m==2)
		{
			system("cls");
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
			printf("\t\t\t\t\t∴∵                      ∴∵\n");
			printf("\t\t\t\t\t∴∵      欢 迎 使 用     ∴∵\n");
			printf("\t\t\t\t\t∴∵                      ∴∵\n");
			printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
			printf("\n\n\n"); 
			break;
		}
		else
		{
			printf("\n\n\n\t\t输入错误请重新输入！\n\n\n\n");
			scanf("%d",&m); 
		}
	}
	
}
 
//欢迎进入 
void zhujiemian()
{
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *---------------------Welcome!-----------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *-----------------邮电东区导航系统-------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *-------------------按回车键继续---------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    *----------------------------------------------------*\n");
	printf("\t\t\t\t\t    ******************************************************\n");
	getchar();
		
	daohanglan();
}
 
int main(void)
{
	system("mode con cols=150 lines=200");		//改变运行窗口大小 
	cuntu();
	//getchar();getchar();
	zhujiemian();
	return 0;
}