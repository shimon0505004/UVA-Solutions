#include<stdio.h>
#define UBound 9876543210LL
char noRepeat(long long n){
	char used[10]={0};
	int mod;
	while(n){
		mod=n%10;
		if(used[mod]) return 0;
		used[mod]=1;
		n/=10;
	}
	return 1;
}
int main(){
	int cases;
	long long N,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lld",&N);
		for(i=1;N*i<=UBound;i++)
			if(noRepeat(N*i)&&noRepeat(i))
				printf("%lld / %lld = %lld\n",N*i,i,N);
		if(cases) puts("");
	}
	return 0;
}
