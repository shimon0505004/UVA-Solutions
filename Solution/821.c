#include<stdio.h>
#include<string.h>
int main(){
	int cases;
	int i,j,k,count,from,to;
	int dis[105][105];
	int list[105],sum;
	char used[105];
	for(cases=1;;cases++){
		memset(used,0,sizeof(used));
		for(i=0;i<105;i++)
			for(j=0;j<105;j++)
				dis[i][j]=100000;
		count=0;
		while(scanf("%d%d",&from,&to),from|to){
			if(used[from]==0) list[count++]=from;
			if(used[to]==0) list[count++]=to;
			used[from]=used[to]=1;
			dis[from][to]=1;
		}
		if(count==0) break;
		for(k=0;k<count;k++)
			for(i=0;i<count;i++)
				for(j=0;j<count;j++){
					int a=list[i],b=list[j],c=list[k];
					if(dis[a][c]+dis[c][b]<dis[a][b])
						dis[a][b]=dis[a][c]+dis[c][b];
				}
		sum=0;
		for(i=0;i<count;i++)
			for(j=0;j<i;j++){
				int a=list[i],b=list[j];
				sum+=dis[a][b]+dis[b][a];
			}
		printf("Case %d: average length between pages = %.3lf clicks\n",cases,(double)sum/count/(count-1));
	}
	return 0;
}
