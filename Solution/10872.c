#include<stdio.h>
int main(){
	int cases,i;
	long long answer,half,third,N,carry,n,a;
	for(cases=1;scanf("%lld",&N),N;cases++){
		half=(N-1)>>1,third=(N+2)/3;
		answer=half-third+1;
		half=3*half-N,third=3*third-N;
		if(third&1) carry=1;
		else carry=2;
		half>>=1,third>>=1;
		answer+=(third+half)*(half-third+1)/2;
		n=(half-third+1)/3,a=third+carry;
		answer-=n*(2*a+(n-1)*3)/2;
		printf("Case %d: %lld\n",cases,answer);
	}
	return 0;
}
