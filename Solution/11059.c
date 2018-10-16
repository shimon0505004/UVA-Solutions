#include<stdio.h>
long long max_product(long long s[],int len){
	long long product=1,left=1,right=1;
	int i;
	if(len==0) return 0;
	if(len==1&&s[0]<0) return 0;
	for(i=0;i<len;i++) product*=s[i];
	if(product>0) return product;
	for(i=0;left*=s[i],s[i]>0;i++);
	for(i=len-1;right*=s[i],s[i]>0;i--);
	if(left>right) return product/left;
	else return product/right;
}
int main(){
	int N,cases,i,zeros[20],z;
	long long s[20],max;
	for(cases=1;scanf("%d",&N)==1;cases++){
		z=0;
		zeros[0]=-1;
		for(i=0;i<N;i++){
			scanf("%lld",&s[i]);
			if(s[i]==0) zeros[++z]=i;
		}
		zeros[++z]=N;
		printf("Case #%d: The maximum product is ",cases);
		max=0;
		for(i=1;i<=z;i++){
			long long m;
			if(max<(m=max_product(s+zeros[i-1]+1,zeros[i]-zeros[i-1]-1))) max=m;
		}
		printf("%lld.\n\n",max);
	}
	return 0;
}
