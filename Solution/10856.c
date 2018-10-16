#include<stdio.h>
#include<stdlib.h>
#define maxn 1680
char prime[maxn]={0};
int primen[263];
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int i,j,count=0,X,*ptr,cases=0;
	static int FFactor[2703700]={0};
	for(i=2;i<maxn/2;i++){
		if(prime[i]) continue;
		primen[count++]=i;
		for(j=2;i*j<maxn;j++)
			prime[i*j]=1;
	}
	for(i=maxn/2;i<maxn;i++)
		if(prime[i]==0) primen[count++]=i;
	for(i=1;i<2703700;i++){
		int n=i;
		FFactor[i]=FFactor[i-1];
		for(j=0;primen[j]*primen[j]<=n;j++){
			if(n%primen[j]==0){
				FFactor[i]+=(FFactor[primen[j]]-FFactor[primen[j]-1])+(FFactor[n/primen[j]]-FFactor[n/primen[j]-1]);
				n=1;
				break;
			}
			
		}
		if(n>1) FFactor[i]++;
	}
	while(scanf("%d",&X),X>=0){
		printf("Case %d: ",++cases);
		if(X==0) puts("0!");
		else if((ptr=bsearch(&X,FFactor,2703700,sizeof(int),compar))!=NULL)
			printf("%d!\n",ptr-FFactor);
		else puts("Not possible.");
	}
	return 0;
}
