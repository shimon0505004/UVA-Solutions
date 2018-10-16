#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int M,side;
char visit[25];
int stick[25];
int compar(const void *a,const void *b){
	return *((int *)b)-*((int *)a);
}
int dfs(int cur,int now,int finish){
	int i;
	if(finish==3) return 1;
	for(i=cur+1;i<M;i++){
		if(visit[i]) continue;
		if(now+stick[i]>side) continue;
		visit[i]=1;
		if(now+stick[i]==side){
			if(dfs(-1,0,finish+1)) return 1;
		}else if(dfs(i,now+stick[i],finish)) return 1;
		visit[i]=0;
	}
	return 0;
}
int main(){
	int N,i,tot,max;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&M);
		tot=0,max=0;
		for(i=0;i<M;i++){
			scanf("%d",&stick[i]);
			if(max<stick[i]) max=stick[i];
			tot+=stick[i];
		}
		if(tot%4!=0||max>tot/4){
			puts("no");
			continue;
		}
		qsort(stick,M,sizeof(int),compar);
		side=tot/4;
		memset(visit,0,sizeof(visit));
		if(dfs(-1,0,0)) puts("yes");
		else puts("no");
	}
	return 0;
}
