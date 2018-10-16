#include<stdio.h>
#include<string.h>
int main(){
	int T,N,i,j,G,W;
	int prices[1005],weight[1005];
	int table[1005][35];
	int total,t;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(i=1;i<=N;i++) scanf("%d%d",&prices[i],&weight[i]);
		memset(table,0,sizeof(table));
		for(i=1;i<=N;i++)
			for(j=0;j<=30;j++)
				if(j<weight[i]) table[i][j]=table[i-1][j];
				else if(table[i-1][j]<(t=table[i-1][j-weight[i]]+prices[i]))
					table[i][j]=t;
				else table[i][j]=table[i-1][j];
		scanf("%d",&G);
		total=0;
		while(G--){
			scanf("%d",&W);
			total+=table[N][W];
		}
		printf("%d\n",total);
	}
	return 0;
}
