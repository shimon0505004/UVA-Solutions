#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 1e-6
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
struct SPRINKLER{
	double l,r;
};
int compar(const void *a,const void *b){
	struct SPRINKLER *sp1=(struct SPRINKLER *)a,*sp2=(struct SPRINKLER *)b;
	if(fabs(sp1->l-sp2->l)>EPS){
		if(sp1->l>sp2->l) return 1;
		return -1;
	}else{
		if(sp1->r>sp2->r) return -1;
		return 1;
	}
}
int main(){
	int n,l,w;
	int i;
	int now,count;
	struct SPRINKLER sp[10005];
	while(scanf("%d%d%d",&n,&l,&w)==3){
		for(i=0;i<n;i++){
			int p,r;
			double d;
			scanf("%d%d",&p,&r);
			d=sqrt((double)r*r-w*w/4.0);
			sp[i].l=MAX(0,(double)p-d);
			sp[i].r=MIN(l,(double)p+d);
		}
		qsort(sp,n,sizeof(struct SPRINKLER),compar);
		if(sp[0].l>0) puts("-1");
		else{
			count=1;
			now=0;
			do{
				double rightmost=sp[now].r;
				int righti=-1;
				for(i=now+1;i<n&&sp[now].r+EPS>sp[i].l;i++)
					if(sp[i].r>rightmost) rightmost=sp[i].r,righti=i;
				if(righti==-1) break;
				now=righti;
				count++;
			}while(sp[now].r+EPS<l);
			if(sp[now].r+EPS<l) puts("-1");
			else printf("%d\n",count);
		}
	}
	return 0;
}
