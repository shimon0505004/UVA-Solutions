#include<stdio.h>
int main()
{
	int I,M,L,n,i;
	char message[12],cycle[100000];
	while(scanf("%d%d",&I,&M)==2){
		memset(cycle,0,sizeof(cycle));
		n=0;
		L=0;
		while(!cycle[L]){
			cycle[L]=1;
			n++;
			L=(L+I)%M;
		}
		if(n==M)
			sprintf(message,"%s","Good Choice");
		else
			sprintf(message,"%s","Bad Choice");
		printf("%10d%10d    %s\n\n",I,M,message);
	}
	return 0;
}
