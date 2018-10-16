#include<stdio.h>
int main(){
	int T,cases,i;
	long long n;
	const long long shift=0xAAAAAAAA;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%lld",&n);
		printf("Case #%d: ",cases);
		n+=shift;
		for(i=1;i<32;i+=2)
			n^=1LL<<i;
		for(i=31;i>0&&(n&(1<<i))==0;i--);
		for(;i>=0;i--)
			printf("%d",n&(1LL<<i)?1:0);
		puts("");
	}
	return 0;
}
