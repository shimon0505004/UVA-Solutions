#include<stdio.h>
struct FACTORIAL{
	int index[25];
};
int main(){
	int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int i,j,N,D;
	struct FACTORIAL F[101]={0},test;
	long long result;
	for(i=2;i<=100;i++){
		int n=i;
		F[i]=F[i-1];
		for(j=0;n>1;j++)
			while(n%prime[j]==0) F[i].index[j]++,n/=prime[j];
	}
	while(scanf("%d%d",&N,&D),N||D){
		if(D<0) D=-D;
		if(N==0||N==1){
			if(D==1) puts("1");
			else puts("0");
			continue;
		}
		test=F[N];
		for(i=0;i<25;i++)
			while(D%prime[i]==0) D/=prime[i],test.index[i]--;
		if(D>1) puts("0");
		else{
			result=1;
			for(i=0;i<25;i++)
				if(test.index[i]>=0)
					result*=test.index[i]+1;
				else{
					result=0;
					break;
				}
			printf("%lld\n",result);
		}
	}
	return 0;
}
