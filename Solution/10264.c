#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int n,i;
	int sum[1<<14],w,t,max;
	while(scanf("%d",&n)==1){
		int size=1<<n;
		memset(sum,0,sizeof(int[1<<n]));
		for(i=0;i<size;i++){
			scanf("%d",&w);
			for(t=1;t<size;t<<=1)
				sum[i^t]+=w;
		}
		max=0;
		for(i=0;i<size;i++)
			for(t=1;t<size;t<<=1)
				max=MAX(max,sum[i]+sum[i^t]);
		printf("%d\n",max);
	}
	return 0;
}
