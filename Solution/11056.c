#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
struct F1{
	char name[25];
	int ms;
};
int compar(const void *a,const void *b){
	struct F1 *f1=(struct F1 *)a,*f2=(struct F1 *)b;
	if(f1->ms!=f2->ms) return f1->ms-f2->ms;
	return strcasecmp(f1->name,f2->name);
}
int main(){
	int N,row,i;
	struct F1 f1[105];
	while(scanf("%d",&N)==1){
		int m,s,ms;
		for(i=0;i<N;i++)
			scanf("%s %*c%d%*s%d%*s%d%*s",f1[i].name,&m,&s,&ms),f1[i].ms=m*60*1000+s*1000+ms;
		qsort(f1,N,sizeof(struct F1),compar);
		for(i=0,row=1;i<N;i++){
			if(i%2==0) printf("Row %d\n",row++);
			puts(f1[i].name);
		}
		puts("");
	}
	return 0;
}
