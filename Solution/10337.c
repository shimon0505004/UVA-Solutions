#include<stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int main(){
	int wind[1005][10];
	int fuel[1005][10];
	int N,X,i,j,t;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&X),X/=100;
		for(i=9;i>=0;i--)
			for(j=0;j<X;j++)
				scanf("%d",&wind[j][i]);
		for(i=0;i<10;i++) fuel[0][i]=0;
		for(i=1;i<=X;i++)
			for(j=0;j<10;j++)
				fuel[i][j]=50000;
		for(i=0;i<X;i++){
			for(j=0;j<=MIN(i,9);j++){
				if(j>0&&fuel[i+1][j-1]>(t=fuel[i][j]+20-wind[i][j])) fuel[i+1][j-1]=t;
				if(j<9&&fuel[i+1][j+1]>(t=fuel[i][j]+60-wind[i][j])) fuel[i+1][j+1]=t;
				if(fuel[i+1][j]>(t=fuel[i][j]+30-wind[i][j])) fuel[i+1][j]=t;
			}
		}
		printf("%d\n",fuel[X][0]);
		puts("");
	}
	return 0;
}
