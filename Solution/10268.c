#include<stdio.h>
#include<string.h>
#define max 1000005
int main()
{
	int k,n,i;
	int f[max]={0};
	char polynomial[max];
	char *tokenPtr;
	while(scanf("%d ",&k)==1){
		fgets(polynomial,max,stdin);
		tokenPtr=strtok(polynomial," ");
		n=0;
		memset(f,0,sizeof(f));
		while(tokenPtr!=NULL){
			sscanf(tokenPtr,"%d",&f[n++]);
			tokenPtr=strtok(NULL," ");
		}
		for(i=0;i<n-1;i++)
			f[i]*=(n-1-i);
		for(i=0;i<n-1;i++)
			f[i+1]+=k*f[i];
		printf("%d\n",f[n-2]);
	}
	return 0;
}
