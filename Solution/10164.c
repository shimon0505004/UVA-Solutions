#include<stdio.h>
#include<string.h>
int seq[2050],D,N;
char flag;
int ans[1025];
void dfs(int depth,int rmd,int now){
	int i;
	if(depth==N){
		if(rmd%N==0){
			flag=1;
			puts("Yes");
			printf("%d",ans[0]);
			for(i=1;i<N;i++) printf(" %d",ans[i]);
			puts("");
		}
		return;
	}
	for(i=now;i<D&&flag==0;i++){
		ans[depth]=seq[i];
		dfs(depth+1,rmd+seq[i],i+1);
	}
}
int main(){
	int i;
	while(scanf("%d",&N),N){
		D=2*N-1;
		for(i=0;i<D;i++) scanf("%d",&seq[i]);
		flag=0;
		dfs(0,0,0);
	}
	return 0;
}
