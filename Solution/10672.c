#include<stdio.h>
#include<stdlib.h>
struct ADJ{
	int n;
	struct ADJ *next;
};
struct NODE{
	struct ADJ *adj;
	int parent,deg,val,subsum,n_child;
};
struct NODE node[10005];
void insert(struct NODE *node,int adj){
	struct ADJ *ptr=node->adj;
	node->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	node->adj->n=adj;
	node->adj->next=ptr;
}
void add_all_children(int cur){
	int i;
	struct ADJ *ptr=node[cur].adj;
	node[cur].subsum=node[cur].val;
	node[cur].n_child=1;
	for(i=0;i<node[cur].deg;i++,ptr=ptr->next){
		add_all_children(ptr->n);
		node[cur].subsum+=node[ptr->n].subsum;
		node[cur].n_child+=node[ptr->n].n_child;
	}
}
int main(){
	int n,i,j,seq,adj,root,n_move;
	while(scanf("%d",&n),n){
		for(i=1;i<=n;i++) node[i].parent=0;
		for(i=0;i<n;i++){
			scanf("%d",&seq);
			scanf("%d%d",&node[seq].val,&node[seq].deg);
			for(j=0;j<node[seq].deg;j++){
				scanf("%d",&adj);
				insert(&node[seq],adj);
				node[adj].parent=seq;
			}
		}
		for(i=1;i<=n;i++) if(node[i].parent==0) root=i;
		add_all_children(root);
		n_move=0;
		for(i=1;i<=n;i++)
			if(node[i].parent)
				n_move+=abs(node[i].subsum-node[i].n_child);
		printf("%d\n",n_move);
	}
	return 0;
}
