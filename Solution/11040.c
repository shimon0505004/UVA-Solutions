#include<stdio.h>
#include<string.h>
int main(){
	int cases,i,j;
	int wall[9][9];
	scanf("%d",&cases);
	while(cases--){
		memset(wall,0,sizeof(wall));
		for(i=0;i<9;i+=2)
			for(j=0;j<=i;j+=2)
				scanf("%d",&wall[i][j]);
		for(i=1;i<9;i+=2)
			wall[8][i]=(wall[6][i-1]-wall[8][i-1]-wall[8][i+1])/2;
		for(i=7;i>0;i--)
			for(j=0;j<=i;j++)
				wall[i][j]=wall[i+1][j]+wall[i+1][j+1];
		for(i=0;i<9;i++){
			printf("%d",wall[i][0]);
			for(j=1;j<=i;j++)
				printf(" %d",wall[i][j]);
			puts("");
		}
	}
	return 0;
}
