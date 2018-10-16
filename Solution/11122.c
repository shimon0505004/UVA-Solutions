#include<stdio.h>
struct POINT{
	int x,y;
};
char cross_product(struct POINT *p0,struct POINT *p1,struct POINT *p2){
	struct POINT v1,v2;
	int cp;
	v1.x=p1->x-p0->x,v1.y=p1->y-p0->y;
	v2.x=p2->x-p0->x,v2.y=p2->y-p0->y;
	cp=v1.x*v2.y-v1.y*v2.x;
	if(cp>0) return 1;
	if(cp<0) return -1;
	return 0;
}
char inside(struct POINT *p,struct POINT tri[]){
	char cp1,cp2,cp3;
	cp1=cross_product(p,&tri[0],&tri[1]),cp2=cross_product(p,&tri[1],&tri[2]),cp3=cross_product(p,&tri[2],&tri[0]);
	if(cp1*cp2>0&&cp2*cp3>0) return 1;
	if(cp1==0&&cp2*cp3>=0) return 0;
	if(cp2==0&&cp1*cp3>=0) return 0;
	if(cp3==0&&cp1*cp2>=0) return 0;
	return -1;
}
char intersect_segment(struct POINT *L1_1,struct POINT *L1_2,struct POINT *L2_1,struct POINT *L2_2){
	char d1=cross_product(L1_1,L2_1,L2_2),d2=cross_product(L1_2,L2_1,L2_2);
	char d3=cross_product(L2_1,L1_1,L1_2),d4=cross_product(L2_2,L1_1,L1_2);
	if(d1*d2<0&&d3*d4<0) return 1;
	return 0;
}
char cip(struct POINT tri1[],struct POINT tri2[]){
	int i,j,on_seg=0;
	for(i=0;i<3;i++){
		int in1=inside(&tri1[i],tri2),in2=inside(&tri2[i],tri1);
		if(in1==1||in2==1) return 1;
		if(in1==0) on_seg++;
		if(in2==0) on_seg++;
	}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(tri1[i].x==tri2[j].x&&tri1[i].y==tri2[j].y) on_seg--;
	if(on_seg>=3) return 1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(intersect_segment(&tri1[i],&tri1[(i+1)%3],&tri2[j],&tri2[(j+1)%3])) return 1;
	return 0;
}
int main(){
	struct POINT tri1[3],tri2[3];
	int T,cases;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d%d%d%d%d",&tri1[0].x,&tri1[0].y,&tri1[1].x,&tri1[1].y,&tri1[2].x,&tri1[2].y);
		scanf("%d%d%d%d%d%d",&tri2[0].x,&tri2[0].y,&tri2[1].x,&tri2[1].y,&tri2[2].x,&tri2[2].y);
		printf("pair %d: ",cases);
		if(cip(tri1,tri2)) puts("yes");
		else puts("no");
	}
	return 0;
}
