#include<stdio.h>
#include<string.h>
char Currency[35][50];
int N;
int convert(char *s){
	int i;
	for(i=0;i<N;i++) if(strcmp(Currency[i],s)==0) return i;
}
int main(){
	int i,j,k,A,cases;
	char C1[50],C2[50];
	double Arbitrage[35][35],ratio,t;
	for(cases=1;scanf("%d",&N),N;cases++){
		for(i=0;i<N;i++) scanf("%s",Currency[i]);
		scanf("%d",&A);
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				Arbitrage[i][j]=0;
		for(i=0;i<A;i++){
			scanf("%s%lf%s",C1,&ratio,C2);
			Arbitrage[convert(C1)][convert(C2)]=ratio;
		}
		for(k=0;k<N;k++)
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					if((t=Arbitrage[i][k]*Arbitrage[k][j])>Arbitrage[i][j])
						Arbitrage[i][j]=t;
		printf("Case %d: ",cases);
		for(i=0;i<N;i++)
			if(Arbitrage[i][i]>1){
				puts("Yes");
				break;
			}
		if(i==N) puts("No");
	}
	return 0;
}
