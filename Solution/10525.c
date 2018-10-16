#include<stdio.h>
#define INF 100000000
struct TIME_DIS{
	int t,d;
};
int main(){
	int cases;
	int n,r,q;
	int i,j,k,from,to,t,d;
	struct TIME_DIS map[55][55];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&n,&r);
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				map[i][j].t=map[i][j].d=INF;
			map[i][i].t=map[i][i].d=0;
		}
		while(r--){
			scanf("%d%d%d%d",&from,&to,&t,&d);
			if(map[from][to].t>t){
				map[from][to].t=map[to][from].t=t;
				map[from][to].d=map[to][from].d=d;
			}else if(map[from][to].t==t&&map[from][to].d>d)
				map[from][to].d=map[to][from].d=d;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<i;j++){
					if(map[i][k].t+map[k][j].t<map[i][j].t){
						map[j][i].t=map[i][j].t=map[i][k].t+map[k][j].t;
						map[j][i].d=map[i][j].d=map[i][k].d+map[k][j].d;
					}else if(map[i][k].t+map[k][j].t==map[i][j].t){
						if(map[i][k].d+map[k][j].d<map[i][j].d){
							map[j][i].t=map[i][j].t=map[i][k].t+map[k][j].t;
							map[j][i].d=map[i][j].d=map[i][k].d+map[k][j].d;
						}
					}
				}
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&from,&to);
			if(map[from][to].t==INF) puts("No Path.");
			else printf("Distance and time to reach destination is %d & %d.\n",map[from][to].d,map[from][to].t);
		}
		if(cases) puts("");
	}
	return 0;
}
