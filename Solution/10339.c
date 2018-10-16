#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int k,m,diff;
	double duration;
	int hour,min;
	while(scanf("%d%d",&k,&m)==2){
		printf("%d %d ",k,m);
		if(k==m){
			puts("12:00");
			continue;
		}
		diff=abs(k-m);
		duration=(double)(86400-k)/2/diff;
		duration=(duration-floor(duration))*1440;
		min=(int)floor(duration+0.5+1e-10);
		hour=(min/60)%12,min%=60;
		if(hour==0) hour=12;
		printf("%.2d:%.2d\n",hour,min);
	}
	return 0;
}
