#include<stdio.h>
#include<stdlib.h>
struct ROAD{
	int from,to,cap;
};
int compar(const void *a,const void *b){
	struct ROAD *r1=(struct ROAD *)a,*r2=(struct ROAD *)b;
	return r2->cap-r1->cap;
}
int parent[105];
int find_root(int a){
	if(a!=parent[a]) parent[a]=find_root(parent[a]);
	return parent[a];
}
void link(int a,int b){
	parent[a]=b;
}
int main(){
	int T,cases;
	int n,m,i,min;
	struct ROAD r[10005];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d",&n,&m);
		for(i=0;i<m;i++) scanf("%d%d%d",&r[i].from,&r[i].to,&r[i].cap);
		for(i=0;i<n;i++) parent[i]=i;
		qsort(r,m,sizeof(struct ROAD),compar);
		min=r[0].cap;
		for(i=0;i<m;i++){
			int r1=find_root(r[i].from),r2=find_root(r[i].to);
			if(r1!=r2){
				link(r1,r2);
				min=r[i].cap;
			}
		}
		printf("Case #%d: %d\n",cases,min);
	}
	return 0;
}
