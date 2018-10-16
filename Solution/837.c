#include<stdio.h>
#include<stdlib.h>
#define EPS (1e-5)
struct SEGMENT{
	double left,right,rate;
};
int compar(const void *a,const void *b){
	double *dbl1=(double *)a,*dbl2=(double *)b;
	if(*dbl1>*dbl2) return 1;
	if(*dbl1<*dbl2) return -1;
	return 0;
}
int main(){
	int cases,n,i,j;
	double p[2005];
	struct SEGMENT seg[1005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%lf%*s%lf%*s%lf",&seg[i].left,&seg[i].right,&seg[i].rate);
			if(seg[i].right<seg[i].left){
				double tmp=seg[i].right;
				seg[i].right=seg[i].left,seg[i].left=tmp;
			}
			p[i*2]=seg[i].left,p[i*2+1]=seg[i].right;
		}
		qsort(p,n*2,sizeof(double),compar);
		printf("%d\n",2*n+1);
		printf("-inf %.3lf 1.000\n",p[0]);
		for(i=0;i<2*n-1;i++){
			double energy=1;
			printf("%.3lf %.3lf ",p[i],p[i+1]);
			for(j=0;j<n;j++)
				if(seg[j].left<p[i]+EPS&&seg[j].right+EPS>p[i+1])
					energy*=seg[j].rate;
			printf("%.3lf\n",energy);
		}
		printf("%.3lf +inf 1.000\n",p[2*n-1]);
		if(cases) puts("");
	}
	return 0;
}
