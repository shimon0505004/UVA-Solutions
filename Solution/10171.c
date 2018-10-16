#include<stdio.h>
#define INF 1000000000
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int young[26][26],mature[26][26];
	int N,i,j,k;
	char YM,UB,from,to,SM,PM;
	int cost,min;
	while(scanf("%d",&N),N){
		for(i=0;i<26;i++){
			for(j=0;j<26;j++)
				young[i][j]=mature[i][j]=INF;
			young[i][i]=mature[i][i]=0;
		}
		while(N--){
			scanf(" %c %c %c %c %d\n",&YM,&UB,&from,&to,&cost),from-='A',to-='A';
			if(YM=='Y'){
				if(UB=='U') young[(int)from][(int)to]=MIN(young[(int)from][(int)to],cost);
				else if(UB=='B') young[(int)from][(int)to]=MIN(young[(int)from][(int)to],cost),young[(int)to][(int)from]=MIN(young[(int)to][(int)from],cost);
			}else if(YM=='M'){
				if(UB=='U') mature[(int)from][(int)to]=MIN(mature[(int)from][(int)to],cost);
				else if(UB=='B') mature[(int)from][(int)to]=MIN(mature[(int)from][(int)to],cost),mature[(int)to][(int)from]=MIN(mature[(int)to][(int)from],cost);
			}
		}
		for(k=0;k<26;k++)
			for(i=0;i<26;i++)
				for(j=0;j<26;j++){
					young[i][j]=MIN(young[i][j],young[i][k]+young[k][j]);
					mature[i][j]=MIN(mature[i][j],mature[i][k]+mature[k][j]);
				}
		scanf(" %c %c",&SM,&PM),SM-='A',PM-='A';
		min=INF;
		for(i=0;i<26;i++)
			min=MIN(min,young[(int)SM][i]+mature[(int)PM][i]);
		if(min==INF) puts("You will never meet.");
		else{
			printf("%d",min);
			for(i=0;i<26;i++)
				if(young[(int)SM][i]+mature[(int)PM][i]==min)
					printf(" %c",i+'A');
			puts("");
		}
	}
	return 0;
}
