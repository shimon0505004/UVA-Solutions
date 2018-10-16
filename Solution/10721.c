#include<stdio.h>
#include<string.h>
int main(){
	int i,n,m,k;
	long long barcode[51][51][51]={{{0}}};
	for(n=1;n<=50;n++){
		barcode[n][1][n]=1;
		for(k=2;k<=n;k++){
			for(m=n/k;m<n;m++){
				for(i=n-m;i<=n-1;i++)
					barcode[n][k][m]+=barcode[i][k-1][m];
				for(i=1;i<=m-1;i++)
					barcode[n][k][m]+=barcode[n-m][k-1][i];
			}
		}
	}
	for(n=1;n<=50;n++)
		for(k=1;k<=n;k++)
			for(m=2;m<=50;m++)
				barcode[n][k][m]+=barcode[n][k][m-1];
	while(scanf("%d%d%d",&n,&k,&m)==3)
		printf("%lld\n",barcode[n][k][m]);
	return 0;
}
