#include<stdio.h>
#include<stdlib.h>
struct POINT{
	int x,y;
};
int main(){
	int cases,N,T;
	struct POINT from,to;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&T,&N);
		while(T--){
			scanf("%d%d%d%d",&from.x,&from.y,&to.x,&to.y);
			if(from.x>N||from.y>N||to.x>N||to.y>N) puts("no move");
			else if((from.x+from.y+to.x+to.y)%2!=0) puts("no move");
			else{
				if(from.x==to.x&&from.y==to.y) puts("0");
				else if(from.x+from.y==to.x+to.y) puts("1");
				else if(from.x-from.y==to.x-to.y) puts("1");
				else puts("2");
			}
		}
	}
	return 0;
}
