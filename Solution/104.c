#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k,l,from,to;
	double arbi[20][20][20];
	int change[20][20][20];
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				if(i==j) arbi[0][i][j]=1;
				else scanf("%lf",&arbi[0][i][j]);
		}
		for(i=1;i<n;i++){
			for(j=0;j<n;j++)
				for(k=0;k<n;k++){
					arbi[i][j][k]=arbi[i-1][j][k];
					change[i][j][k]=-1;
					for(l=0;l<n;l++)
						if(arbi[i][j][k]<arbi[i-1][j][l]*arbi[0][l][k]){
							arbi[i][j][k]=arbi[i-1][j][l]*arbi[0][l][k];
							change[i][j][k]=l;
						}
				}
			for(j=0;j<n;j++)
				if(arbi[i][j][j]>1.01){
					int out[20];
					from=to=j;
					for(k=i;k>0;k--){
						out[k]=change[k][from][to];
						to=out[k];
					}
					printf("%d",j+1);
					for(k=1;k<=i;k++) printf(" %d",out[k]+1);
					printf(" %d",j+1);
					puts("");
					break;
				}
			if(j<n) break;
		}
		if(i==n) puts("no arbitrage sequence exists");
	}
	return 0;
}
