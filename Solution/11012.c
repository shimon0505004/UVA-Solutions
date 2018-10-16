#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y,z;
};
int distance(struct POINT *p1,struct POINT *p2){
	return abs(p1->x-p2->x)+abs(p1->y-p2->y)+abs(p1->z-p2->z);
}
int main(){
	int N,n,cases,i,j,d;
	int largest;
	struct POINT p[100005],maxp,minp;
	struct POINT ep[8];
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		scanf("%d",&n);
		maxp.x=maxp.y=maxp.z=-100000001;
		minp.x=minp.y=minp.z=100000001;
		for(i=0;i<n;i++){
			scanf("%d%d%d",&(p[i].x),&(p[i].y),&(p[i].z));
			if(p[i].x>maxp.x) maxp.x=p[i].x;
			if(p[i].y>maxp.y) maxp.y=p[i].y;
			if(p[i].z>maxp.z) maxp.z=p[i].z;
			if(p[i].x<minp.x) minp.x=p[i].x;
			if(p[i].y<minp.y) minp.y=p[i].y;
			if(p[i].z<minp.z) minp.z=p[i].z;
		}
		ep[0].x=maxp.x,ep[0].y=maxp.y,ep[0].z=maxp.z;
		ep[1].x=maxp.x,ep[1].y=maxp.y,ep[1].z=minp.z;
		ep[2].x=maxp.x,ep[2].y=minp.y,ep[2].z=maxp.z;
		ep[3].x=maxp.x,ep[3].y=minp.y,ep[3].z=minp.z;
		ep[4].x=minp.x,ep[4].y=maxp.y,ep[4].z=maxp.z;
		ep[5].x=minp.x,ep[5].y=maxp.y,ep[5].z=minp.z;
		ep[6].x=minp.x,ep[6].y=minp.y,ep[6].z=maxp.z;
		ep[7].x=minp.x,ep[7].y=minp.y,ep[7].z=minp.z;
		for(i=0;i<8;i++){
			int closest,minj;
			closest=100000001;
			for(j=0;j<n;j++)
				if((d=distance(&ep[i],&p[j]))<closest)
					closest=d,minj=j;
			ep[i]=p[minj];
		}
		largest=0;
		for(i=0;i<8;i++){
			for(j=0;j<n;j++)
				if((d=distance(&ep[i],&p[j]))>largest)
					largest=d;
		}
		printf("Case #%d: %d\n",cases,largest);
	}
	return 0;
}
