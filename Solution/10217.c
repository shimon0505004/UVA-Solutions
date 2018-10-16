#include<stdio.h>
#include<math.h>
int main(){
	double N,ans;
	while(scanf("%lf",&N)==1){
		ans=(-1+sqrt(1+4*N))/2;
		printf("%.2lf %.0lf\n",ans,floor(ans+1));
	}
	return 0;
}
