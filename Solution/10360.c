#include<stdio.h>
#include<string.h>
#define SIZE 1025
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int cases,x,y,size;
	int rat[1030][1030],d,n;
	int i,j;
	int a_x,a_y,a_size;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&d,&n);
		memset(rat,0,sizeof(rat));
		while(n--){
			scanf("%d%d%d",&x,&y,&size);
			rat[x+1][y+1]=size;
		}
		for(i=1;i<=SIZE;i++)
			for(j=1;j<=SIZE;j++)
				rat[i][j]+=rat[i][j-1];
		for(i=1;i<=SIZE;i++)
			for(j=1;j<=SIZE;j++)
				rat[i][j]+=rat[i-1][j];
		a_size=0;
		for(x=1;x<=SIZE-d;x++)
			for(y=1;y<=SIZE-d;y++){
				int l=MAX(x-d,1),r=x+d,u=MAX(y-d,1),b=y+d;
				size=rat[r][b]-rat[l-1][b]-rat[r][u-1]+rat[l-1][u-1];
				if(size>a_size) a_x=x,a_y=y,a_size=size;
			}
		printf("%d %d %d\n",a_x-1,a_y-1,a_size);
	}
	return 0;
}
