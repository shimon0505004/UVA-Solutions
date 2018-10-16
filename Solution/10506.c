#include<stdio.h>
#include<string.h>
char used[65536];
char ans[65600];
int Bound,M,N;
char dfs(int cur,int now){
	int i;
	if(cur==Bound-M){
		for(i=0;i<M-1;i++){
			now=(now*N+ans[i])%Bound;
			if(used[now]) return 0;
		}
		for(i=0;i<Bound;i++) printf("%d",ans[i]);
		puts("");
		return 1;
	}
	for(i=0;i<N;i++){
		int next=(now*N+i)%Bound;
		if(used[next]) continue;
		used[next]=1;
		ans[M+cur]=i;
		if(dfs(cur+1,next)) return 1;
		used[next]=0;
	}
	return 0;
}
int main(){
	int i;
	while(scanf("%d%d",&M,&N)==2){
		for(Bound=1,i=0;i<M;i++) Bound*=N;
		for(i=0;i<M;i++) ans[i]=0;
		memset(used,0,sizeof(used));
		used[0]=1;
		dfs(0,0);
	}
	return 0;
}
