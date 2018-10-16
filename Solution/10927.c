#include<stdio.h>
struct POLE{
	int x,y;
	int z;
};
int compar(const void *a,const void *b){
	struct POLE *p1=(struct POLE *)a,*p2=(struct POLE *)b;
	long long diff;
	if(diff=(long long)p1->x*p2->y-(long long)p2->x*p1->y) return diff<0;
	if(p1->y==0&&(long long)p1->x*p2->x<0) return p2->x-p1->x;
	return (abs(p1->x)+abs(p1->y))-(abs(p2->x)+abs(p2->y));
}
int compar2(const void *a,const void *b){
	struct POLE *p1=(struct POLE *)a,*p2=(struct POLE *)b;
	if(p1->x!=p2->x) return p1->x-p2->x;
	return p1->y-p2->y;
}
int main(){
	struct POLE p[100005];
	struct POLE p_inv[100005];
	int poles,height,n_inv,cases,i;
	for(cases=1;scanf("%d",&poles),poles;cases++){
		for(i=0;i<poles;i++) scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
		qsort(p,poles,sizeof(struct POLE),compar);
		n_inv=0;
		height=p[0].z;
		for(i=1;i<poles;i++){
			if((long long)p[i].x*p[i-1].y!=(long long)p[i-1].x*p[i].y) height=p[i].z;
			else if(p[i].y==0&&(long long)p[i].x*p[i-1].x<0) height=p[i].z;
			else if(p[i].z<=height) p_inv[n_inv++]=p[i];
			else height=p[i].z;
		}
		qsort(p_inv,n_inv,sizeof(struct POLE),compar2);
		printf("Data set %d:\n",cases);
		if(n_inv==0) puts("All the lights are visible.");
		else{
			puts("Some lights are not visible:");
			for(i=0;i<n_inv-1;i++)
				printf("x = %d, y = %d;\n",p_inv[i].x,p_inv[i].y);
			printf("x = %d, y = %d.\n",p_inv[n_inv-1].x,p_inv[n_inv-1].y);
		}
	}
	return 0;
}
