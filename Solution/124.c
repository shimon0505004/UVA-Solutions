#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 26
int count;
char ans[SIZE],var[SIZE],visit[SIZE];
int compar(const void *a,const void *b){
	return *((char *)a)-*((char *)b);
}
void print(char graph[][SIZE]){
	int i,j;
	for(i=0;i<count;i++){
		for(j=0;j<count;j++)
			printf("%d ",graph[var[i]][var[j]]);
		puts("");
	}
	puts("");
}
void dfs(int depth,char graph[SIZE][SIZE]){
	int i,j;
	char copy[SIZE][SIZE];
	if(count==depth){
		puts(ans);
		return;
	}
	for(i=0;i<count;i++){
		if(visit[i]) continue;
		memcpy(copy,graph,SIZE*SIZE*sizeof(char));
		for(j=0;j<count;j++) if(copy[var[i]][var[j]]) break;
		if(j<count) continue;
		for(j=0;j<count;j++) copy[var[j]][var[i]]=0;
		visit[i]=1;
		ans[depth]=var[i]+'a';
		dfs(depth+1,copy);
		visit[i]=0;
	}
}
int main(){
	char input[205],*ptr,graph[SIZE][SIZE];
	int w1,w2,i,j,start=0;
	while(fgets(input,205,stdin)!=NULL){
		if(start) puts("");
		start=1;
		count=0;
		memset(var,0,sizeof(var));
		for(ptr=strtok(input," ");ptr!=NULL;ptr=strtok(NULL," "))
			var[count++]=*ptr-'a';
		qsort(var,count,sizeof(char),compar);
		fgets(input,205,stdin);
		memset(graph,0,sizeof(graph));
		for(i=0,ptr=strtok(input," ");ptr!=NULL;ptr=strtok(NULL," "),i++)
			if(i%2==0)
				w1=*ptr-'a';
			else{
				w2=*ptr-'a';
				graph[w2][w1]=1;
			}
		memset(ans,0,sizeof(ans));
		memset(visit,0,sizeof(visit));
		dfs(0,graph);
	}
	return 0;
}
