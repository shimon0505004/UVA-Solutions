#include<stdio.h>
int main(){
	int cases;
	int chops[5005];
	int sqr[5005],table[5005];
	int K,N,i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&K,&N),K+=8;
		chops[0]=0;
		for(i=1;i<=N;i++){
			scanf("%d",&chops[i]);
			sqr[i]=(chops[i]-chops[i-1])*(chops[i]-chops[i-1]);
			table[i]=0;
		}
		for(i=1;i<=K;i++){
			for(j=N-(K-i)*3-1;j>=2*i;j--)
				table[j]=table[j-2]+sqr[j];
			for(j=2*i+1;j<N-(K-i)*3;j++)
				if(table[j]>table[j-1]) table[j]=table[j-1];
			table[N-(K-i)*3]=table[N-(K-i)*3-1];
		}
		printf("%d\n",table[N]);
	}
	return 0;
}
