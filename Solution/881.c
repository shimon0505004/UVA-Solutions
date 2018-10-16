#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct POINT{
	double x,y;
};
struct POLYGON{
	int n_v;
	struct POINT v[105];
	double area;
	int id;
};
struct ID_CONTAINER{
	int id;
	int container;
};
int compar1(const void *a,const void *b){
	struct POLYGON *p1=(struct POLYGON *)a,*p2=(struct POLYGON *)b;
	if(p1->area>p2->area) return 1;
	if(p1->area<p2->area) return -1;
	return 0;
}
int compar2(const void *a,const void *b){
	struct ID_CONTAINER *id_con1=(struct ID_CONTAINER *)a,*id_con2=(struct ID_CONTAINER *)b;
	return id_con1->id-id_con2->id;
}
void cal_area(struct POLYGON *poly){
	int i;
	poly->area=0;
	for(i=1;i<poly->n_v;i++)
		poly->area+=poly->v[i].y*poly->v[i-1].x-poly->v[i].x*poly->v[i-1].y;
	poly->area+=poly->v[0].y*poly->v[poly->n_v-1].x-poly->v[0].x*poly->v[poly->n_v-1].y;
	poly->area=fabs(poly->area);
}
char left(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p0->x-p1->x,v1.y=p0->y-p1->y;
	v2.x=p1->x-p2->x,v2.y=p1->y-p2->y;
	if(v2.y>0&&v1.x*v2.y>v1.y*v2.x) return 1;
	if(v2.y<0&&v1.x*v2.y<v1.y*v2.x) return 1;
	return 0;
}
char cross_threshold(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	if(p1->y+1e-5>p0->y&&p2->y<p0->y) return 1;
	if(p2->y+1e-5>p0->y&&p1->y<p0->y) return 1;
	return 0;
}
char is_contain(struct POLYGON *poly,struct POINT *p){
	int i,next;
	char result=0;
	for(i=0;i<poly->n_v;i++){
		next=(i+1)%(poly->n_v);
		if(cross_threshold(p,&(poly->v[i]),&(poly->v[next])))
			if(left(p,&(poly->v[i]),&(poly->v[next])))
				result=!result;
	}
	return result;
}
int main(){
	int cases;
	char input[300];
	struct POLYGON poly[300];
	int n_poly,n_point,i,j,id;
	struct ID_CONTAINER id_cont[300];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n_poly);
		for(i=0;i<n_poly;i++){
			int len;
			char *ptr;
			double x,y;
			scanf("%d",&id);
			fgets(input,300,stdin);
			poly[i].id=id;
			poly[i].n_v=0;
			for(ptr=input;sscanf(ptr,"%lf%lf%n",&x,&y,&len)==2;ptr+=len){
				poly[i].v[poly[i].n_v].x=x;
				poly[i].v[poly[i].n_v].y=y;
				poly[i].n_v++;
			}
			cal_area(&poly[i]);
		}
		qsort(poly,n_poly,sizeof(struct POLYGON),compar1);
		scanf("%d",&n_point);
		for(i=0;i<n_point;i++){
			struct POINT tmp;
			scanf("%d",&id);
			id_cont[i].id=id;
			scanf("%lf%lf",&tmp.x,&tmp.y);
			for(j=0;j<n_poly;j++)
				if(is_contain(&poly[j],&tmp)){
					id_cont[i].container=poly[j].id;
					break;
				}
			if(j==n_poly) id_cont[i].container=0;
		}
		qsort(id_cont,n_point,sizeof(struct ID_CONTAINER),compar2);
		for(i=0;i<n_point;i++)
			printf("%d %d\n",id_cont[i].id,id_cont[i].container);
		if(cases) puts("");
	}
	return 0;
}
