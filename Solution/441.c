#include<stdio.h>
int answer[6],num;
int lotto[14];
void dfs(int start,int depth)
{
	int i;
	if(depth==6){
		for(i=0;i<5;i++)
			printf("%d ",answer[i]);
		printf("%d\n",answer[5]);
	}
	else{
		for(i=start;i<num;i++){
			answer[depth]=lotto[i];
			dfs(i+1,depth+1);
		}
	}
}
int main()
{
	int i,start=0;
	while(scanf("%d",&num)==1&&num){
		if(start) puts("");
		start=1;
		for(i=0;i<num;i++)
			scanf("%d",&lotto[i]);
		dfs(0,0);
	}
	return 0;
}
