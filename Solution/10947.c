#include<stdio.h>
#include<string.h>
#define SQAR(x) ((x)*(x))
#define MAX 105
struct ISLAND{
	int x,y,r;
};
int isAvailable(struct ISLAND *is1,struct ISLAND *is2,int limit){
	int x=is1->x-is2->x,y=is1->y-is2->y;
	return x*x+y*y<=SQAR(limit+is1->r+is2->r);
}
int queue[MAX],head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[tail++]=n;
	tail%=MAX;
}
int dequeue(){
	int result=queue[head++];
	head%=MAX;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int K,M,N,i,j,k;
	struct ISLAND island[MAX];
	char GOAL,visit[MAX];
	while(scanf("%d%d",&K,&M)==2){
		scanf("%d%d%d",&island[0].x,&island[0].y,&island[0].r);
		scanf("%d%d%d",&island[1].x,&island[1].y,&island[1].r);
		scanf("%d",&N);
		N+=2;
		for(i=2;i<N;i++)
			scanf("%d%d%d",&island[i].x,&island[i].y,&island[i].r);
		initial();
		enqueue(0);
		memset(visit,0,sizeof(visit));
		GOAL=0;
		while(!is_empty()&&!GOAL){
			int now=dequeue();
			for(i=1;i<N;i++){
				if(visit[i]) continue;
				if(isAvailable(&island[now],&island[i],K*M)){
					if(i==1){
						GOAL=1;
						break;
					}
					visit[i]=1;
					enqueue(i);
				}
			}
		}
		if(GOAL) puts("Larry and Ryan will escape!"); 
		else puts("Larry and Ryan will be eaten to death.");
	}
	return 0;
}
