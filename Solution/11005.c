#include<stdio.h>
int calcost(int n,int base,int cost[]){
	int result=0;
	while(n>0){
		result+=cost[n%base];
		n/=base;
	}
	return result;
}
int main(){
	int cases,i,T,N,n,base;
	int cost[36];
	int mincost[37];
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		if(cases>1) puts("");
		for(i=0;i<36;i++)
			scanf("%d",&cost[i]);
		printf("Case %d:\n",cases);
		scanf("%d",&T);
		while(T--){
			int min=2147483647;
			scanf("%d",&n);
			for(base=2;base<=36;base++){
				mincost[base]=calcost(n,base,cost);
				if(mincost[base]<min) min=mincost[base];
			}
			printf("Cheapest base(s) for number %d:",n);
			for(base=2;base<=36;base++)
				if(mincost[base]==min)
					printf(" %d",base);
			puts("");
		}
	}
	return 0;
}
