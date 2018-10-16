#include<stdio.h>
int main()
{
	int Z,I,M,L,cycle[10000],n,i;
	for(i=1;;i++){
		scanf("%d%d%d%d",&Z,&I,&M,&L);
		if(!(Z+I+M+L)) break;
		memset(cycle,0,sizeof(cycle));
		n=0;
		while(!cycle[L]){
			cycle[L]=n++;
			L=(Z*L+I)%M;
		}
		printf("Case %d: %d\n",i,n-cycle[L]);
	}
	return 0;
}
