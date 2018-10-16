#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
int main(){
	int cases,R,n,i;
	for(cases=1;scanf("%d%d",&R,&n),R|n;cases++){
		printf("Case %d:\n",cases);
		for(i=1;i<=10;i++){
			double r=(double)n/i/2/pi;
			printf("%.5lf\n",(acos(r/R)-(double)n/R)*180/pi);
		}
	}
	return 0;
}
