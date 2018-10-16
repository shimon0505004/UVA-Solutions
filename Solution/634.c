#include<stdio.h>
struct POINT{
	int x,y;
};
char left(struct POINT *ivst,struct POINT *p1,struct POINT *p2){
	if(p1->x==p2->x&&p1->x<ivst->x) return 1;
	return 0;
}
char cross_threshold(struct POINT *ivst,struct POINT *p1,struct POINT *p2){
	if(p1->y>=ivst->y&&p2->y<ivst->y) return 1;
	if(p2->y>=ivst->y&&p1->y<ivst->y) return 1;
	return 0;
}
char is_contain(struct POINT p[],struct POINT *ivst,int n_v){
	char result=0;
	int next,i;
	for(i=0;i<n_v;i++){
		next=(i+1)%n_v;
		if(cross_threshold(ivst,&p[i],&p[next]))
			if(left(ivst,&p[i],&p[next]))
				result=!result;
	}
	return result;
}
int main(){
	int n_v,i;
	struct POINT p[1005],ivst;
	while(scanf("%d",&n_v),n_v){
		for(i=0;i<n_v;i++) scanf("%d%d",&p[i].x,&p[i].y);
		scanf("%d%d",&ivst.x,&ivst.y);
		if(is_contain(p,&ivst,n_v)) puts("T");
		else puts("F");
	}
	return 0;
}
