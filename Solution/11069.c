#include<stdio.h>
int main(){
	int graph[77][2]={{0}};
	int i,n;
	graph[1][0]=0,graph[1][1]=1;
	graph[2][0]=1,graph[2][1]=1;
	for(i=3;i<=76;i++){
		graph[i][0]=graph[i-1][1];
		graph[i][1]=graph[i-2][1]+graph[i-3][1];
	}
	while(scanf("%d",&n)==1)
		printf("%d\n",graph[n][0]+graph[n][1]);
	return 0;
}
