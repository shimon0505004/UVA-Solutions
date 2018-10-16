#include<stdio.h>
#include<string.h>
void printMCM(int from,int to,int d[][15]){
	int mid;
	if(from==to){
		printf("A%d",from+1);
		return;
	}
	mid=d[from][to];
	printf("(");
	printMCM(from,mid-1,d);
	printf(" x ");
	printMCM(mid,to,d);
	printf(")");
}
int main(){
	int N,l,i,j,cases;
	int m[15],d[15][15];
	int table[15][15];
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<N-1;i++)
			scanf("%d%*d",&m[i]);
		scanf("%d%d",&m[N-1],&m[N]);
		for(i=0;i<N;i++) table[i][i]=0;
		for(l=2;l<=N;l++){
			for(i=0;i<=N-l;i++){
				table[i][i+l-1]=2147483647;
				for(j=i+1;j<i+l;j++){
					int t=m[i]*m[j]*m[i+l]+table[i][j-1]+table[j][i+l-1];
					if(t<table[i][i+l-1]) table[i][i+l-1]=t,d[i][i+l-1]=j;
				}
			}
		}
		printf("Case %d: ",cases);
		printMCM(0,N-1,d);
		puts("");
	}
	return 0;
}
