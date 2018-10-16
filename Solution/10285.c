#include<stdio.h>
int R,C;
int snowboard(int height[][105],int x,int y){
	int now=height[x][y];
	int result=1,t;
	if(x>1&&now>height[x-1][y]&&(t=1+snowboard(height,x-1,y))>result) result=t; 
	if(x<R&&now>height[x+1][y]&&(t=1+snowboard(height,x+1,y))>result) result=t;
	if(y>1&&now>height[x][y-1]&&(t=1+snowboard(height,x,y-1))>result) result=t;
	if(y<C&&now>height[x][y+1]&&(t=1+snowboard(height,x,y+1))>result) result=t;
	return result;
}
int main(){
	int N;
	int i,j,longest;
	char name[20];
	int height[105][105],t;
	scanf("%d",&N);
	while(N--){
		scanf("%s%d%d",name,&R,&C);
		for(i=1;i<=R;i++)
			for(j=1;j<=C;j++)
				scanf("%d",&height[i][j]);
		longest=0;
		for(i=1;i<=R;i++)
			for(j=1;j<=C;j++)
				if(longest<(t=snowboard(height,i,j)))
					longest=t;
		printf("%s: %d\n",name,longest);
	}
	return 0;
}
