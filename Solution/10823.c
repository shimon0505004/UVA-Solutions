#include<stdio.h>
#include<math.h>
#define SQUARE 0
#define CIRCLE 1
#define BORDERLINE 1
#define INSIDE 2
#define EPS 1e-6
struct POINT{
	int x,y;
};
struct REGION{
	int r,g,b,s;
	struct POINT p;
	char type;
};
double distance(struct POINT *p1,struct POINT *p2){
	int x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
char inside(struct REGION *r,struct POINT *p){
	double d;
	if(r->type==SQUARE){
		if(p->x>r->p.x&&p->x<r->p.x+r->s&&p->y>r->p.y&&p->y<r->p.y+r->s)
			return INSIDE;
		if(p->x>r->p.x+r->s||p->x<r->p.x) return 0;
		if(p->y>r->p.y+r->s||p->y<r->p.y) return 0;
		return BORDERLINE;
	}else{
		d=distance(p,&(r->p));
		if(d<(double)r->s) return INSIDE;
		if(fabs(d-(double)r->s)<EPS) return BORDERLINE;
		return 0;
	}
}
int round(int a,int b){
	if(2*(a%b)>=b)
		return a/b+1;
	return a/b;
}
int main(){
	int T,cases,R,P,i,j,r,g,b;
	struct REGION region[105];
	struct POINT p;
	char figure[10],found;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		if(cases>1) puts("");
		printf("Case %d:\n",cases);
		scanf("%d%d",&R,&P);
		for(i=0;i<R;i++){
			scanf("%s%d%d%d%d%d%d",figure,&region[i].p.x,&region[i].p.y,&region[i].s,&region[i].r,&region[i].g,&region[i].b);
			if(*figure=='S')
				region[i].type=SQUARE;
			else
				region[i].type=CIRCLE;
		}
		for(i=0;i<P;i++){
			scanf("%d%d",&p.x,&p.y);
			found=0;
			r=g=b=0;
			for(j=0;j<R;j++){
				char result=inside(&(region[j]),&p);
				if(result==INSIDE){
					found++;
					r+=region[j].r;
					g+=region[j].g;
					b+=region[j].b;
				}else if(result==BORDERLINE){
					found=-1;
					break;
				}
			}
			if(found==0)
				puts("(255, 255, 255)");
			else if(found==-1)
				puts("(0, 0, 0)");
			else
				printf("(%d, %d, %d)\n",round(r,found),round(g,found),round(b,found));
		}
	}
	return 0;
}
