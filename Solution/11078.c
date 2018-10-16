#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int cases;
	int n,seq[100005],max[100005],min[100005],diff;
	int i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&seq[i]);
		max[0]=-1000000;
		for(i=1;i<n;i++) max[i]=MAX(seq[i],max[i-1]);
		min[n+1]=1000000;
		for(i=n;i>1;i--) min[i]=MIN(seq[i],min[i+1]);
		diff=-100000;
		for(i=1;i<n;i++) diff=MAX(diff,max[i]-min[i+1]);
		printf("%d\n",diff);
	}
	return 0;
}
