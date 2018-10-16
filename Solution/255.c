#include<stdio.h>
struct POINT{
	int x,y;
};
void cal_point(int n,struct POINT *p){
	p->x=n/8,p->y=n%8;
}
char illegal_state(struct POINT *pK,struct POINT *pQ,struct POINT *pnQ){
	if(pK->x==pQ->x&&pK->y==pQ->y) return 1;
	return 0;
}
char illegal_move(struct POINT *pK,struct POINT *pQ,struct POINT *pnQ){
	if(!((pQ->x==pnQ->x)^(pQ->y==pnQ->y))) return 1;
	if(pQ->x==pnQ->x){
		if(pK->x!=pQ->x) return 0;
		if((pK->y-pQ->y)*(pK->y-pnQ->y)<=0) return 1;
		return 0;
	}
	if(pK->y!=pQ->y) return 0;
	if((pK->x-pQ->x)*(pK->x-pnQ->x)<=0) return 1;
	return 0;
}
char Move_not_allowed(struct POINT *pK,struct POINT *pQ,struct POINT *pnQ){
	if(pnQ->x==pK->x&&(pK->y-pnQ->y)*(pK->y-pnQ->y)==1) return 1;
	if(pnQ->y==pK->y&&(pK->x-pnQ->x)*(pK->x-pnQ->x)==1) return 1;
	return 0;
}
char Continue(struct POINT *pK,struct POINT *pQ,struct POINT *pnQ){
	if(pK->x>0&&pK->x-1!=pnQ->x&&pK->y!=pnQ->y) return 1;
	if(pK->x<7&&pK->x+1!=pnQ->x&&pK->y!=pnQ->y) return 1;
	if(pK->y>0&&pK->x!=pnQ->x&&pK->y-1!=pnQ->y) return 1;
	if(pK->y<7&&pK->x!=pnQ->x&&pK->y+1!=pnQ->y) return 1;
	return 0;
}
int main(){
	int K,Q,nQ;
	struct POINT pK,pQ,pnQ;
	while(scanf("%d%d%d",&K,&Q,&nQ)==3){
		cal_point(K,&pK),cal_point(Q,&pQ),cal_point(nQ,&pnQ);
		if(illegal_state(&pK,&pQ,&pnQ)) puts("Illegal state");
		else if(illegal_move(&pK,&pQ,&pnQ)) puts("Illegal move");
		else if(Move_not_allowed(&pK,&pQ,&pnQ)) puts("Move not allowed");
		else if(Continue(&pK,&pQ,&pnQ)) puts("Continue");
		else puts("Stop");
	}
	return 0;
}
