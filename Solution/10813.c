#include<stdio.h>
struct pos{
	int x,y;
};
int main(){
	int line[12];
	int n,i,j,temp,after;
	struct pos P[80];
	scanf("%d",&n);
	while(n--){
		for(i=0;i<10;i++) line[i]=5;
		line[2]=line[7]=line[10]=line[11]=4;
		for(i=0;i<80;i++) P[i].x=P[i].y=-1;
		for(i=0;i<5;i++)
			for(j=0;j<5;j++){
				if(i==2&&j==2) continue;
				scanf("%d",&temp);
				P[temp].x=i,P[temp].y=j;
			}
		after=0;
		for(i=0;i<75;i++){
			int x,y;
			scanf("%d",&temp);
			if(after==0){
				x=P[temp].x,y=P[temp].y;
				if(x==-1&&y==-1) continue;
				if(--line[x]==0) after=i+1;
				if(--line[y+5]==0) after=i+1;
				if(x==y) if(--line[10]==0) after=i+1;
				if(x+y==4) if(--line[11]==0) after=i+1;
			}
		}
		printf("BINGO after %d numbers announced\n",after);
	}
	return 0;
}
