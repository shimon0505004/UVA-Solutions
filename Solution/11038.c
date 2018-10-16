#include<stdio.h>
long long zero(long long n){
	long long result=0;
	while(n>0){
		if(n%10==0) result++;
		n/=10;
	}
	return result;
}
long long zero_N(long long n){
	long long result=0;
	if(n==0) return 0;
	if(n<0) return -1;
	if(n<10) return 0;
	result+=n/10;
	result+=(n%10+1)*zero(n/10);
	return result+zero_N(n/10-1)*10;
}
int main(){
	long long m,n;
	while(scanf("%lld%lld",&m,&n),m>=0){
		printf("%lld\n",zero_N(n)-zero_N(m-1));
	}
	return 0;
}
