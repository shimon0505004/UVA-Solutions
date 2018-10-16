#include<stdio.h>
int main(){
	int i,j,k,n;
	double table[10][105];
	double prob[10][105];
	for(i=1;i<=10;i++){
		for(j=0;j<10;j++) table[j][1]=1.0/i;
		prob[i-1][1]=1;
		for(j=2;j<=100;j++){
			table[0][j]=(table[0][j-1]+table[1][j-1])/i;
			for(k=1;k<i-1;k++)
				table[k][j]=(table[k-1][j-1]+table[k][j-1]+table[k+1][j-1])/i;
			table[i-1][j]=(table[i-1][j-1]+table[i-2][j-1])/i;
			prob[i-1][j]=0;
			for(k=0;k<i;k++) prob[i-1][j]+=table[k][j];
		}
	}
	while(scanf("%d%d",&k,&n)==2)
		printf("%.5lf\n",prob[k][n]*100);
	return 0;
}
