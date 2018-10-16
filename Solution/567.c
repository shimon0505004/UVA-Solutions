#include<stdio.h>
#define INF 30
int main(){
	int map[30][30];
	int cases,i,j,k,adjs,adj,t,R,from,to;
	for(cases=1;scanf(" "),!feof(stdin);cases++){
		for(i=1;i<=20;i++)
			for(j=1;j<=20;j++)
				map[i][j]=INF;
		for(i=1;i<20;i++){
			scanf("%d",&adjs);
			while(adjs--){
				scanf("%d",&adj);
				map[i][adj]=map[adj][i]=1;
			}
		}
		for(k=1;k<=20;k++)
			for(i=1;i<=20;i++)
				for(j=1;j<i;j++)
					if((t=map[i][k]+map[k][j])<map[i][j])
						map[i][j]=map[j][i]=t;
		scanf("%d",&R);
		printf("Test Set #%d\n",cases);
		while(R--){
			scanf("%d%d",&from,&to);
			printf("%2d to %2d: %d\n",from,to,map[from][to]);
		}
		puts("");
	}
	return 0;
}
