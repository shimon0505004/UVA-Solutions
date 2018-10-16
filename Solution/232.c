#include<stdio.h>
#include<string.h>
int main(){
	char puzzle[15][15];
	int number[15][15];
	int r,c,i,j,k,id;
	int cases;
	for(cases=1;scanf("%d%d ",&r,&c),r;cases++){
		if(cases>1) puts("");
		memset(number,0,sizeof(number));
		memset(puzzle,'*',sizeof(puzzle));
		for(i=1;i<=r;i++){
			fgets(puzzle[i]+1,14,stdin);
			puzzle[i][c+1]='*';
		}
		id=0;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				if(puzzle[i][j]!='*'&&(puzzle[i-1][j]=='*'||puzzle[i][j-1]=='*'))
					number[i][j]=++id;
		printf("puzzle #%d:\n",cases);
		puts("Across");
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				if(number[i][j]&&puzzle[i][j-1]=='*'){
					printf("%3d.",number[i][j]);
					for(k=j;puzzle[i][k]!='*';k++)
						putchar(puzzle[i][k]);
					puts("");
				}
		puts("Down");
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				if(number[i][j]&&puzzle[i-1][j]=='*'){
					printf("%3d.",number[i][j]);
					for(k=i;puzzle[k][j]!='*';k++)
						putchar(puzzle[k][j]);
					puts("");
				}
	}
	return 0;
}
