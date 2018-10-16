#include<stdio.h>
#define MAX 1005
#define INF 1000000000
struct EDGE{
	int from,to;
};
int main(){
	struct EDGE e[2005];
	int d[1005],t;
	int map[1005][1005],cases,n,m,i,j,w;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++) d[i]=INF;
		for(i=0;i<m;i++){
			scanf("%d%d%d",&e[i].from,&e[i].to,&w);
			map[e[i].from][e[i].to]=w;
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(d[e[j].to]>(t=d[e[j].from]+map[e[j].from][e[j].to]))
					d[e[j].to]=t;
		for(i=0;i<m;i++)
			if(d[e[i].to]>(t=d[e[i].from]+map[e[i].from][e[i].to]))
				break;
		if(i<m) puts("possible");
		else puts("not possible");
	}
	return 0;
}
