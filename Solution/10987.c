#include<stdio.h>
#include<string.h>
char impossible(int shortest[][105],int N){
	int i,j,k;
	for(k=1;k<=N;k++)
		for(i=1;i<=N;i++)
			for(j=1;j<i;j++)
				if(shortest[i][k]+shortest[k][j]<shortest[i][j])
					return 1;
	return 0;
}
char necessary(int shortest[][105],int from,int to,int N){
	int i;
	for(i=1;i<=N;i++)
		if(i!=from&&i!=to&&shortest[from][i]+shortest[i][to]==shortest[from][to])
			return 0;
	return 1;
}
int main(){
	int T,cases;
	int i,j,N,edges;
	int shortest[105][105];
	int d[105][105];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		printf("Case #%d:\n",cases);
		scanf("%d",&N);
		memset(shortest,0,sizeof(shortest));
		for(i=2;i<=N;i++)
			for(j=1;j<i;j++)
				scanf("%d",&shortest[i][j]),shortest[j][i]=shortest[i][j];
		if(impossible(shortest,N)){
			puts("Need better measurements.\n");
			continue;
		}
		memset(d,0,sizeof(d));
		edges=0;
		for(i=1;i<=N;i++)
			for(j=i+1;j<=N;j++)
				if(necessary(shortest,i,j,N))
					d[i][j]=shortest[i][j],edges++;
		printf("%d\n",edges);
		for(i=1;i<=N;i++)
			for(j=i+1;j<=N;j++)
				if(d[i][j])
					printf("%d %d %d\n",i,j,d[i][j]);
		puts("");
	}
	return 0;
}
