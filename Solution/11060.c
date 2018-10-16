#include<stdio.h>
#include<string.h>
int findbeverage(char beverage[][60],char find[]){
	int n;
	for(n=0;strcmp(beverage[n],find)!=0;n++);
	return n;
}
int main(){
	char beverage[105][60];
	char table[105][105],deg[105];
	char wine1[60],wine2[60];
	char visit[105];
	int N,i,M,w1,w2,min,mini;
	int cases;
	for(cases=1;scanf("%d",&N)==1;cases++){
		memset(table,0,sizeof(table));
		memset(visit,0,sizeof(visit));
		memset(deg,0,sizeof(deg));
		for(i=0;i<N;i++) scanf("%s",beverage[i]);
		scanf("%d",&M);
		for(i=0;i<M;i++){
			scanf("%s%s",wine1,wine2);
			w1=findbeverage(beverage,wine1);
			w2=findbeverage(beverage,wine2);
			if(table[w1][w2]==0) deg[w2]++;
			table[w1][w2]=1;
		}
		printf("Case #%d: Dilbert should drink beverages in this order:",cases);
		for(;;){
			min=N,mini;
			for(i=0;i<N;i++)
				if(visit[i]==0&&deg[i]==0){
					mini=i;
					break;
				}
			if(i==N) break;
			visit[mini]=1;
			printf(" %s",beverage[mini]);
			for(i=0;i<N;i++) if(table[mini][i]) deg[i]--;
		}
		puts(".\n");
	}
	return 0;
}
