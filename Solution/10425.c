#include<stdio.h>
struct POINT{
	long long x,y,z;
};
long long dis_sqr(struct POINT *p1,struct POINT *p2){
	struct POINT v;
	v.x=p1->x-p2->x,v.y=p1->y-p2->y,v.z=p1->z-p2->z;
	return v.x*v.x+v.y*v.y+v.z*v.z;
}
char on_cross_plane(struct POINT *p1,struct POINT *p2,struct POINT *p,long long r1_sqr,long long r2_sqr){
	return (p1->x-p2->x)*(p1->x+p2->x-2*p->x)+(p1->y-p2->y)*(p1->y+p2->y-2*p->y)+(p1->z-p2->z)*(p1->z+p2->z-2*p->z)==r1_sqr-r2_sqr;
}
int main(){
	char name[10];
	struct POINT sphere1,sphere2,set;
	long long r1,r2,d1,d2;
	while(scanf("%s",name)==1){
		puts(name);
		scanf("%lld%lld%lld%lld",&sphere1.x,&sphere1.y,&sphere1.z,&r1);
		scanf("%lld%lld%lld%lld",&sphere2.x,&sphere2.y,&sphere2.z,&r2);
		scanf("%lld%lld%lld",&set.x,&set.y,&set.z);
		d1=dis_sqr(&set,&sphere1),d2=dis_sqr(&set,&sphere2);
		r1*=r1,r2*=r2;
		if(d1<=r1) puts("y");
		else puts("n");
		if(d2<=r2) puts("y");
		else puts("n");
		if(d1<=r1||d2<=r2){
			if(on_cross_plane(&sphere1,&sphere2,&set,r1,r2)) puts("n");
			else puts("y");
		}else puts("n");
	}
	return 0;
}
