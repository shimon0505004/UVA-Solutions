#include<stdio.h>
#define maxn 2000005
int main(){
	int i,j;
	int n,m,cases;
	int SODF[maxn]={0};
	for(i=2;i<maxn;i++){
		if(SODF[i]) continue;
		for(j=1;i*j<maxn;j++){
			if(SODF[i*j]==0) SODF[i*j]=j*(i-1);
			else SODF[i*j]=SODF[i*j]/i*(i-1);
		}
	}
	for(i=3;i<maxn;i++)
		SODF[i]=SODF[i-1]+SODF[SODF[i]]-SODF[SODF[i]-1]+1;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&m,&n);
		printf("%d\n",SODF[n]-SODF[m-1]);
	}
	return 0;
}
