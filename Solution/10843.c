#include<stdio.h>
#define MODULI 2000000011
long long pow_n(long long n,int index){
	long long tmp;
	if(index==0) return 1;
	if(index==1) return n;
	tmp=pow_n(n,index/2);
	tmp=(tmp*tmp)%MODULI;
	if(index%2==0) return tmp;
	return (tmp*n)%MODULI;
}
int main(){
	int T,cases;
	long long n;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%lld",&n);
		printf("Case #%d: ",cases);
		if(n==1) puts("1");
		else printf("%lld\n",pow_n(n,(int)n-2));
	}
	return 0;
}
