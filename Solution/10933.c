#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TEAM{
	char name[25];
	int winsets,scored,winmatches;
}team;
int compar(const void *b,const void *a){
	team *t1=(team *)a,*t2=(team *)b;
	if(t1->winmatches!=t2->winmatches) return t1->winmatches-t2->winmatches;
	if(t1->winsets!=t2->winsets) return t1->winsets-t2->winsets;
	if(t1->scored!=t2->scored) return t1->scored-t2->scored;
	return strcmp(t2->name,t1->name);
}
int compar1(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int main()
{
	int N,T,G,i,j,s1,s2,t1,t2,tmp1,tmp2;
	char score[1000],*ptr;
	char team1[25],team2[25];
	team Teams[1005];
	while(scanf("%d ",&T),T){
		for(i=0;i<T;i++){
			fgets(Teams[i].name,25,stdin);
			Teams[i].name[strlen(Teams[i].name)-1]=0;
			Teams[i].winsets=Teams[i].scored=Teams[i].winmatches=0;
		}
		qsort(Teams,T,sizeof(team),compar1);
		scanf("%d ",&G);
		for(i=0;i<G;i++){
			int t,prev,Ub,Lb,tmp;
			scanf("%[^-]%*c%[^:]%*c",team1,team2);
			Ub=T,Lb=0;
			t1=(Ub+Lb)/2;
			while(t=strcmp(team1,Teams[t1].name)){
				if(t>0) Lb=(Ub+Lb)/2;
				else Ub=(Ub+Lb)/2;
				t1=(Ub+Lb)/2;
			}
			Ub=T,Lb=0;
			t2=(Ub+Lb)/2;
			while(t=strcmp(team2,Teams[t2].name)){
				if(t>0) Lb=(Ub+Lb)/2;
				else Ub=(Ub+Lb)/2;
				t2=(Ub+Lb)/2;
			}
			for(j=0;j<T;j++){
				if(!strcmp(team1,Teams[j].name)) t1=j;
				else if(!strcmp(team2,Teams[j].name)) t2=j;
				if(t1>0&&t2>0) break;
			}
			tmp1=tmp2=0;
			fgets(score,1000,stdin);
			for(ptr=score;sscanf(ptr,"%d%*c%d%n",&s1,&s2,&tmp)==2;ptr+=tmp){
				Teams[t1].scored+=s1;
				Teams[t2].scored+=s2;
				if(s1>s2) tmp1++,tmp2--;
				else tmp2++,tmp1--;
			}
			if(tmp1>tmp2) Teams[t1].winmatches++;
			else Teams[t2].winmatches++;
			Teams[t1].winsets+=tmp1;
			Teams[t2].winsets+=tmp2;
		}
		qsort(Teams,T,sizeof(team),compar);
		for(i=0;i<T;i++)
			printf("%-20s%5d%5d%10d\n",Teams[i].name,Teams[i].winmatches,Teams[i].winsets,Teams[i].scored);
		puts("");
	}
	return 0;
}
