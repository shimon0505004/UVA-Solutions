#include<stdio.h>
int CD[25],temp[25],N,time,max,ans[25];
void dfs(int start,int depth,int sum){
	int i;
	if(sum<=time&&sum>max){
		max=sum;
		for(i=0;i<depth;i++)
			ans[i]=temp[i];
		ans[depth]=0;
	}
	for(i=start+1;i<N;i++){
		if(sum+CD[i]>time) continue;
		temp[depth]=CD[i];
		dfs(i,depth+1,sum+CD[i]);
	}
}
int main(){
	int i;
	while(scanf("%d",&time)==1){
		scanf("%d",&N);
		for(i=0;i<N;i++) scanf("%d",&CD[i]);
		max=0;
		dfs(-1,0,0);
		for(i=0;ans[i]!=0;i++)
			printf("%d ",ans[i]);
		printf("sum:%d\n",max);
	}
	return 0;
}
