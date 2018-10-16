#include<stdio.h>
int main(){
	unsigned long long calltimes[61][61]={0};
	int i,j,k,n,back;
	int cases=1;
	for(i=0;i<=1;i++)
		for(j=0;j<61;j++)
			calltimes[i][j]=1;
	for(i=2;i<61;i++)
		for(j=1;j<61;j++){
			for(k=1;k<=j;k++)
				if(i-k<=1)
					calltimes[i][j]++;
				else
					calltimes[i][j]+=calltimes[i-k][j];
			calltimes[i][j]++;
		}
	while(scanf("%d%d",&n,&back),n<=60){
		printf("Case %d: ",cases++);
		if(n<=1||back<1){
			puts("1");
			continue;
		}
		printf("%llu\n",calltimes[n][back]);
	}
	return 0;
}
