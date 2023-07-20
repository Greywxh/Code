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
    Point P[600];
    double x0=0,y0=0;//前一个点的坐标 
    double xt=0,yt=0;//当前点的坐标
    for(int i=0;i<300;i++) {
        Rad=(i+1)/300.0;
        xt=300.0*sin(Rad);
        yt=300.0*(1-cos(Rad));
        P[300+i].Slope=(yt-y0)/(xt-x0);
        P[299-i].Slope=(yt-y0)/(x0-xt);
        P[300+i].radian=atan(P[300+i].Slope);
        P[299-i].radian=(-1.0)*atan(P[300+i].Slope);
        P[300+i].X=(xt+x0)/2.0;
        P[299-i].X=(xt+x0)/(-2.0);
        P[299-i].Y=P[300+i].Y=(yt+y0)/2.0;
        P[300+i].Ylab=(P[300+i].Y)-(P[300+i].X)*tan(2.0*(P[300+i].radian)+PI*5/9);
        printf("%d  %f\n",300+i,P[300+i].Ylab);
        P[299-i].Ylab=(P[299-i].Y)-(P[299-i].X)*tan(2.0*(P[299-i].radian)+PI*5/9);
        printf("%d  %f\n",299-i,P[299-i].Ylab);
        x0=xt;
        y0=yt;
    }

	for(int i=0;i<600;i++) {
		printf("X[%3d]=%lf      Y[%3d]=%lf      ",i,P[i].X,i,P[i].Y);
		printf("Ylab[%3d]=%lf      Y[%3d]转换=%lf\n",i,P[i].Ylab,i,P[i].Ylab-300);
	}

    int count=0;
    int calculate[800]={0};
    for(int i=0;i<600;i++) {
        if(100<=P[i].Ylab && P[i].Ylab<=120) count++;
        if(-100<P[i].Ylab && P[i].Ylab<700) {
            int t=(int)P[i].Ylab+100;
            if(P[i].Ylab<300) t--;
            calculate[t]++;
        }
    }
    printf("射在[-200,-180]区间的数量为%d个\n",count);

    int sum;    
    printf("\n\ncalculate数组:\n");
    for(int t=0;t<800;t++)
	{
		printf("%4d",calculate[t]);
		if(t%20==19) printf("\n");
	}
    
    printf("\n\n\ncalculate周围数组统计:\n");
    for(int i=0;i<781;i++) {
        sum=0;
        for(int j=0;j<20;j++) {
            sum+=calculate[i+j];
        }
        printf("%4d",sum);
        if(i%20==19) printf("\n");
    }
    
    //----精度为0.1
    //183.x-203.x
    printf("\n精度为0.1   183.x-203.x的数据:\n");
    for(double i=0.0;i<0.9999;i+=0.1) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(83+i<=P[j].Ylab && P[j].Ylab<=103+i) sum++;
        }
        printf("%-5d",sum);
    }
    printf("\n");

    //----精度为0.1
    //184.x-204.x
    printf("精度为0.1   184.x-204.x的数据:\n");
    for(double i=0.0;i<0.9999;i+=0.1) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84+i<=P[j].Ylab && P[j].Ylab<=104+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.01
    //184.2x-204.2x
    printf("精度为0.01   184.2x-204.2x的数据:\n");
    for(double i=0.0;i<0.09999;i+=0.01) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.2+i<=P[j].Ylab && P[j].Ylab<=104.2+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.01
    //184.3x-204.3x
    printf("精度为0.01   184.3x-204.3x的数据:\n");
    for(double i=0.0;i<0.09999;i+=0.01) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.3+i<=P[j].Ylab && P[j].Ylab<=104.3+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.01
    //184.4x-204.4x
    printf("精度为0.01   184.4x-204.4x的数据:\n");
    for(double i=0.0;i<0.09999;i+=0.01) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.4+i<=P[j].Ylab && P[j].Ylab<=104.4+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

//经过三次递进式精度校验,发现，落在[184.29,204.29],[184.48,204.48]区间
//的值均是最高的，170个，即题目所求最佳区间为
//起始区间:[184.29-184.48],终点区间:[204.29,204.48]均是满足题意得
    system("pause");
    return 0;
}