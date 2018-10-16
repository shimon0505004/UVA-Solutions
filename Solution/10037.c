#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int cases,n,i,total;
	int person[1005];
	int subsum[1005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&person[i]);
		subsum[0]=person[0];
		for(i=1;i<n;i++) subsum[i]=subsum[i-1]+person[i];
		qsort(person,n,sizeof(int),compar);
		if(n==0) puts("0");
		else if(n==1) printf("%d\n%d\n",person[0],person[0]);
		else if(n==2) printf("%d\n%d %d\n",person[1],person[0],person[1]);
		else{
			total=0;
			for(i=n-1;person[i-1]>2*person[1]-person[0];i-=2)
				total+=person[1]*2+person[0]+person[i];
			total+=subsum[i]+(i-2)*person[0];
			printf("%d\n",total);
			for(i=n-1;person[i-1]>2*person[1]-person[0];i-=2){
				printf("%d %d\n",person[0],person[1]);
				printf("%d\n",person[0]);
				printf("%d %d\n",person[i-1],person[i]);
				printf("%d\n",person[1]);
			}
			for(;i>1;i--){
				printf("%d %d\n",person[0],person[i]);
				printf("%d\n",person[0]);
			}
			printf("%d %d\n",person[0],person[1]);
		}
		if(cases) puts("");
	}
	return 0;
}
