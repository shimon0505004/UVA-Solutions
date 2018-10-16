#include<stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
struct POINT{
	int x,y;
};
int main(){
	int N,i;
	struct POINT gallery[105],U,L;
	int cases;
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<N;i++) scanf("%d%d",&gallery[i].x,&gallery[i].y);
		U.x=U.y=1000000000;
		L.x=L.y=-1000000000;
		for(i=0;i<N;i++){
			if(gallery[i].x==gallery[(i+1)%N].x){
				if(gallery[i].y>gallery[(i+1)%N].y) U.x=MIN(U.x,gallery[i].x);
				else L.x=MAX(L.x,gallery[i].x);
			}else{
				if(gallery[i].x>gallery[(i+1)%N].x) L.y=MAX(L.y,gallery[i].y);
				else U.y=MIN(U.y,gallery[i].y);
			}
		}
		printf("Floor #%d\n",cases);
		if(U.x>=L.x&&U.y>=L.y) puts("Surveillance is possible.");
		else puts("Surveillance is impossible.");
		puts("");
	}
	return 0;
}
