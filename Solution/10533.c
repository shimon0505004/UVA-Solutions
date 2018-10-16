#include<stdio.h>
#include<string.h>
#define maxn 1000001
int main()
{
	int i,j,k,cases,n1,n2,isdigitprime,isdigitprimen;
	int len;
	char digitprime[maxn]={0};
	char ns[10];
	int digitprimen[maxn]={0};
	digitprime[0]=digitprime[1]=1;
	for(i=2;i<maxn;i++){
		if(digitprime[i]) continue;
		for(j=2;i*j<maxn;j++)
			digitprime[i*j]=1;
	}
	for(i=2;i<maxn;i++){
		digitprimen[i]=digitprimen[i-1];
		if(digitprime[i]) continue;
		sprintf(ns,"%d",i);
		len=strlen(ns);
		isdigitprime=0;
		for(j=0;j<len;j++)
			isdigitprime+=(ns[j]-'0');
		if(!digitprime[isdigitprime])
			digitprimen[i]++;
	}
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&n1,&n2);
		printf("%d\n",digitprimen[n2]-digitprimen[n1-1]);
	}
	return 0;
}
