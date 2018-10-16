#include<stdio.h>
#include<string.h>
int main(){
	int N,T,i,k,j,dep[105],d,max,maxi;
	char map[105][105];
	while(scanf("%d",&N),N){
		memset(map,0,sizeof(map));
		memset(dep,0,sizeof(dep));
		for(i=1;i<=N;i++){
			scanf("%d",&T);
			dep[i]=T;
			while(T--){
				scanf("%d",&d);
				map[i][d]=1;
			}
		}
		max=-1,maxi=-1;
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					if(map[i][k]&&map[k][j]&&map[i][j]==0)
						map[i][j]=1,dep[i]++;
		for(i=1;i<=N;i++)
			if(dep[i]>max)
				max=dep[i],maxi=i;
		printf("%d\n",maxi);
	}
	return 0;
}
