#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000
struct ADJ{
	int n;
	struct ADJ *next;
};
struct NODE{
	struct ADJ *adj;
	int paths;
};
void ins_adj(struct NODE *node,int adj){
	struct ADJ *tmp=node->adj;
	node->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	node->adj->next=tmp;
	node->adj->n=adj;
}
int main(){
	int n,i,count,sum;
	struct NODE node[SIZE];
	char start=0;
	while(scanf("%d",&n)==1){
		if(start) puts("");
		else start=1;
		for(i=0;i<n;i++){
			scanf("%d",&count);
			node[i].adj=NULL;
			node[i].paths=0;
			while(count--){
				int adj;
				scanf("%d",&adj);
				ins_adj(&node[i],adj);
			}
		}
		node[0].paths=1;
		for(i=0;i<n;i++){
			struct ADJ *adj;
			for(adj=node[i].adj;adj!=NULL;adj=adj->next)
				node[adj->n].paths+=node[i].paths;
		}
		sum=0;
		for(i=0;i<n;i++)
			if(node[i].adj==NULL)
				sum+=node[i].paths;
		printf("%d\n",sum);
	}
	return 0;
}
