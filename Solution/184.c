#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
struct LINE{
	struct POINT pstart,vector;
};
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v1.y*v2.x;
}
int compar(const void *a,const void *b){
	struct POINT *p1=(struct POINT *)a,*p2=(struct POINT *)b;
	if(p1->x!=p2->x) return p1->x-p2->x;
	return p1->y-p2->y;
}
char printed(struct POINT *p1,struct POINT *p2,struct LINE line[],int n_line){
	int i;
	for(i=0;i<n_line;i++){
		int cp=cross_product(p1,p2,&(line[i].pstart));
		int x=p2->x-p1->x,y=p2->y-p1->y;
		if(cp==0&&x*line[i].vector.y==y*line[i].vector.x) return 1;
	}
	return 0;
}
int main(){
	struct POINT p[305];
	char start,casestart;
	struct LINE line[1000];
	int n,i,j,k,n_line;
	for(;;){
		for(n=0;scanf("%d%d",&p[n].x,&p[n].y),p[n].x|p[n].y;n++);
		if(n==0) break;
		qsort(p,n,sizeof(struct POINT),compar);
		casestart=0;
		n_line=0;
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				start=0;
				if(printed(&p[i],&p[j],line,n_line)) continue;
				for(k=j+1;k<n;k++){
					if(cross_product(&p[i],&p[j],&p[k])==0){
						if(start==0){
							if(casestart==0) puts("The following lines were found:");
							printf("(%4d,%4d)",p[i].x,p[i].y);
							printf("(%4d,%4d)",p[j].x,p[j].y);
							line[n_line].pstart.x=p[i].x;
							line[n_line].pstart.y=p[i].y;
							line[n_line].vector.x=p[j].x-p[i].x;
							line[n_line].vector.y=p[j].y-p[i].y;
							n_line++;
							start=casestart=1;
						}
						printf("(%4d,%4d)",p[k].x,p[k].y);
					}
				}
				if(start) puts("");
			}
		}
		if(casestart==0) puts("No lines were found");
	}
	return 0;
}
