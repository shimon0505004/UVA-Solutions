#include<stdio.h>
#include<string.h>
int a[5],out[5],visit[5],flag;
void dfs(int depth,int now){
	int i;
	if(flag) return;
	if(depth==5){
		if(now==23) flag=1;
		return;
	}
	dfs(depth+1,now+out[depth]);
	dfs(depth+1,now-out[depth]);
	dfs(depth+1,now*out[depth]);
}
int ndfs(int depth){
	int i;
	if(flag) return;
	if(depth==5){
		dfs(1,out[0]);
	}else
		for(i=0;i<5;i++){
			if(visit[i]) continue;
			out[depth]=a[i];
			visit[i]=1;
			ndfs(depth+1);
			visit[i]=0;
		}
	return 0;
}
int main()
{
	int i,t;
	for(;;){
		t=flag=0;
		for(i=0;i<5;i++){
			scanf("%d",&a[i]);
			t+=a[i];
		}
		if(t==0) break;
		memset(visit,0,sizeof(visit));
		ndfs(0);
		if(flag) puts("Possible");
		else puts("Impossible");
	}
	return 0;
}
