#include<stdio.h>
struct POINT{
	long long x,y;
};
int cross_product(struct POINT *p0,struct POINT *p1){
	long long x1=p0->x,y1=p0->y;
	long long x2=p1->x,y2=p1->y;
	long long cp=x1*y2-x2*y1;
	if(cp>0) return 1;
	if(cp<0) return -1;
	return 0;
}
char contain_0(struct POINT p[],int N){
	struct POINT pos_far=p[0],neg_far=p[0];
	int i;
	for(i=1;i<N;i++){
		int cp=cross_product(p,p+i);
		if(cp>0){
			if(cross_product(&pos_far,p+i)>0) pos_far=p[i];
		}else if(cp<0){
			if(cross_product(&neg_far,p+i)<0) neg_far=p[i];
		}else{
			if(p[0].x*p[i].x<0||p[0].y*p[i].y<0) return 1;
		}
	}
	if(cross_product(&pos_far,&neg_far)>=0) return 1;
	return 0;
}
int main(){
	int N;
	int i;
	struct POINT p[1005];
	while(scanf("%d",&N),N){
		long long p1,p2,p3;
		for(i=0;i<N;i++){
			scanf("%lld%lld%lld",&p1,&p2,&p3);
			p[i].x=p2-p1,p[i].y=p3-p1;
		}
		if(contain_0(p,N)) puts("Yes");
		else puts("No");
	}
	return 0;
}
