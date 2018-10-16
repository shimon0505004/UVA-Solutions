#include<stdio.h>
#include<math.h>
int main(){
	double L,W,x;
	while(scanf("%lf%lf",&L,&W)==2){
		x=((W+L)-sqrt((W+L)*(W+L)-3*L*W))/6;
		L+=0.00009,W+=0.00009;
		if(L<W) printf("%.3lf 0.000 %.3lf\n",x,L/2);
		else printf("%.3lf 0.000 %.3lf\n",x,W/2);
	}
	return 0;
}
