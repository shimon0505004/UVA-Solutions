#include<stdio.h>
int main(){
	int cases;
	long long CSOD,n,cf1,cf2,i;
	for(cases=1;scanf("%lld",&n),n;cases++){
		CSOD=0;
		for(i=2;i*i<=n;i++){
			CSOD+=(n/i)*i;
			cf1=n/i;
			cf2=n/(i+1)+1;
			if(cf2>i) CSOD+=(cf1+cf2)*(cf1-cf2+1)/2*i;
		}
		CSOD-=(2+n/2)*(n/2-1)/2;
		printf("Case %d: %lld\n",cases,CSOD);
	}
	return 0;
}
