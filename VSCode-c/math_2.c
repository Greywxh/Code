#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
int main(void)
{
	double XL[600],YL[600];
	double Ylab[600];//在y轴坐标
	double XZ,YZ;//中点长度
	double XD=0,YD=0;//前一段线的右端点值
    //生成中点坐标
	for(int i=1,j=0;i<600;i+=2,j++) {
		XZ=0.5*cos(i/599.0);
		YZ=0.5*sin(i/599.0);
		XD+=XZ;
		YD+=YZ;
		XL[j]=XD;
		YL[j]=YD;
		XD+=XZ;
		YD+=YZ;
	}

    for(int i=0;i<300;i++) {
        XL[300+i]=XL[i];
        YL[300+i]=YL[i];
    }
    for(int i=0;i<300;i++) {
        XL[i]=XL[599-i]*(-1);
        YL[i]=YL[599-i];
    }
    for(int t=-599,k=0;t<600;t+=2,k++) {
        Ylab[k]=YL[k]-XL[k]*tan(2*t/599.0+PI*5/9);
    }

//    double YZF[600];
	for(int k=-300;k<300;k++) {
		printf("x[%3d]=%lf      y[%3d]=%lf      ",k,XL[k+300],k,YL[k+300]);
		printf("Y[%3d]=%lf      Y[%3d]转换=%lf\n",k,Ylab[k+300],k,Ylab[k+300]-300);

	}

    int count=0;
    int calculate[800]={0};
    for(int i=0;i<600;i++) {
        if(100<=Ylab[i] && Ylab[i]<=120) count++;
        if(-100<Ylab[i] && Ylab[i]<700) {
            int t=(int)Ylab[i]+100;
            if(Ylab[i]<300) t--;
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
            if(83+i<=Ylab[j] && Ylab[j]<=103+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.1
    //184.x-204.x
    printf("精度为0.1   184.x-204.x的数据:\n");
    for(double i=0.0;i<0.9999;i+=0.1) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84+i<=Ylab[j] && Ylab[j]<=104+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.01
    //184.1x-204.1x
    printf("精度为0.01   184.1x-204.1x的数据:\n");
    for(double i=0.0;i<0.09999;i+=0.01) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.1+i<=Ylab[j] && Ylab[j]<=104.1+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.01
    //184.2x-204.2x
    printf("精度为0.01   184.2x-204.x的数据:\n");
    for(double i=0.0;i<0.09999;i+=0.01) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.2+i<=Ylab[j] && Ylab[j]<=104.2+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    //----精度为0.001
    //184.11x-204.11x
    printf("精度为0.001   184.11x-204.11x的数据:\n");
    for(double i=0.0;i<0.009999;i+=0.001) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.11+i<=Ylab[j] && Ylab[j]<=104.11+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    printf("精度为0.001   184.12x-204.12x的数据:\n");
    for(double i=0.0;i<0.009999;i+=0.001) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.12+i<=Ylab[j] && Ylab[j]<=104.12+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

    printf("精度为0.001   184.13x-204.13x的数据:\n");
    for(double i=0.0;i<0.009999;i+=0.001) {
        sum=0;
        for(int j=0;j<600;j++) {
            if(84.13+i<=Ylab[j] && Ylab[j]<=104.13+i) sum++;
        }
        printf("%-4d",sum);
    }
    printf("\n");

//经过三次递进式精度校验,发现，落在[184.114,204.114],[184.132,204.132]区间
//的值均是最高的，171个，即题目所求最佳区间为
//起始区间:[184.114-184.132],终点区间:[204.114,204.132]均是满足题意得
    system("pause");
    return 0;
}