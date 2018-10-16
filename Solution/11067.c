#include<stdio.h>
#include<string.h>
int main(){
	int w,h,n,i,j;
	int map[105][105],ans;
	char wolf[105][105];
	while(scanf("%d%d",&w,&h),w|h){
		memset(map,0,sizeof(map));
		memset(wolf,0,sizeof(wolf));
		scanf("%d",&n);
		while(n--){
			int x,y;
			scanf("%d%d",&x,&y);
			wolf[y][x]=1;
		}
		for(i=0;i<=w&&wolf[0][i]==0;i++) map[0][i]=1;
		for(i=0;i<=h&&wolf[i][0]==0;i++) map[i][0]=1;
		for(i=1;i<=h;i++)
			for(j=1;j<=w;j++)
				if(wolf[i][j]==0) map[i][j]=map[i-1][j]+map[i][j-1];
		ans=map[h][w];
		if(ans>1) printf("There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n",ans);
		else if(ans==1) puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
		else puts("There is no path.");
	}
	return 0;
}
