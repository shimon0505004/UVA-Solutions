#include<stdio.h>
#include<math.h>
int main(){
	int cases,i;
	int deg;
	long long coef[25],d,k,m,res;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&deg);
		for(i=0;i<=deg;i++) scanf("%lld",&coef[i]);
		scanf("%lld%lld",&d,&k);
		m=(long long)ceil((sqrt(d*d+8*k*d)-d)/2/d);
		res=0;
		for(i=deg;i>=0;i--){
			res*=m;
			res+=coef[i];
		}
		printf("%lld\n",res);
	}
	return 0;
}
