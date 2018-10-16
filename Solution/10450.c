#include<stdio.h>
int main()
{
	long long noise[52][2];
	int i,n,cases;
	noise[1][0]=noise[1][1]=1;
	for(i=2;i<51;i++){
		noise[i][0]=noise[i-1][0]+noise[i-1][1];
		noise[i][1]=noise[i-1][0];
	}
	noise[51][0]=noise[50][0]+noise[50][1];
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d",&n);
		printf("Scenario #%d:\n%lld\n\n",i+1,noise[n+1][0]);
	}
	return 0;
}
