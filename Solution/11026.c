#include<stdio.h>
#include<string.h>
int main(){
	int N;
	int i,j;
	int arr[1005];
	long long table[1005],res,M;
	while(scanf("%d%lld",&N,&M),N|M){
		memset(table,0,sizeof(table));
		for(i=1;i<=N;i++) scanf("%d",&arr[i]);
		table[0]=1;
		for(i=1;i<=N;i++)
			for(j=i;j>0;j--)
				table[j]=(table[j]+arr[i]*table[j-1])%M;
		res=0;
		for(i=1;i<=N;i++)
			if(res<table[i]) res=table[i];
		printf("%lld\n",res);
	}
	return 0;
}
