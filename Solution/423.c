#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int N;
	int map[105][105];
	int i,j,k,t,max;
	char cost[15];
	scanf("%d",&N);
	memset(map,0,sizeof(map));
	for(i=0;i<N;i++){
		for(j=0;j<i;j++){
			scanf("%s",cost);
			if(*cost=='x') map[i][j]=map[j][i]=-1;
			else map[i][j]=map[j][i]=atoi(cost);
		}
	}
	for(k=0;k<N;k++)
		for(i=0;i<N;i++)
			for(j=0;j<i;j++)
				if(map[i][k]==-1||map[k][j]==-1) continue;
				else if(map[i][j]==-1) map[i][j]=map[j][i]=map[i][k]+map[k][j];
				else if((t=map[i][k]+map[k][j])<map[i][j])
					map[i][j]=map[j][i]=t;
	max=0;
	for(i=0;i<N;i++)
		if(max<map[0][i]) max=map[0][i];
	printf("%d\n",max);
	return 0;
}
