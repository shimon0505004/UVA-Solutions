#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)b)-*((int *)a);
}
int main(){
	int n,i;
	int array[1005],total,change,average,mod;
	while(scanf("%d",&n),n){
		total=0;
		for(i=0;i<n;i++){
			int a,b;
			scanf("%d%*c%d",&a,&b);
			array[i]=a*100+b;
			total+=array[i];
		}
		qsort(array,n,sizeof(int),compar);
		change=0;
		average=total/n;
		mod=total-average*n;
		for(i=0;i<mod;i++) if(array[i]<average+1) change+=average+1-array[i];
		for(i=mod;i<n;i++) if(array[i]<average) change+=average-array[i];
		printf("$%d.%.2d\n",change/100,change%100);
	}
	return 0;
}
