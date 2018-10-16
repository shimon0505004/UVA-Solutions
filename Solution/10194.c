#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct TEAM{
	char name[40];
	int points,games,wins,ties,losses,diff,scored,against;
}team;
int compar(const void *b,const void *a){
	team *t1=(team *)a,*t2=(team *)b;
	int i,len=strlen(t1->name);
	if(t1->points!=t2->points) return t1->points-t2->points;
	if(t1->wins!=t2->wins) return t1->wins-t2->wins;
	if(t1->diff!=t2->diff) return t1->diff-t2->diff;
	if(t1->scored!=t2->scored) return t1->scored-t2->scored;
	if(t1->games!=t2->games) return t2->games-t1->games;
	for(i=0;i<len;i++){
		if(tolower(t1->name[i])<tolower(t2->name[i]))
			return 1;
		else if(tolower(t1->name[i])>tolower(t2->name[i]))
			return -1;
	}
	return 1;
}
int main()
{
	int N,T,G,i,j,t1,t2;
	char tournament[105];
	char input[100];
	char team1[40],team2[40];
	team Teams[35];
	scanf("%d ",&N);
	while(N--){
		fgets(tournament,105,stdin);
		scanf("%d ",&T);
		for(i=0;i<T;i++){
			fgets(Teams[i].name,40,stdin);
			Teams[i].name[strlen(Teams[i].name)-1]=0;
			Teams[i].points=Teams[i].games=Teams[i].wins=Teams[i].ties=Teams[i].losses=Teams[i].diff=Teams[i].scored=Teams[i].against=0;
		}
		scanf("%d ",&G);
		for(i=0;i<G;i++){
			fgets(input,100,stdin);
			sscanf(input,"%[^#]%*c%d%*c%d%*c%[^\n]",team1,&t1,&t2,team2);
#ifdef DEBUG
			printf("team1: %s,score: %d\n",team1,t1);
			printf("team2: %s,score: %d\n",team2,t2);
#endif
			for(j=0;j<T;j++)
				if(!strcmp(team1,Teams[j].name)){
					Teams[j].games++;
					Teams[j].diff+=t1-t2;
					Teams[j].scored+=t1;
					Teams[j].against+=t2;
					if(t1>t2){
						Teams[j].points+=3;
						Teams[j].wins++;
					}else if(t1==t2){
						Teams[j].points+=1;
						Teams[j].ties++;
					}else
						Teams[j].losses++;
				}else if(!strcmp(team2,Teams[j].name)){
					Teams[j].games++;
					Teams[j].diff+=t2-t1;
					Teams[j].scored+=t2;
					Teams[j].against+=t1;
					if(t2>t1){
						Teams[j].points+=3;
						Teams[j].wins++;
					}else if(t1==t2){
						Teams[j].points+=1;
						Teams[j].ties++;
					}else
						Teams[j].losses++;
				}
		}
		qsort(Teams,T,sizeof(team),compar);
		printf(tournament);
		for(i=0;i<T;i++){
			team *t=&Teams[i];
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,t->name,t->points,t->games,t->wins,t->ties,t->losses,t->diff,t->scored,t->against);
		}
		if(N) puts("");
	}
	return 0;
}
