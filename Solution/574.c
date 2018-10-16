#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int answer[12],num,count;
int x[12],t;
int graph[105];
int compar(const void *a,const void *b){
	return *((int *)b)-*((int *)a);
}
void dfs(int start,int depth,int current)
{
	int i;
	if(current==num){
		printf("%d",answer[0]);
		for(i=1;i<depth;i++)
			printf("+%d",answer[i]);
		puts("");
		t=1;
	}else if(current<num){
		for(i=start;i<count;i++){
			if(!graph[x[i]]) continue;
			if(current+x[i]>num) continue;
			graph[x[i]]--;
			answer[depth]=x[i];
			dfs(i,depth+1,current+x[i]);
			graph[x[i]]++;
		}
	}
}
int main()
{
	int i,temp,cases;
	while(scanf("%d%d",&num,&cases),num){
		memset(graph,0,sizeof(graph));
		count=0;
		for(i=0;i<cases;i++){
			scanf("%d",&x[count]);
			graph[x[count]]++;
			if(graph[x[count]]==1) count++;
		}
		qsort(x,count,sizeof(int),compar);
		t=0;
		printf("Sums of %d:\n",num);
		dfs(0,0,0);
		if(!t) puts("NONE");
	}
	return 0;
}
