#include<stdio.h>
int main(){
	long long a,b,result;
	int cases;
	for(cases=1;scanf("%lld%lld",&a,&b),a|b;cases++){
		result=a*(a-1)/2*b*(b-1)/2;
		printf("Case %d: %lld\n",cases,result);
	}
	return 0;
}
