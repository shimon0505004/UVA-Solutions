#include<stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
int main()
{
	int N,R,i,j,C1,C2,c,Psg,trips,maximin,cases=0,k,t;
	int capac[105][105];
	while(scanf("%d%d",&N,&R),N){
		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				capac[i][j]=0;
		for(i=0;i<R;i++){
			scanf("%d%d%d",&C1,&C2,&c);
			capac[C1][C2]=capac[C2][C1]=c;
		}
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=i;j++)
					if(capac[i][j]<(t=min(capac[i][k],capac[k][j])))
						capac[i][j]=capac[j][i]=t;
		printf("Scenario #%d\n",++cases);
		scanf("%d%d%d",&C1,&C2,&Psg);
		maximin=capac[C1][C2]-1;
		trips=Psg/maximin;
		if(Psg%maximin) trips++;
		printf("Minimum Number of Trips = %d\n\n",trips);
	}
	return 0;
}
