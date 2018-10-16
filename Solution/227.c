#include<stdio.h>
#include<string.h>
int main(){
	char puzzle[10][10],*ptr,instr,isillegal;
	int i,j,x,y,cases=0;
	while(fgets(puzzle[0],10,stdin),puzzle[0][0]!='Z'){
		if(cases++) puts("");
		for(i=1;i<5;i++) fgets(puzzle[i],10,stdin);
		for(i=0;i<5;i++)
			if((ptr=strchr(puzzle[i],' '))!=NULL){
				x=i,y=ptr-puzzle[i];
				break;
			}
		isillegal=0;
		while(scanf(" %c",&instr),instr!='0'){
			if(isillegal) continue;
			switch(instr){
				case 'A':
					if(x==0) isillegal=1;
					else puzzle[x][y]=puzzle[--x][y];
					break;
				case 'B':
					if(x==4) isillegal=1;
					else puzzle[x][y]=puzzle[++x][y];
					break;
				case 'L':
					if(y==0) isillegal=1;
					else puzzle[x][y]=puzzle[x][--y];
					break;
				case 'R':
					if(y==4) isillegal=1;
					else puzzle[x][y]=puzzle[x][++y];
					break;
			}
		}
		getchar();
		printf("Puzzle #%d:\n",cases);
		if(isillegal){
			puts("This puzzle has no final configuration.");
			continue;
		}
		puzzle[x][y]=' ';
		for(i=0;i<5;i++){
			putchar(puzzle[i][0]);
			for(j=1;j<5;j++)
				printf(" %c",puzzle[i][j]);
			puts("");
		}
	}
	return 0;
}
