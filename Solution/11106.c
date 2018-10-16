#include<stdio.h>
#include<stdlib.h>
#define SIZE 100005
struct POINT{
	int x,y,n;
};
int compar1(const void *a,const void *b){
	struct POINT *p1=(struct POINT *)a,*p2=(struct POINT *)b;
	if(p1->x!=p2->x) return p1->x-p2->x;
	return p1->y-p2->y;
}
int compar2(const void *a,const void *b){
	struct POINT *p1=(struct POINT *)a,*p2=(struct POINT *)b;
	if(p1->y!=p2->y) return p1->y-p2->y;
	return p1->x-p2->x;
}
int parent[SIZE];
int find_root(int n){
	if(parent[n]!=n) parent[n]=find_root(parent[n]);
	return parent[n];
}
void link(int a,int b){
	parent[a]=b;
}
int vertical(struct POINT p[],int n){
	int result=0,i;
	for(i=0;i<n;i+=2){
		int r1,r2;
		if(p[i].x!=p[i+1].x) return -1;
		result+=p[i+1].y-p[i].y;
		r1=find_root(p[i].n),r2=find_root(p[i+1].n);
		if(r1==r2) return -1;
		link(r1,r2);
	}
	return result;
}
int horizontal(struct POINT p[],int n){
	int result=0,i;
	for(i=0;i<n;i+=2){
		int r1,r2;
		if(p[i].y!=p[i+1].y) return -1;
		result+=p[i+1].x-p[i].x;
		r1=find_root(p[i].n),r2=find_root(p[i+1].n);
		if(r1==r2&&i<n-2) return -1;
		link(r1,r2);
	}
	return result;
}
int main(){
	struct POINT p[SIZE];
	int cases,n,v,h,i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		if(n%2!=0){
			puts("-1");
			continue;
		}
		for(i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].n=i,parent[i]=i;
		qsort(p,n,sizeof(struct POINT),compar1);
		if((v=vertical(p,n))<0){
			puts("-1");
			continue;
		}
		qsort(p,n,sizeof(struct POINT),compar2);
		h=horizontal(p,n);
		if(h<0) puts("-1");
		else printf("%d\n",h+v);
	}
	return 0;
}
