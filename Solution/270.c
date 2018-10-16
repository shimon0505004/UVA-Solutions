#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
struct POINT *pptr[705];
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	if(v1.y<0) v1.x=-v1.x,v1.y=-v1.y;
	else if(v1.y==0) v1.x=abs(v1.x);
	if(v2.y<0) v2.x=-v2.x,v2.y=-v2.y;
	else if(v2.y==0) v2.x=abs(v2.x);
	return v1.x*v2.y-v1.y*v2.x;
}
int compar(const void *a,const void *b){
	struct POINT *p1=*((struct POINT **)a),*p2=*((struct POINT **)b);
	return cross_product(pptr[0],p1,p2);
}
int main(){
	int cases;
	char input[50];
	struct POINT p[705],*temp;
	int n,i,j,max,now,k;
	scanf("%d ",&cases);
	while(cases--){
		for(n=0;fgets(input,50,stdin)!=NULL&&*input!='\n';n++)
			sscanf(input,"%d%d",&p[n].x,&p[n].y);
		max=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++) pptr[j]=&(p[j]);
			temp=pptr[i],pptr[i]=pptr[0],pptr[0]=temp;
			qsort(pptr+1,n-1,sizeof(struct POINT *),compar);
			for(j=1;j<n;j++){
				now=2;
				for(k=j+1;k<n;k++)
					if(cross_product(pptr[0],pptr[j],pptr[k])==0) now++;
					else{
						j=k-1;
						break;
					}
				if(now>max) max=now;
			}
		}
		printf("%d\n",max);
		if(cases) puts("");
	}
	return 0;
}
