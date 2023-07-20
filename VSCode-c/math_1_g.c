#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
typedef struct Point{
    double X;//中点横坐标
    double Y;//中点纵坐标
    double Slope;//对应点与前一个点构成直线的斜率
    double radian;//锐角弧度数
    double Ylab;//在y轴交点坐标
}Point;

int main(void)
{
    double Rad;//圆心角度数
    Point P[300];
    double x0=0,y0=0;//前一个点的坐标 
    double xt=0,yt=0;//当前点的坐标
    for(int i=0;i<300;i++) {
        Rad=(i+1)/300.0;
        xt=300.0*sin(Rad);
        yt=300.0*(1-cos(Rad));
        P[i].Slope=(yt-y0)/(xt-x0);
        P[i].radian=atan(P[i].Slope);
        P[i].X=(xt+x0)/2.0;
        P[i].Y=(yt+y0)/2.0;
        P[i].Ylab=(P[i].Y)-(P[i].X)*tan(2.0*(P[i].radian)+PI/2.0);
        x0=xt;
        y0=yt;
    }
    int calculate[160]={0},sum=0;//统计每个区间段反射点Ylab的数据个数
	for(int i=0;i<300;i++) {
		printf("X[%d]=%lf      Y[%d]=%lf      ",i,P[i].X,i,P[i].Y);
		printf("Ylab[%d]=%lf      Y[%d]转换=%lf\n",i,P[i].Ylab,i,P[i].Ylab-300);
		int t=(int)P[i].Ylab;
		calculate[t]++;
	}

    for(int i=0;i<160;i++) {
        printf("%4d",calculate[i]);
        if(i%10==9) printf("\n");
	}

    printf("\n\n\ncalculate周围数组统计:\n");
    for(int i=0;i<141;i++) {
        sum=0;
        for(int j=0;j<20;j++) {
            sum+=calculate[i+j];
        }
        printf("%4d",sum);
        if(i%20==19) printf("\n");
    }
    printf("\n");


    //第一问解答
	sum=0;
	for(int t=100;t<120;t++) sum+=calculate[t];
	printf("射在[-200,-180]区间的数量为%d个\n",sum);

    sum=0;
    for(int i=0;i<300;i++){
        if(100<=P[i].Ylab && P[i].Ylab<=120) sum++;
    }
    printf("射在[-200,-180]区间的数量为%d个\n",sum);


    int count;
	//精度校验---0.1---[129.0,129.9]
	printf("在精度为0.1的情况下,有以下可能:\n");
	for(double i=0;i<0.9999;i+=0.1) {
		count=0;
		for(int t=0;t<300;t++){
			if((129+i)<=P[t].Ylab && P[t].Ylab<=(149+i)) count++;
		}
		printf("落在[%.1lf,%.1lf]的区间内有%d个点\n",129+i,149+i,count);
	}
	printf("\n");

	//精度校验---0.1---[130.0,130.9]
	printf("在精度为0.1的情况下,有以下可能:\n");
	for(double i=0;i<0.9999;i+=0.1) {
		count=0;
		for(int t=0;t<300;t++){
			if((130+i)<=P[t].Ylab && P[t].Ylab<=(150+i)) count++;
		}
		printf("落在[%.1lf,%.1lf]的区间内有%d个点\n",130+i,150+i,count);
	}
	printf("\n");

    //精度校验---0.01---[130.00-130.09]
	for(double i=0;i<0.099;i+=0.01) {
		count=0;
		for(int t=0;t<300;t++){
			if((130.0+i)<=P[t].Ylab && P[t].Ylab<=(150.0+i)) count++;
		}
		printf("落在[%.2lf,%.2lf]的区间内有%d个点\n",130.0+i,150.0+i,count);
	}
    printf("\n");

	//精度校验---0.01---[130.10-130.19]
	printf("在精度为0.01的情况下,有以下可能:\n");
	for(double i=0;i<0.0999;i+=0.01) {
		count=0;
		for(int t=0;t<300;t++){
			if((130.1+i)<=P[t].Ylab && P[t].Ylab<=(150.1+i)) count++;
		}
		printf("落在[%.2lf,%.2lf]的区间内有%d个点\n",130.1+i,150.1+i,count);
	}
//经过两次递进式精度校验,发现，落在[130.01,150.01],[130.14,150.14]区间
//的值均是最高的,147个，即题目所求最佳区间为
//起始区间:[130.01-130.14],终点区间:[150.01,150.14]均是满足题意得
    system("pause");
    return 0;
}