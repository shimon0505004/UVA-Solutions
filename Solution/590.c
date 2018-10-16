#include<stdio.h>
int main(){
	int table[1005][15];
	int N,K;
	int cost[15][15][35];
	int period[15][15];
	int i,j,k,t;
	int cases;
	for(cases=1;scanf("%d%d",&N,&K),N|K;cases++){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				if(i!=j){
					scanf("%d",&period[i][j]);
					for(k=0;k<period[i][j];k++){
						scanf("%d",&cost[i][j][k]);
						if(cost[i][j][k]==0)
							cost[i][j][k]=1000000000;
					}
				}
		}
		for(i=0;i<=K;i++)
			for(j=0;j<N;j++)
				table[i][j]=1000000000;
		table[0][0]=0;
		for(i=1;i<=K;i++)
			for(j=0;j<N;j++)
				for(k=0;k<N;k++)
					if(k!=j)
						if((t=cost[j][k][(i-1)%period[j][k]]+table[i-1][j])<table[i][k])
							table[i][k]=t;
		printf("Scenario #%d\n",cases);
		if(table[K][N-1]==1000000000) puts("No flight possible.");
		else printf("The best flight costs %d.\n",table[K][N-1]);
		puts("");
	}
	return 0;
}
