#include<stdio.h>
#include<stdlib.h>
struct CONN{
	int from,to,cost;
	char used;
};
int compar(const void *a,const void *b){
	struct CONN *c1=(struct CONN *)a,*c2=(struct CONN *)b;
	return c1->cost-c2->cost;
}
int parent[105];
int find_root(int a){
	if(parent[a]!=a) parent[a]=find_root(parent[a]);
	return parent[a];
}
void link(int a,int b){
	parent[b]=a;
}
int main(){
	int cases,min_cost,next_min_cost,tmpcost,n_con;
	int i,j,r1,r2,A,B,C,M,N;
	struct CONN conn[5005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&N,&M);
		for(i=1;i<=N;i++) parent[i]=i;
		for(i=0;i<M;i++){
			scanf("%d%d%d",&A,&B,&C);
			conn[i].from=A,conn[i].to=B,conn[i].cost=C;
			conn[i].used=0;
		}
		qsort(conn,M,sizeof(struct CONN),compar);
		min_cost=0;
		for(i=0;i<M;i++){
			r1=find_root(conn[i].from),r2=find_root(conn[i].to);
			if(r1!=r2){
				min_cost+=conn[i].cost;
				conn[i].used=1;
				link(r1,r2);
			}
		}
		next_min_cost=2147483647;
		for(i=0;i<M;i++){
			if(conn[i].used==0) continue;
			for(j=1;j<=N;j++) parent[j]=j;
			tmpcost=n_con=0;
			for(j=0;j<M;j++){
				if(j==i) continue;
				r1=find_root(conn[j].from),r2=find_root(conn[j].to);
				if(r1!=r2){
					tmpcost+=conn[j].cost;
					if(tmpcost>next_min_cost) break;
					n_con++;
					link(r1,r2);
				}
			}
			if(tmpcost<next_min_cost&&n_con==N-1) next_min_cost=tmpcost;
		}
		printf("%d %d\n",min_cost,next_min_cost);
	}
	return 0;
}
