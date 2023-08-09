#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct Point
{
    float x;
    float y;
}Point;

int main(void)
{
    //angle1代表<OPA,angle2代表<OPB,angle3代表<APB
    float angle1,angle2,angle3;
    scanf("%f %f %f",&angle1,&angle2,&angle3);
    int flag=0;
    //flag==1,则在第一区域
    if(angle2==angle1+angle3) flag=1;
    //flag==2,则在第二区域
    if(angle3==angle1+angle2) flag=2;
    //flag==3,则在第三区域
    if(angle1==angle2+angle3) flag=3;

    //R1是圆OAP的半径,R2是圆OBP的半径,r为飞机编队的半径
    float R1,R2,r;
    //由正弦定理可知,R1=r/2sin(2angle1),R2=r/2sin(2angle2)
    R1=r/2*sin(2*angle1);
    R2=r/2*sin(2*angle2);
    //假设圆OAP的圆心是O1,圆OPB的圆心是O2
    Point O1,O2;
    //则O1(r/2,±sqrt(R1²-(r/2)²)),O2()
    O1.x=r/2;
    O1.y=O1.x/tan(angle1);
    //如果在第一区域,则y为正;反之,则为负
    if(flag!=1) O1.y*=-1;

    system("puase");
    return 0;
}