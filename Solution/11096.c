#include<stdio.h>
#include<math.h>
struct POINT{
	long long x,y;
};
long long cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	return v1.x*v2.y-v1.y*v2.x;
}
long long dis_sqr(struct POINT *p1,struct POINT *p2){
	long long x=p2->x-p1->x,y=p2->y-p1->y;
	return x*x+y*y;
}
double dis(struct POINT *p1,struct POINT *p2){
	return sqrt(dis_sqr(p1,p2));
}
double convex_hull_length(struct POINT p[],int n_p){
	int now,start=0,next;
	int i;
	int n_ch=0,ch[105];
	double len;
	for(i=1;i<n_p;i++)
		if(p[i].x<p[start].x) start=i;
		else if(p[i].x==p[start].x&&p[i].y<p[start].y) start=i;
	now=start;
	do{
		ch[n_ch++]=now;
		next=(now+1)%n_p;
		for(i=0;i<n_p;i++){
			long long cp;
			if(i==now||i==next) continue;
			cp=cross_product(&p[now],&p[i],&p[next]);
			if(cp>0) next=i;
			else if(cp==0&&dis_sqr(&p[now],&p[i])>dis_sqr(&p[now],&p[next])) next=i;
		}
		now=next;
	}while(now!=start);
	for(i=0,len=0;i<n_ch;i++)
		len+=dis(&p[ch[i]],&p[ch[(i+1)%n_ch]]);
	return len;
}
int main(){
	int cases;
	int l,n,i;
	double ch_len;
	struct POINT p[105];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&l,&n);
		for(i=0;i<n;i++) scanf("%lld%lld",&p[i].x,&p[i].y);
		if(n<=1) printf("%.5lf\n",(double)l);
		else{
			ch_len=convex_hull_length(p,n);
			if(ch_len>l) printf("%.5lf\n",ch_len);
			else printf("%.5lf\n",(double)l);
		}
	}
	return 0;
}
