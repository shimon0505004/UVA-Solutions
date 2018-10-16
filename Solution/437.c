#include<stdio.h>
#include<stdlib.h>
struct BLOCK{
	int x,y,h;
};
int compar(const void *a,const void *b){
	struct BLOCK *b1=(struct BLOCK *)a,*b2=(struct BLOCK *)b;
	if(b1->x!=b2->x) return b1->x-b2->x;
	return b2->y-b1->y;
}
int main(){
	int n,i,j,a,b,c,max,cases;
	struct BLOCK block[200];
	int LIS[200];
	for(cases=1;scanf("%d",&n),n;cases++){
		for(i=0;i<n;i++){
			scanf("%d%d%d",&a,&b,&c);
			block[6*i].x=a,block[6*i].y=b,block[6*i].h=c;
			block[6*i+1].x=a,block[6*i+1].y=c,block[6*i+1].h=b;
			block[6*i+2].x=b,block[6*i+2].y=a,block[6*i+2].h=c;
			block[6*i+3].x=b,block[6*i+3].y=c,block[6*i+3].h=a;
			block[6*i+4].x=c,block[6*i+4].y=a,block[6*i+4].h=b;
			block[6*i+5].x=c,block[6*i+5].y=b,block[6*i+5].h=a;
		}
		n*=6;
		qsort(block,n,sizeof(struct BLOCK),compar);

		for(i=0;i<n;i++){
			LIS[i]=block[i].h;
			for(j=0;j<i;j++)
				if(block[j].x<block[i].x&&block[j].y<block[i].y&&LIS[i]<LIS[j]+block[i].h)
					LIS[i]=LIS[j]+block[i].h;
		}
		max=0;
		for(i=0;i<n;i++) if(max<LIS[i]) max=LIS[i];
		printf("Case %d: maximum height = %d\n",cases,max);
	}
	return 0;
}
