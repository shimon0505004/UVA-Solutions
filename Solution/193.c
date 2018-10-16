#include<stdio.h>
#include<string.h>
#define BLACK 0
#define WHITE 1
typedef struct NODE{
	int n_of_nb;
	int nbs[100];
	char color;
}Node;
Node ans[105];
int n,max;
typedef Node *NodePtr;
void push_nb(NodePtr node,int n){
	node->nbs[(node->n_of_nb)++]=n;
}
void dfs(int now,Node node[],char visit[],int blacks,int rest){
	char tmpvisit[105];
	int i,j,start,tmprest=rest;
	memcpy(tmpvisit,visit,sizeof(tmpvisit));
	if(rest==0){
		if(blacks>max){
			max=blacks;
			memcpy(ans,node,sizeof(ans));
		}
		return;
	}
	if(blacks+rest<max) return;
	if(rest==0) return;
	for(i=now+1;i<=n;i++)
		if(visit[i]==0){
			start=i;
			break;
		}
	tmprest--;
	for(j=0;j<node[start].n_of_nb;j++){
		if(visit[node[start].nbs[j]]==0) tmprest--;
		visit[node[start].nbs[j]]=1;
		node[node[start].nbs[j]].color=WHITE;
	}
	visit[start]=tmpvisit[start]=1;
	node[start].color=BLACK;
	dfs(start,node,visit,blacks+1,tmprest);
	dfs(start,node,tmpvisit,blacks,rest-1);
}
int main(){
	Node node[105];
	int cases,i,j,k,n1,n2;
	char visit[105];
	scanf("%d",&cases);
	while(cases--){
		memset(node,0,sizeof(node));
		scanf("%d%d",&n,&k);
		for(i=0;i<k;i++){
			scanf("%d%d",&n1,&n2);
			push_nb(node+n1,n2);
			push_nb(node+n2,n1);
		}
		max=0;
		memset(visit,0,sizeof(visit));
		dfs(0,node,visit,0,n);
		printf("%d\n",max);
		for(i=1;i<=n;i++)
			if(ans[i].color==BLACK){
				printf("%d",i);
				break;
			}
		for(i++;i<=n;i++)
			if(ans[i].color==BLACK)
				printf(" %d",i);
		puts("");
	}
	return 0;
}
