#include<stdio.h>
#define MAXN 3005
int sum_digits(int n){
	int result=0;
	while(n!=0) result+=n%10,n/=10;
	return result;
}
int main()
{
	int i,j,m,n,count,chain,max,maxi,cases=1;
	int next[MAXN];
	int digits[MAXN];
	int length[MAXN];
	for(i=1;i<3001;i++) digits[i]=sum_digits(i);
	for(i=1;i<MAXN;i++){
		next[i]=0;
		for(j=1;j*j<i;j++)
			if(i%j==0) next[i]+=digits[j]+digits[i/j];
		if(j*j==i) next[i]+=digits[j];
	}
	for(i=1;i<MAXN;i++){
		for(count=1,chain=i;next[chain]!=chain;count++,chain=next[chain]);
		length[i]=count;
	}
	while(scanf("%d%d",&m,&n)==2){
		int temp;
		printf("Input%d: %d %d\n",cases,m,n);
		if(m>n) temp=m,m=n,n=temp;
		max=0;
		for(i=m;i<=n;i++)
			if(max<length[i]) max=length[i],maxi=i;
		printf("Output%d:",cases);
		for(i=0;i<max;i++){
			printf(" %d",maxi);
			maxi=next[maxi];
		}
		cases++;
		puts("");
	}
	return 0;
}
