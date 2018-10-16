#include<stdio.h>
#include<string.h>
void printRoute(int from,int to,int relay[][305]){
	int r=relay[from][to];
	if(r==0) printf(" %d",to);
	else printRoute(from,r,relay),printRoute(r,to,relay);
}
int main(){
	int n,from,to,n_query;
	int dis[305][305];
	int relay[305][305];
	char line[105],*ptr;
	int i,j,k,t,len;
	while(scanf("%d",&n)==1){
		for(i=1;i<=n;i++)
			for(j=1;j<i;j++)
				dis[i][j]=dis[j][i]=n,relay[i][j]=relay[j][i]=0;
		for(i=1;i<=n;i++){
			scanf("%d%*c",&from);
			fgets(line,105,stdin);
			if(*line=='\n') continue;
			for(ptr=line;sscanf(ptr,"%d%*c%n",&to,&len)==1;ptr+=len)
				dis[from][to]=1;
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if((t=dis[i][k]+dis[k][j])<dis[i][j])
						dis[i][j]=t,relay[i][j]=k;
		puts("-----");
		scanf("%d",&n_query);
		while(n_query--){
			scanf("%d%d",&from,&to);
			if(dis[from][to]==n) puts("connection impossible");
			else{
				printf("%d",from);
				printRoute(from,to,relay);
				puts("");
			}
		}
	}
	return 0;
}
