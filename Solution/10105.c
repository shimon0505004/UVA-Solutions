#include<stdio.h>
int fac(int n)
{
	if(n==1||n==0)
		return 1;
	return n*fac(n-1);
}
int main()
{
	int i,k,n,f,coef;
	while(scanf("%d%d",&n,&k)==2){
		f=fac(n);
		for(i=0;i<k;i++){
			scanf("%d",&coef);
			f/=fac(coef);
		}
		printf("%d\n",f);
	}
	return 0;
}

