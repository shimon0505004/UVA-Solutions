#include<stdio.h>
int main(){
	double u,p[25],min,cost[201];
	int M,N[25],need,i,j,cases=0;
	char check;
	while(scanf("%lf%d",&u,&M)==2){
		printf("Case %d:\n",++cases);
		for(i=0;i<=200;i++) cost[i]=u*i;
		for(i=0;i<M;i++){
			scanf("%d%lf",&N[i],&p[i]);
			for(j=N[i];j<=200;j++)
				if((min=cost[j-N[i]]+p[i])<cost[j]) cost[j]=min;
		}
		min=cost[200];
		for(i=200;i>=0;i--)
			if(cost[i]>min) cost[i]=min;
			else if(cost[i]<min) min=cost[i];
		while(scanf("%d",&need)){
			printf("Buy %d for $%.2lf\n",need,cost[need]);
			if(getchar()=='\n') break;
		}
	}
	return 0;
}
