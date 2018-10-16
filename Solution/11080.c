#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define W 1
#define B -1
#define ANO(x) (-(x))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
struct ADJ{
	int n;
	struct ADJ *next;
};
struct POINT{
	int n;
	struct ADJ *adj;
};
struct POINT p[205];
char visit[205];
int b,w;
char flag;
void insert(struct POINT *p,int adj){
	struct ADJ *ptr=p->adj;
	p->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	p->adj->next=ptr;
	p->adj->n=adj;
}
void paint(int n,char color){
	struct ADJ *adj;
	visit[n]=color;
	if(color==B) b++;
	else w++;
	for(adj=p[n].adj;adj!=NULL;adj=adj->next)
		if(visit[adj->n]==0) paint(adj->n,ANO(color));
		else if(visit[adj->n]==color) flag=1;
}
int main(){
	int cases;
	int v,e,i,n_v_c,from,to;
	for(i=0;i<205;i++) p[i].n=i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&v,&e);
		for(i=0;i<v;i++) p[i].adj=NULL;
		while(e--){
			scanf("%d%d",&from,&to);
			insert(&p[from],to),insert(&p[to],from);
		}
		memset(visit,0,sizeof(visit));
		n_v_c=0;
		flag=0;
		for(i=0;i<v&&flag==0;i++)
			if(visit[i]==0){
				b=w=0;
				paint(i,W);
				n_v_c+=MAX(MIN(b,w),1);
			}
		if(flag) puts("-1");
		else printf("%d\n",n_v_c);
	}
	return 0;
}
