#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
struct POINT_dbl{
	double x,y;
}c_h[200];
int n_c_h;
void push(struct POINT *p){
	c_h[n_c_h].x=p->x,c_h[n_c_h].y=p->y;
	n_c_h++;
}
int inner_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1={p1->x-p0->x,p1->y-p0->y},v2={p2->x-p0->x,p2->y-p0->y};
	return v1.x*v2.x+v1.y*v2.y;
}
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1={p1->x-p0->x,p1->y-p0->y},v2={p2->x-p0->x,p2->y-p0->y};
	return v1.x*v2.y-v1.y*v2.x;
}
double cross_product_dbl(struct POINT_dbl *p0,struct POINT_dbl *p1,struct POINT_dbl *p2){
	struct POINT_dbl v1={p1->x-p0->x,p1->y-p0->y},v2={p2->x-p0->x,p2->y-p0->y};
	return v1.x*v2.y-v1.y*v2.x;
}
char inside(struct POINT *p,struct POINT poly[],int n_v){
	int i,ip,cp,is_inside=0;
	for(i=0;i<n_v;i++){
		int ni=(i+1)%n_v;
		ip=inner_product(p,&poly[i],&poly[ni]);
		cp=cross_product(p,&poly[i],&poly[ni]);
		if(ip<=0&&cp==0) return 1;
		if(poly[i].y<p->y&&poly[ni].y>=p->y){
			if(cp<0) is_inside=1-is_inside;
		}else if(poly[ni].y<p->y&&poly[i].y>=p->y){
			if(cp>0) is_inside=1-is_inside;
		}
	}
	return is_inside;
}
int double_area(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	return abs(cross_product(p0,p1,p2));
}
char cal_cross_point(struct POINT *L1_1,struct POINT *L1_2,struct POINT *L2_1,struct POINT *L2_2,struct POINT_dbl *res){
	if(cross_product(L1_1,L2_1,L2_2)*cross_product(L1_2,L2_1,L2_2)<0)
		if(cross_product(L2_1,L1_1,L1_2)*cross_product(L2_2,L1_1,L1_2)<0){
			int a1=double_area(L2_1,L1_1,L1_2),a2=double_area(L2_2,L1_1,L1_2);
			double t=(double)a1/(a1+a2);
			res->x=(double)L2_1->x+t*(L2_2->x-L2_1->x);
			res->y=(double)L2_1->y+t*(L2_2->y-L2_1->y);
			return 1;
		}
	return 0;
}
int compar(const void *a,const void *b){
	struct POINT_dbl *p1=(struct POINT_dbl *)a,*p2=(struct POINT_dbl *)b;
	double cp=cross_product_dbl(&c_h[0],p1,p2);
	if(cp>0) return 1;
	return -1;
}
void sort(struct POINT_dbl c_h[],int n_c_h){
	int lu=0,i;
	struct POINT_dbl temp;
	for(i=1;i<n_c_h;i++)
		if(c_h[i].x<c_h[lu].x) lu=i;
		else if(c_h[i].x==c_h[lu].x&&c_h[i].y<c_h[lu].y) lu=i;
	temp=c_h[0],c_h[0]=c_h[lu],c_h[lu]=temp;
	qsort(c_h+1,n_c_h-1,sizeof(struct POINT_dbl),compar);
}
int main(){
	int n_v1,n_v2;
	int i,j;
	double area;
	struct POINT poly1[100],poly2[100];
	while(scanf("%d",&n_v1),n_v1){
		area=0;
		for(i=0;i<n_v1;i++) scanf("%d%d",&poly1[i].x,&poly1[i].y);
		scanf("%d",&n_v2);
		for(i=0;i<n_v2;i++) scanf("%d%d",&poly2[i].x,&poly2[i].y);
		for(i=0;i<n_v1;i++) area+=(double)(poly1[i].y*poly1[(i+1)%n_v1].x-poly1[i].x*poly1[(i+1)%n_v1].y)/2;
		for(i=0;i<n_v2;i++) area+=(double)(poly2[i].y*poly2[(i+1)%n_v2].x-poly2[i].x*poly2[(i+1)%n_v2].y)/2;
		n_c_h=0;
		for(i=0;i<n_v1;i++) if(inside(&poly1[i],poly2,n_v2)) push(&poly1[i]);
		for(i=0;i<n_v2;i++) if(inside(&poly2[i],poly1,n_v1)) push(&poly2[i]);
		for(i=0;i<n_v1;i++){
			int ni=(i+1)%n_v1;
			for(j=0;j<n_v2;j++){
				int nj=(j+1)%n_v2;
				struct POINT_dbl cross;
				if(cal_cross_point(&poly1[i],&poly1[ni],&poly2[j],&poly2[nj],&cross))
					c_h[n_c_h++]=cross;
			}
		}
		if(n_c_h>0) sort(c_h,n_c_h);
		for(i=0;i<n_c_h;i++){
			int ni=(i+1)%n_c_h;
			area-=c_h[i].y*c_h[ni].x-c_h[i].x*c_h[ni].y;
		}
		printf("%8.2lf",area);
	}
	puts("");
	return 0;
}
