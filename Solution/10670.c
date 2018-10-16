#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
struct AGENCY{
	char name[20];
	int cost;
};
int compar(const void *a,const void *b){
	struct AGENCY *ag1=(struct AGENCY *)a,*ag2=(struct AGENCY *)b;
	if(ag1->cost!=ag2->cost) return ag1->cost-ag2->cost;
	return strcmp(ag1->name,ag2->name);
}
int main(){
	int T,N,M,L,A,B,i,cases;
	struct AGENCY ag[105];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d%d",&N,&M,&L);
		for(i=0;i<L;i++){
			int n=N,m=M,min=2147483647;
			scanf(" %[^:]%*c%d%*c%d",ag[i].name,&A,&B);
			ag[i].cost=0;
			while(n/2>=m&&(n-m)*A>B){
				min=MIN(min,ag[i].cost+(n-m)*A);
				ag[i].cost+=B;
				n/=2;
			}
			ag[i].cost+=(n-m)*A;
			ag[i].cost=MIN(ag[i].cost,min);
		}
		qsort(ag,L,sizeof(struct AGENCY),compar);
		printf("Case %d\n",cases);
		for(i=0;i<L;i++)
			printf("%s %d\n",ag[i].name,ag[i].cost);
	}
	return 0;
}
