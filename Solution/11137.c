#include<stdio.h>
int cubic[22]={0};
int main(){
	int i,j,n;
	long long cubrency[10000]={0};
	for(i=1;i<22;i++) cubic[i]=i*i*i;
	cubrency[0]=1;
	for(i=1;i<22;i++)
		for(j=cubic[i];j<10000;j++)
			cubrency[j]+=cubrency[j-cubic[i]];
	while(scanf("%d",&n)==1) printf("%lld\n",cubrency[n]);
	return 0;
}
