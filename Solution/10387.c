#include<stdio.h>
#include<math.h>
int main(){
	double a,b,s,m,n;
	double dis;
	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&s,&m,&n),a+b+s+m+n){
		dis=sqrt(a*m*a*m+n*b*n*b);
		printf("%.2lf %.2lf\n",acos(a*m/dis)/acos(0)*90,dis/s);
	}
	return 0;
}
