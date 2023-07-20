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
	Point para[600];
	double XZ,YZ;//半条线长度
	double XD=0,YD=0;//前一段线的右端点值
	for(int i=1,j=0;i<600;i+=2,j++)	{
		XZ=0.5*cos(i/599.0);
		YZ=0.5*sin(i/599.0);
		XD+=XZ; YD+=YZ;
		para[j+300].X=XD;
        para[299-j].X=-1*XD;
		para[299-j].Y=para[j+300].Y=YD;
        para[j+300].radian=2*i/599.0;
        para[299-j].radian=-2*i/599.0;
        para[j+300].Slope=tan(para[j+300].radian+PI*5/9);
        para[299-j].Slope=tan(para[299-j].radian+PI*5/9);
        para[j+300].Ylab=para[j+300].Y-para[j+300].X*para[j+300].Slope;
        para[299-j].Ylab=para[299-j].Y-para[299-j].X*para[299-j].Slope; 
        para[j+300].Reflectance=Reflect_Weight(para[j+300]);
        para[299-j].Reflectance=Reflect_Weight(para[299-j]);
		XD+=XZ; YD+=YZ;
	}
    for(int i=0;i<600;i++) {
        display(para[i]);
    }
    for(int i=0;i<600;i++) {
        printf("%6lf    ",para[i].Reflectance);
        if(i%10==9) printf("\n");
    }
    system("pause");
    return 0;
}
double Reflect_Weight(Point p) {
    //130-150
    double half_long=0.5/sin(p.radian+PI/18);
    if(p.radian<0) {
        if(-1*p.radian<=PI/18) return 0;
        half_long=0.5/sin(-1*p.radian-PI/18);
    }
    double high=p.Ylab+half_long,low=p.Ylab-half_long;
//    if(0<=i && i<=10) printf("%lf          %lf         %lf\n",low,high,high-low);
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