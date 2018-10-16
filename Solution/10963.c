#include<stdio.h>
int main(){
	int cases;
	int W,diff,x,y;
	char close;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&W);
		close=1;
		scanf("%d%d",&x,&y);
		diff=x-y;
		while(--W){
			scanf("%d%d",&x,&y);
			if(x-y!=diff) close=0;
		}
		if(close) puts("yes");
		else puts("no");
		if(cases) puts("");
	}
	return 0;
}
