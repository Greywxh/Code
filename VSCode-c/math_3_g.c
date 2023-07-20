#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
typedef struct Point{
    double X;//中点横坐标
    double Y;//中点纵坐标
    double Slope;//斜率
    double radian;//锐角弧度数
    double Ylab;//在y轴交点坐标
    double Reflectance;//反射系数
}Point;

double Reflect_Weight(Point p);

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
        P[i].Reflectance=Reflect_Weight(P[i]);
        x0=xt;
        y0=yt;
    }
    for(int i=0;i<300;i++) {
        printf("%6lf    ",P[i].Reflectance);
        if(i%10==9) printf("\n");
    }
    system("pause");
    return 0;
}
/*
double Reflect_Weight(Point p) {
//[130-150] 
    double half_long=0.5/sin(p.radian);
//[p.Ylab-half_long,p.Ylab+half_long]
    double high=p.Ylab+half_long,low=p.Ylab-half_long;
//  if(0<=i && i<=10) printf("%lf          %lf         %lf\n",low,high,high-low);
    if(150<=low || high<=130) return 0;
    if(low<130 && 130<high && high<=150) return (high-130)/(high-low);
    if(150<high && 130<=low && low<150) return (150-low)/(high-low);
    if(130<=low && high<=150) return 1;
    if(low<130 && 150<high) return 20/(high-low);
}
*/
double Reflect_Weight(Point p) 
{
    double half_long=cos(p.radian)/sin(2*p.radian);
    double high=p.Ylab+half_long,low=p.Ylab-half_long;
    if(150<=low || high<=130) return 0;
    if(low<130 && 130<high && high<=150) return (high-130)/(high-low);
    if(150<high && 130<=low && low<150) return (150-low)/(high-low);
    if(130<=low && high<=150) return 1;
    if(low<130 && 150<high) return 20/(high-low);
}