#include<stdio.h>
int main(){
	int N,M,i,j,k,min,mini,cases;
	int distance[25][25];
	int sum[25];
	char name[25][15];
	for(cases=1;scanf("%d%d",&N,&M),N;cases++){
		for(i=1;i<=N;i++) scanf("%s",name[i]);
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++)
				distance[i][j]=1000000;
			distance[i][i]=0;
		}
		while(M--){
			int from,to,cost;
			scanf("%d%d%d",&from,&to,&cost);
			distance[from][to]=distance[to][from]=cost;
		}
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<i;j++){
					int t;
					if(distance[i][j]>(t=distance[i][k]+distance[k][j]))
						distance[i][j]=distance[j][i]=t;
				}
		for(i=1;i<=N;i++){
			sum[i]=0;
			for(j=1;j<=N;j++)
				sum[i]+=distance[i][j];
		}
		min=1000000;
		for(i=N;i>=1;i--)
			if(min>=sum[i]) min=sum[i],mini=i;
		printf("Case #%d : %s\n",cases,name[mini]);
	}
	return 0;
}
