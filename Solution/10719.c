#include<stdio.h>
#include<string.h>
#define max 82500
int main()
{
	int k,n,i;
	int f[10001]={0};
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
		printf("q(x):");
		for(i=0;i<n-1;i++){
			printf(" %d",f[i]);
			f[i+1]+=k*f[i];
		}
		printf("\nr = %d\n\n",f[n-1]);
	}
	return 0;
}
