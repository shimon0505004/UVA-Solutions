#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char used[45];
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
char is_answer(int a[],int b[],int n,int n_b){
	int i,j,k;
	for(i=3;i<n;i++){
		for(j=0;j<n_b&&used[j]==1;j++);
		if(j==n_b) return 0;
		a[i]=b[j]-a[0];
		used[j]=1;
		for(j=1;j<i;j++){
			for(k=0;k<n_b&&a[i]+a[j]>=b[k];k++) if(used[k]==0&&a[i]+a[j]==b[k]) break;
			if(used[k]==0&&a[i]+a[j]==b[k]) used[k]=1;
			else return 0;
		}
	}
	return 1;
}
int main(){
	int n,n_b,sum;
	int i,j;
	int a[10],b[45];
	while(scanf("%d",&n)==1){
		n_b=n*(n-1)/2;
		sum=0;
		for(i=0;i<n_b;i++) scanf("%d",&b[i]),sum+=b[i];
		qsort(b,n_b,sizeof(int),compar);
		if(sum%(n-1)!=0){
			puts("Impossible");
			continue;
		}
		for(i=2;i<n_b;i++){
			memset(used,0,sizeof(used));
			if((b[0]+b[1]+b[i])%2==0){
				a[0]=(b[0]+b[1]-b[i])/2;
				a[1]=(b[0]-b[1]+b[i])/2;
				a[2]=(-b[0]+b[1]+b[i])/2;
				used[0]=used[1]=used[i]=1;
				if(is_answer(a,b,n,n_b)){
					printf("%d",a[0]);
					for(j=1;j<n;j++) printf(" %d",a[j]);
					puts("");
					break;
				}
			}
		}
		if(i==n_b) puts("Impossible");
	}
	return 0;
}
