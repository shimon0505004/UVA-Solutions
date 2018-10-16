#include<stdio.h>
#define maxn 20000001
int main()
{
	char *isprime;
	int i,j,count=1,S,n=1;
	int twinprime[100005][2]={0};
	isprime=(char*)malloc(sizeof(char)*(20000000+1));
	memset(isprime,0,sizeof(isprime));
	isprime[0]=isprime[1]=1;
	for(i=2;i<maxn/2;i++){
		if(isprime[i]) continue;
		for(j=2;i*j<maxn;j++)
			isprime[i*j]=1;
	}
	twinprime[0][0]=3;
	twinprime[0][1]=5;
	for(i=6;n<100005;i+=6){
		if(!isprime[i-1]&&!isprime[i+1]){
			twinprime[n][0]=i-1;
			twinprime[n][1]=i+1;
			n++;
		}
	}
	while(scanf("%d",&S)==1)
		printf("(%d, %d)\n",twinprime[S-1][0],twinprime[S-1][1]);
	return 0;
}
