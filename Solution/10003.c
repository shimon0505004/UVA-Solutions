#include<stdio.h>
#include<string.h>
int main(){
	int costs[55][55],i,j,min,t,k,l;
	int length,n,seg[55];
	while(scanf("%d",&length),length){
		scanf("%d",&n);
		seg[0]=0;
		for(i=1;i<=n;i++)
			scanf("%d",&seg[i]);
		seg[++n]=length;
		memset(costs,0,sizeof(costs));
		for(l=2;l<=n;l++){
			for(i=0;i+l<=n;i++){
				j=i+l-1;
				min=1000000000;
				for(k=i;k<j;k++){
					if((t=costs[i][k]+costs[k+1][j])<min) min=t;
				}
				costs[i][j]=min+seg[j+1]-seg[i];
			}
		}
		printf("The minimum cutting is %d.\n",costs[0][n-1]);
	}
	return 0;
}
