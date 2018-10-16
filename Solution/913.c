#include<stdio.h>
int main(){
	long long N,res;
	while(scanf("%lld",&N)==1){
		res=(N+1)/2;
		res=res*res*2-3;
		printf("%lld\n",res*3);
	}
	return 0;
}
