#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i;
	long long prev,now,cost;
	while(scanf("%d",&n),n){
		prev=cost=0;
		for(i=0;i<n;i++) scanf("%lld",&now),now+=prev,cost+=abs(now),prev=now;
		printf("%lld\n",cost);
	}
	return 0;
}
