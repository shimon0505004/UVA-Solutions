#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
struct POINT{
	int x,y;
};
int inner_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.x+v1.y*v2.y;
}
char baseline(struct POINT *p1,struct POINT *p2,struct POINT *c_mass){
	if(inner_product(p1,p2,c_mass)>0&&inner_product(p2,p1,c_mass)>0) return 1;
	return 0;
}
int cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v2.x*v1.y;
}
int convex_hull(struct POINT bumpy[],int n_v,int convex_v[]){
	int i,ldm=0,count=0,now,next,find;
	struct POINT p_ldm=bumpy[ldm];
	for(i=1;i<n_v;i++)
		if(bumpy[i].x<p_ldm.x) ldm=i,p_ldm=bumpy[i];
		else if(bumpy[i].x==p_ldm.x&&bumpy[i].y<p_ldm.y) ldm=i,p_ldm=bumpy[i];
	convex_v[count++]=ldm;
	now=ldm;
	for(;;){
		next=(now+1)%n_v;
		for(i=2;i<n_v;i++){
			find=(now+i)%n_v;
			if(cross_product(&bumpy[now],&bumpy[next],&bumpy[find])<=0) next=find;
		}
		if(next==convex_v[0]) break;
		convex_v[count++]=next;
		now=next;
	}
	return count;
}
int main(){
	struct POINT bumpy[100],c_mass;
	char objname[25];
	int convex_v[100],n_convex;
	int n_v,x,y,i,t,min;
	while(scanf("%s",objname),*objname!='#'){
		scanf("%d%d",&c_mass.x,&c_mass.y);
		for(n_v=0;scanf("%d%d",&x,&y),x||y;n_v++)
			bumpy[n_v].x=x,bumpy[n_v].y=y;
		n_convex=convex_hull(bumpy,n_v,convex_v);
		min=n_v;
		for(i=0;i<n_convex-1;i++)
			if(baseline(&bumpy[convex_v[i]],&bumpy[convex_v[i+1]],&c_mass))
				if(min>(t=MAX(convex_v[i],convex_v[i+1])))
					min=t;
		if(baseline(&bumpy[convex_v[n_convex-1]],&bumpy[convex_v[0]],&c_mass))
			if(min>(t=MAX(convex_v[n_convex-1],convex_v[0])))
				min=t;
		printf("%-19s %2d\n",objname,min+1);
	}
	return 0;
}
