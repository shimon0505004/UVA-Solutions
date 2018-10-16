#include<stdio.h>
#define maxn 10050
int fac(int,int);
int main()
{
	int i,j,m,n=1,cases,times,temp,min;
	int factorize[10]={0};
	char isprime[maxn]={0};
	int count=0,pm,pn;
	isprime[0]=isprime[1]=1;
	for(i=2;i<maxn/2;i++){
		if(isprime[i]) continue;
		for(j=2;i*j<maxn;j++)
			isprime[i*j]=1;
	}
	n=0;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&m,&n);
		temp=m;
		count=0;
		memset(factorize,0,sizeof(factorize));
		for(j=0;;j++){
			if(isprime[j]) continue;
			if(!(temp%j))
				factorize[count++]=j;
			else
				continue;
			while(!(temp%j))
				temp/=j;
			if(temp==1) break;
		}
		for(count=0;count<7;count++){
			if(!factorize[count]) break;
			pm=fac(m,factorize[count]);
			pn=0;
			for(j=2;j<=n;j++)
				pn+=fac(j,factorize[count]);
			if(!count) min=pn/pm;
			if(pn/pm<min)
				min=pn/pm;
		}
		printf("Case %d:\n",i+1);
		if(!min)
			printf("Impossible to divide\n");
		else
			printf("%d\n",min);
	}
	return 0;
}
int fac(int num,int prime)
{
	if(!prime)
		return 0;
	if(!(num%prime))
		return fac(num/prime,prime)+1;
	else
		return 0;
}
