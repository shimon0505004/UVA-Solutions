#include<stdio.h>
#include<string.h>
#define INF 1000000000
#define MAX 130
void print_Path(int from,int to,int relay[][MAX]){
	int r=relay[from][to];
	if(from==to) return;
	if(r){
		print_Path(from,r,relay);
		print_Path(r,to,relay);
	}else printf("-->%d",to);
}
int main(){
	int cases,len,n,i,j,k,t;
	char check[5000],*ptr;
	int map[MAX][MAX],cost[MAX],from,to;
	int relay[MAX][MAX],start;
	scanf("%d",&cases);
	while(cases--){
		scanf(" "),fgets(check,5000,stdin);
		memset(map,0,sizeof(map));
		memset(relay,0,sizeof(relay));
		for(n=0,ptr=check;sscanf(ptr,"%d%n",&map[1][n+1],&len)==1;ptr+=len,n++)
			if(map[1][n+1]<0) map[1][n+1]=INF;
		for(i=2;i<=n;i++)
			for(j=1;j<=n;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]<0) map[i][j]=INF;
			}
		for(i=1;i<=n;i++){
			scanf("%d",&cost[i]);
			for(j=1;j<=n;j++)
				if(map[j][i]!=INF) map[j][i]+=cost[i];
		}
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					if((t=map[i][k]+map[k][j])<map[i][j])
						map[i][j]=t,relay[i][j]=k;
		scanf(" ");
		start=0;
		while(fgets(check,500,stdin)!=NULL&&*check!='\n'){
			if(start) puts("");
			start=1;
			sscanf(check,"%d%d",&from,&to);
			printf("From %d to %d :\nPath: %d",from,to,from);
			print_Path(from,to,relay);
			printf("\nTotal cost : %d\n",map[from][to]-cost[to]);
		}
		if(cases) puts("\n");
	}
	return 0;
}
