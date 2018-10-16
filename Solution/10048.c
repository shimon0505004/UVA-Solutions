#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
	int C,S,Q,i,j,C1,C2,d,cases=0,k,t;
	int decibel[105][105];
	while(scanf("%d%d%d",&C,&S,&Q),C){
		for(i=1;i<=C;i++)
			for(j=1;j<=C;j++)
				decibel[i][j]=1e8;
		for(i=0;i<S;i++){
			scanf("%d%d%d",&C1,&C2,&d);
			decibel[C1][C2]=decibel[C2][C1]=d;
		}
		for(k=1;k<=C;k++)
			for(i=1;i<=C;i++)
				for(j=1;j<=C;j++)
					if(decibel[i][j]>(t=max(decibel[i][k],decibel[k][j])))
						decibel[i][j]=t;
		if(cases) puts("");
		printf("Case #%d\n",++cases);
		for(i=0;i<Q;i++){
			scanf("%d%d",&C1,&C2);
			if(decibel[C1][C2]==1e8){
				puts("no path");
				continue;
			}
			printf("%d\n",decibel[C1][C2]);
		}
	}
	return 0;
}
