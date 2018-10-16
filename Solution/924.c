#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 2505
struct ADJ{
	int n;
	struct ADJ *next;
};
struct EMPOLYEE{
	struct ADJ *adj;
	int depth;
};
void insert(struct EMPOLYEE *emp,int n){
	struct ADJ *tmpadj=emp->adj;
	emp->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	emp->adj->next=tmpadj;
	emp->adj->n=n;
}
int queue[SIZE],head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int result=queue[tail++];
	tail%=SIZE;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int E,T,n_adj;
	int i,max,maxi;
	struct EMPOLYEE emp[SIZE];
	int dep_count[SIZE];
	scanf("%d",&E);
	for(i=0;i<E;i++){
		scanf("%d",&n_adj);
		emp[i].adj=NULL;
		while(n_adj--){
			int adj;
			scanf("%d",&adj);
			insert(&emp[i],adj);
		}
	}
	scanf("%d",&T);
	while(T--){
		int src;
		scanf("%d",&src);
		initial();
		for(i=0;i<E;i++) emp[i].depth=E;
		emp[src].depth=0;
		enqueue(src);
		while(!is_empty()){
			int cur=dequeue();
			struct ADJ *nowadj;
			for(nowadj=emp[cur].adj;nowadj!=NULL;nowadj=nowadj->next){
				if(emp[nowadj->n].depth==E){
					emp[nowadj->n].depth=emp[cur].depth+1;
					enqueue(nowadj->n);
				}
			}
		}
		memset(dep_count,0,sizeof(dep_count));
		for(i=0;i<E;i++)
			dep_count[emp[i].depth]++;
		max=0;
		for(i=1;i<E;i++)
			if(max<dep_count[i])
				max=dep_count[i],maxi=i;
		if(max==0) puts("0");
		else printf("%d %d\n",max,maxi);
	}
	return 0;
}
