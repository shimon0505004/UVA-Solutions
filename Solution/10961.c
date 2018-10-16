#include<stdio.h>
#include<stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
struct POINT{
	int x,y;
};
int dis(struct POINT *p1,struct POINT *p2){
	return abs(p1->x-p2->x)+abs(p1->y-p2->y);
}
void move(struct POINT *p1,struct POINT *p2,int len_move){
	if(p1->x==p2->x){
		if(p2->y>p1->y) p1->y+=len_move;
		else p1->y-=len_move;
	}else{
		if(p2->x>p1->x) p1->x+=len_move;
		else p1->x-=len_move;
	}
}
char safe(struct POINT Villagers[],struct POINT Leporello[],int n_L,int n_V){
	struct POINT L,V;
	int now_L,now_V,len_move;
	L=Leporello[0],V=Villagers[0];
	now_L=now_V=0;
	while(now_V<n_V&&now_L<n_L){
		struct POINT nextL=Leporello[now_L+1],nextV=Villagers[now_V+1];
		if(dis(&L,&V)==0) return 0;
		len_move=MIN(dis(&L,&nextL),dis(&V,&nextV));
		if((L.x-nextL.x)*(V.y-nextV.y)){
			struct POINT meet;
			meet.x=V.x,meet.y=L.y;
			if((meet.x-L.x)*(meet.x-nextL.x)<0&&(meet.y-V.y)*(meet.y-nextV.y)<0)
				if(abs(meet.x-L.x)==abs(meet.y-V.y))
					return 0;
		}else if((L.y-nextL.y)*(V.x-nextV.x)){
			struct POINT meet;
			meet.y=V.y,meet.x=L.x;
			if((meet.y-L.y)*(meet.y-nextL.y)<0&&(meet.x-V.x)*(meet.x-nextV.x)<0)
				if(abs(meet.y-L.y)==abs(meet.x-V.x))
					return 0;
		}else if((L.x-nextL.x)*(V.x-nextV.x)&&L.y==V.y){
			if((nextL.x-L.x)*(nextV.x-V.x)<0&&(nextL.x-L.x)*(V.x-L.x)>0)
				if(len_move*2>abs(L.x-V.x)) return 0;
		}else if((L.y-nextL.y)*(V.y-nextV.y)&&L.x==V.x){
			if((nextL.y-L.y)*(nextV.y-V.y)<0&&(nextL.y-L.y)*(V.y-L.y)>0)
				if(len_move*2>abs(L.y-V.y)) return 0;
		}
		move(&L,&nextL,len_move);
		move(&V,&nextV,len_move);
		if(dis(&L,&nextL)==0) now_L++;
		if(dis(&V,&nextV)==0) now_V++;
	}
	return 1;
}
int main(){
	int cases,i;
	struct POINT Leporello[105],Villagers[105];
	int n_L,n_V;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&Villagers[0].x,&Villagers[0].y);
		scanf("%d%d",&Leporello[0].x,&Leporello[0].y);
		scanf("%d",&n_L);
		for(i=1;i<=n_L;i++) scanf("%d%d",&Leporello[i].x,&Leporello[i].y);
		scanf("%d",&n_V);
		for(i=1;i<=n_V;i++) scanf("%d%d",&Villagers[i].x,&Villagers[i].y);
		if(safe(Villagers,Leporello,n_L,n_V)) puts("Yes");
		else puts("No");
		if(cases) puts("");
	}
	return 0;
}
