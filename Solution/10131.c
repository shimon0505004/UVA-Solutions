#include<stdio.h>
#include<stdlib.h>
typedef struct ELP{
	int IQ,W;
	int NO;
}Elp;
Elp elp[1005];
int LIS[1005]={0};
int parent[1005];
int compar(const void *a,const void *b){
	Elp *e1=(Elp *)a,*e2=(Elp *)b;
	if(e1->IQ!=e2->IQ) return e2->IQ-e1->IQ;
	return e2->W-e1->W;
}
void printAns(int n){
	if(LIS[n]>1) printAns(parent[n]);
	printf("%d\n",elp[n].NO);
}
int main(){
	int count,i,j;
	int max,maxi;
	for(count=0;scanf("%d%d",&elp[count].W,&elp[count].IQ)==2;count++) elp[count].NO=count+1;
	qsort(elp,count,sizeof(Elp),compar);
	for(i=0;i<count;i++){
		LIS[i]=1;
		for(j=0;j<i;j++)
			if(elp[i].W>elp[j].W&&LIS[j]+1>LIS[i])
				LIS[i]=LIS[j]+1,parent[i]=j;
	}
	max=0;
	for(i=0;i<count;i++)
		if(LIS[i]>max) max=LIS[i],maxi=i;
	printf("%d\n",max);
	printAns(maxi);
	return 0;
}
