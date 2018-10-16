#include<stdio.h>
#include<string.h>
#include<strings.h>
#include<stdlib.h>
typedef struct TEAM{
	char name[20];
	int points,games,scored,suffered,goaldiff;
}Team;
int compar1(const void *a,const void *b){
	return strcasecmp(((Team *)a)->name,((Team *)b)->name);
}
int compar2(const void *a,const void *b){
	Team *t1=(Team *)a,*t2=(Team *)b;
	if(t1->points!=t2->points) return t2->points-t1->points;
	if(t1->goaldiff!=t2->goaldiff) return t2->goaldiff-t1->goaldiff;
	if(t1->scored!=t2->scored) return t2->scored-t1->scored;
	return strcasecmp(t1->name,t2->name);
}
int compar3(Team *t1,Team *t2){
	if(t1->points!=t2->points) return 1;
	if(t1->goaldiff!=t2->goaldiff) return 1;
	if(t1->scored!=t2->scored) return 1;
	return 0;
}
int search(Team t[],char name[],int T){
	int Ubound=T,Lbound=0;
	int now=T/2,temp;
	while(temp=strcasecmp(name,t[now].name)){
		if(temp>0) Lbound=now;
		else Ubound=now;
		now=(Ubound+Lbound)/2;
	}
	return now;
}
int main(){
	int T,G,i,start=0;
	Team t[30];
	char n1[20],n2[20];
	int s1,s2,t1,t2,rank;
	while(scanf("%d%d",&T,&G),T){
		if(start) puts("");
		start=1;
		for(i=0;i<T;i++){
			scanf("%s",t[i].name);
			t[i].points=t[i].games=t[i].scored=t[i].suffered=t[i].goaldiff=0;
		}
		qsort(t,T,sizeof(Team),compar1);
		while(G--){
			scanf("%s%d %*c %d%s",n1,&s1,&s2,n2);
			t1=search(t,n1,T),t2=search(t,n2,T);
			t[t1].games++,t[t2].games++;
			t[t1].scored+=s1,t[t2].scored+=s2;
			t[t1].suffered+=s2,t[t2].suffered+=s1;
			t[t1].goaldiff+=s1-s2,t[t2].goaldiff+=s2-s1;
			if(s1>s2) t[t1].points+=3;
			else if(s2>s1) t[t2].points+=3;
			else t[t1].points++,t[t2].points++;
		}
		qsort(t,T,sizeof(Team),compar2);
		for(i=0,rank=1;i<T;i++,rank++){
			if(i){
				if(compar3(&(t[i]),&(t[i-1]))) printf("%2d.",rank);
				else printf("   ");
			}else
				printf("%2d.",rank);
			printf("%16s%4d%4d%4d%4d%4d",t[i].name,t[i].points,t[i].games,t[i].scored,t[i].suffered,t[i].goaldiff);
			if(t[i].games)
				printf("%7.2lf\n",(double)t[i].points/(t[i].games*3)*100);
			else puts("    N/A");
		}
	}
	return 0;
}
