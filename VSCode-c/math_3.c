#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
typedef struct piont{
    double X;//中点横坐标
    double Y;//中点纵坐标
    double Slope;//斜率
    double radian;//锐角弧度数---2倍的α
    double Ylab;//在y轴交点坐标
    double Reflectance;//反射系数
}Piont;

double Reflect_Weight(Piont p);
void display(Piont p);

int main(void)
{
	Piont para[300];
	double XZ,YZ;//中点长度
	double XD=0,YD=0;//前一段线的右端点值
	for(int i=1,j=0;i<600;i+=2,j++)	{
		XZ=0.5*cos(i/599.0);
		YZ=0.5*sin(i/599.0);
		XD+=XZ; YD+=YZ;
		para[j].X=XD;
		para[j].Y=YD;
        para[j].radian=2.0*i/599.0;
        para[j].Slope=tan(2.0*i/599.0+PI/2);
        para[j].Ylab=YD-XD*tan(2.0*i/599.0+PI/2); 
        para[j].Reflectance=Reflect_Weight(para[j]);
		XD+=XZ; YD+=YZ;
	}
    for(int i=0;i<300;i++) {
        printf("%6lf    ",para[i].Reflectance);
        if(i%10==9) printf("\n");
    }
    system("pause");
    return 0;
}
double Reflect_Weight(Piont p) {
//130-150
    double half_long=0.5/sin(p.radian);
//  [p.Ylab-half_long,p.Ylab+half_long]
    double high=p.Ylab+half_long,low=p.Ylab-half_long;
//  if(0<=i && i<=10) printf("%lf          %lf         %lf\n",low,high,high-low);
    if(150<=low || high<=130) return 0;
    if(low<130 && 130<high && high<=150) return (high-130)/(high-low);
    if(150<high && 130<=low && low<150) return (150-low)/(high-low);
    if(130<=low && high<=150) return 1;
    if(low<130 && 150<high) return 20/(high-low);
}