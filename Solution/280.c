#include<stdio.h>
#include<string.h>
int main(){
	int n,queries,start,end;
	char map[105][105];
	int ans[105],count,i,j,k;
	while(scanf("%d",&n),n){
		memset(map,0,sizeof(map));
		while(scanf("%d",&start),start)
			while(scanf("%d",&end),end)
				map[start][end]=1;
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=i;j++){
					if(map[i][k]&&map[k][j]) map[i][j]=1;
					if(map[j][k]&&map[k][i]) map[j][i]=1;
				}
		scanf("%d",&queries);
		while(queries--){
			scanf("%d",&start);
			count=0;
			for(i=1;i<=n;i++)
				if(map[start][i]==0)
					ans[count++]=i;
			printf("%d",count);
			for(i=0;i<count;i++)
				printf(" %d",ans[i]);
			puts("");
		}
	}
	return 0;
}
