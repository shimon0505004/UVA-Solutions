#include<stdio.h>
#include<stdlib.h>
int r,c;
void rem_cell(signed char *grid[],int x,int y){
	signed char d=grid[y][x];
	if(x<0||x>r||y<0||y>c) return;
	if(grid[y][x]==-1) return;
	grid[y][x]=-1;
	if(grid[y][x-1]==d) rem_cell(grid,x-1,y);
	if(grid[y][x+1]==d) rem_cell(grid,x+1,y);
	if(grid[y-1][x]==d) rem_cell(grid,x,y-1);
	if(grid[y+1][x]==d) rem_cell(grid,x,y+1);
}
void drop_down(signed char *grid[]){
	int i,emp,nemp;
	for(i=1;i<=c;i++){
		for(emp=1;emp<=r&&grid[i][emp]!=-1;emp++);
		if(emp<=r){
			for(nemp=emp+1;nemp<=r;nemp++)
				if(grid[i][nemp]!=-1){
					grid[i][emp++]=grid[i][nemp];
					grid[i][nemp]=-1;
				}
		}
	}
}
void slide(signed char *grid[]){
	int emp,nemp;
	for(emp=1;emp<=c&&grid[emp][1]!=-1;emp++);
	if(emp<=c){
		for(nemp=emp+1;nemp<=c;nemp++)
			if(grid[nemp][1]!=-1){
				signed char *temp=grid[nemp];
				grid[nemp]=grid[emp],grid[emp]=temp;
				emp++;
			}
	}
}
int main(){
	int i,j,x,y;
	signed char *grid[45];
	int cases;
	for(i=0;i<45;i++) grid[i]=(signed char *)malloc(sizeof(signed char[15]));
	for(cases=1;scanf("%d%d",&r,&c),r&&c;cases++){
		for(i=0;i<45;i++) for(j=0;j<15;j++) grid[i][j]=-1;
		for(i=1;i<=r;i++)
			for(j=1;j<=c;j++)
				scanf("%hhd",&grid[j][i]);
		while(scanf("%d%d",&x,&y),x|y){
			char d=grid[y][x];
			if(x<0||x>r||y<0||y>c) continue;
			if(grid[y][x]==-1) continue;
			if(grid[y][x-1]!=d&&grid[y][x+1]!=d&&grid[y-1][x]!=d&&grid[y+1][x]!=d) continue;
			rem_cell(grid,x,y);
			drop_down(grid);
			slide(grid);
		}
		printf("Grid %d.\n",cases);
		if(grid[1][1]==-1) puts("    Game Won");
		else{
			for(i=r;i>0;i--){
				printf("   ");
				for(j=1;j<=c;j++){
					putchar(' ');
					if(grid[j][i]!=-1) printf("%d",grid[j][i]);
					else putchar(' ');
				}
				puts("");
			}
		}
		puts("");
	}
	return 0;
}
