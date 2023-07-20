#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
typedef struct Point{
    double X;//中点横坐标
    double Y;//中点纵坐标
    double Slope;//斜率
    double radian;//锐角弧度数---2倍的α
    double Ylab;//在y轴交点坐标
    double Reflectance;//反射系数
}Point;

double Reflect_Weight(Point p);
void display(Point p);

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
        P[299-i].Ylab=(P[299-i].Y)-(P[299-i].X)*tan(2.0*(P[299-i].radian)+PI*5/9);
        printf("%d  ",300+i);
        P[300+i].Reflectance=Reflect_Weight(P[300+i]);
        printf("%d  ",299-i);
        P[299-i].Reflectance=Reflect_Weight(P[299-i]);
        
        x0=xt;
        y0=yt;
    }
    for(int i=0;i<600;i++){
        display(P[i]);
    }
    for(int i=0;i<600;i++) {
        printf("%6lf    ",P[i].Reflectance);
        if(i%10==9) printf("\n");
    }
    system("pause");
    return 0;
}
double Reflect_Weight(Point p) {
//[130-150] 
    double half_long=0.5/sin(p.radian);
//[p.Ylab-half_long,p.Ylab+half_long]
    double high=p.Ylab+half_long,low=p.Ylab-half_long;
    printf("%lf     %lf      %lf      %lf\n",p.Ylab,high,low,high-low);
    if(150<=low || high<=130) return 0;
    if(low<130 && 130<high && high<=150) return (high-130)/(high-low);
    if(150<high && 130<=low && low<150) return (150-low)/(high-low);
    if(130<=low && high<=150) return 1;
    if(low<130 && 150<high) return 20/(high-low);
}

void display(Point p) {
    printf("X=%lf    Y=%lf    Slope=%lf    ",p.X,p.Y,p.Slope);
    printf("Ylab=%lf    Reflectance=%lf    radian=%lf\n",p.Ylab,p.Reflectance,p.radian);
}