#include<windows.h>
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
int main(void)
{
	double XL[300],YL[300];
	double Ylab[300];//在y轴坐标
	double XZ,YZ;//中点长度
	double XD=0,YD=0;//前一段线的右端点值
	int jk=0;
	for(int i=1;i<600;i+=2,jk++) {
		XZ=0.5*cos(i/599.0);
		YZ=0.5*sin(i/599.0);
		XD+=XZ;
		YD+=YZ;
		XL[jk]=XD;
		YL[jk]=YD;
		Ylab[jk]=YL[jk]-XL[jk]*tan(2*i/599.0+PI/2);
		XD+=XZ;
		YD+=YZ;
	}
	int calculate[150]={0};//统计每个区间段反射点Ylab的数据个数
	for(int k=0;k<300;k++) {
		printf("x[%d]=%lf      y[%d]=%lf      ",k,XL[k],k,YL[k]);
		printf("Y[%d]=%lf      Y[%d]转换=%lf\n",k,Ylab[k],k,Ylab[k]-300);
		int t=(int)Ylab[k];
		calculate[t]++;
	}
	for(int t=0;t<150;t++) {
		printf("%4d",calculate[t]);
		if(t%10==9) printf("\n");
	}

	//第一问解答
	int sum=0;
	for(int t=100;t<120;t++) sum+=calculate[t];
	printf("射在[-200,-180]区间的数量为%d个\n",sum);
	
	int count;
	//精度校验---0.1---[129.8,149.8]
	printf("在精度为0.1的情况下,有以下可能:\n");
	for(double i=0;i<0.9999;i+=0.1) {
		count=0;
		for(int t=0;t<300;t++){
			if((129+i)<=Ylab[t] && Ylab[t]<=(149+i)) count++;
		}
		printf("落在[%.1lf,%.1lf]的区间内有%d个点\n",129+i,149+i,count);
	}
	printf("\n");

	//精度校验---0.01---[129.70-149.79]
	printf("在精度为0.01的情况下,有以下可能:\n");
	for(double i=0;i<0.0999;i+=0.01) {
		count=0;
		for(int t=0;t<300;t++){
			if((129.7+i)<=Ylab[t] && Ylab[t]<=(149.7+i)) count++;
		}
		printf("落在[%.2lf,%.2lf]的区间内有%d个点\n",129.7+i,149.7+i,count);
	}
	printf("\n");

	//精度校验---0.01---[129.80-149.89]
	for(double i=0;i<0.099;i+=0.01) {
		count=0;
		for(int t=0;t<300;t++){
			if((129.8+i)<=Ylab[t] && Ylab[t]<=(149.8+i)) count++;
		}
		printf("落在[%.2lf,%.2lf]的区间内有%d个点\n",129.8+i,149.8+i,count);
	}
//经过两次递进式精度校验,发现，落在[129.76,149.76],[129.85,149.85]区间
//的值均是最高的，147个，即题目所求最佳区间为
//起始区间:[129.76-129.85],终点区间:[149.76,149.85]均是满足题意得
	system("pause");
	return 0;
}