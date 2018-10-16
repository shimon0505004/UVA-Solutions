#include<stdio.h>
#include<string.h>
#define INF 1000001
int map[105][105],relay[105][105],copy[105][105];
void clearRoute(int from,int to){
	int r=relay[from][to];
	if(r){
		clearRoute(from,r);
		clearRoute(r,to);
	}else copy[from][to]=INF,copy[to][from]*=-1;
}
int main(){
	int n,m,from,to,w,i,j,k,t,Distance;
	while(scanf("%d",&n),n){
		for(i=1;i<=n;i++)
			for(j=1;j<i;j++)
				map[i][j]=map[j][i]=INF;
		memset(relay,0,sizeof(relay));
		scanf("%d",&m);
		while(m--){
			scanf("%d%d%d",&from,&to,&w);
			map[from][to]=map[to][from]=w;
		}
		memcpy(copy,map,sizeof(map));
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(map[i][j]>(t=map[i][k]+map[k][j])){
						map[i][j]=t;
						relay[i][j]=k;
					}
		Distance=map[1][n];
		clearRoute(1,n);
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if(copy[i][j]<INF&&copy[1][i]+copy[i][j]<copy[1][j])
						copy[1][j]=copy[1][i]+copy[i][j];
		Distance+=copy[1][n];
		if(Distance>=INF) puts("Back to jail");
		else printf("%d\n",Distance);
	}
	return 0;
}
