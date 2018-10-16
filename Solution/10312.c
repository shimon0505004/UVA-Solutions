#include<stdio.h>
int main(){
	long long superCatalan[27],Catalan[27];
	int i,n;
	Catalan[0]=Catalan[1]=1;
	superCatalan[1]=superCatalan[2]=1;
	for(i=2;i<27;i++) Catalan[i]=Catalan[i-1]*(4*i-2)/(i+1);
	for(i=3;i<27;i++) superCatalan[i]=(3*(2*i-3)*superCatalan[i-1]-(i-3)*superCatalan[i-2])/i;
	while(scanf("%d",&n)==1)
		printf("%lld\n",superCatalan[n]-Catalan[n-1]);
	return 0;
}
