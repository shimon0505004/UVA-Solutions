#include<stdio.h>
#include<math.h>
double func(double s,double a){
	return sqrt(3)/2*sqrt(s*s-a*a)+sqrt(s*s/2+a*a/4);
}
double largest_side(double a,double b){
	double U=2*a,L=a,mid=(U+L)/2;
	while(U-L>1e-3){
		if(func(mid,a)>b) U=mid;
		else L=mid;
		mid=(U+L)/2;
	}
	return mid;
}
int main(){
	int a,start,end;
	int i;
	double sum;
	while(scanf("%d%d%d",&a,&start,&end),a|start|end){
		sum=0;
		for(i=start;i<=end;i++) sum+=largest_side((double)a,(double)(a+i));
		printf("%.0lf\n",floor(sum+0.5));
	}
	return 0;
}
