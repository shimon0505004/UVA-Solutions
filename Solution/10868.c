#include<stdio.h>
#include<math.h>
int main(){
	double k,l,s,w,Ek;
	while(scanf("%lf%lf%lf%lf",&k,&l,&s,&w),k>0||l>0||s>0||w>0){
		Ek=w*9.81*s;
		if(s>l) Ek-=k*(s-l)*(s-l)/2;
		if(Ek<0) puts("Stuck in the air.");
		else if(sqrt(Ek*2/w)>10) puts("Killed by the impact.");
		else puts("James Bond survives.");
	}
	return 0;
}
