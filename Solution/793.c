#include<stdio.h>
#include<string.h>
int findroot(int n,int graph[]){
	while(graph[n]!=0&&n!=graph[n]) n=graph[n];
	return n;
}
int main(){
	int graph[1000];
	char instr,input[30];
	int cases,suc,unsuc,n,i,j,k,from,to,rfrom,rto;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d ",&n);
		memset(graph,0,sizeof(graph));
		suc=unsuc=0;
		while(fgets(input,30,stdin)!=NULL){
			if(*input=='\n') break;
			sscanf(input,"%c%d%d",&instr,&from,&to);
			rfrom=findroot(from,graph),rto=findroot(to,graph);
			if(instr=='c'&&rfrom!=rto){
				if(graph[from]==0&&graph[to]==0)
					graph[to]=from;
				else if(graph[from]==0)
					graph[from]=to;
				else if(graph[to]==0)
					graph[to]=from;
				else graph[rfrom]=rto;
			}else if(instr=='q')
				if(findroot(from,graph)==findroot(to,graph)) suc++;
				else unsuc++;
		}
		printf("%d,%d\n",suc,unsuc);
		if(cases) puts("");
	}
	return 0;
}
