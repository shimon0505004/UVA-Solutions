#include<stdio.h>
#include<string.h>
#define MAX 255
int main(){
	int n,i,j,l;
	int node[MAX],subsum[MAX];
	int OBST[MAX][MAX],root[MAX][MAX];
	while(scanf("%d",&n)==1){
		subsum[0]=0;
		for(i=1;i<=n;i++){
			scanf("%d",&node[i]);
			subsum[i]=subsum[i-1]+node[i];
		}
		memset(OBST,0,sizeof(OBST));
		for(i=1;i<=n;i++) OBST[i][i]=node[i],root[i][i]=i;
		for(l=2;l<=n;l++){
			for(i=1;i<=n-l+1;i++){
				int head=i,tail=i+l-1;
				int min=2147483647,minj;
				for(j=root[head][tail-1];j<=root[head+1][tail];j++){
					int now=OBST[head][j-1]+OBST[j+1][tail];
					if(now<min) min=now,minj=j;
				}
				OBST[head][tail]=min+subsum[tail]-subsum[head-1];
				root[head][tail]=minj;
			}
		}
		printf("%d\n",OBST[1][n]-subsum[n]);
	}
	return 0;
}
