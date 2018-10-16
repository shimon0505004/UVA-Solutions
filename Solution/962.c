#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int cube[1005];
	int i,j,n,range;
	int count=0,sumofcube[510005];
	int ans[510005],count2;
	for(i=1;i<1005;i++)
		cube[i]=i*i*i;
	for(i=1;i<1005;i++)
		for(j=i;j<1005;j++)
			sumofcube[count++]=cube[i]+cube[j];
	qsort(sumofcube,count,sizeof(int),compar);
	count2=0;
	for(i=0;i<count-1;i++)
		if(sumofcube[i]==sumofcube[i+1]){
			ans[count2++]=sumofcube[i];
			while(sumofcube[i+1]==sumofcube[i]) i++;
			i--;
		}
	while(scanf("%d%d",&n,&range)==2){
		count=0;
		for(i=0;ans[i]<n;i++);
		if(ans[i]>n+range) puts("None");
		else
			for(;ans[i]<=n+range;i++)
				printf("%d\n",ans[i]);
	}
	return 0;
}
