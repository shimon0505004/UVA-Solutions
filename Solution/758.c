#include<stdio.h>
#include<stdlib.h>
void rem_cell(char *grid[],int x,int y){
	char c=grid[y][x];
	grid[y][x]=0;
	if(grid[y][x-1]==c) rem_cell(grid,x-1,y);
	if(grid[y][x+1]==c) rem_cell(grid,x+1,y);
	if(grid[y-1][x]==c) rem_cell(grid,x,y-1);
	if(grid[y+1][x]==c) rem_cell(grid,x,y+1);
}
void drop_down(char *grid[]){
	int i,emp,nemp;
	for(i=1;i<=15;i++){
		for(emp=1;emp<=10&&grid[i][emp]!=0;emp++);
		if(emp<=10){
			for(nemp=emp+1;nemp<=10;nemp++)
				if(grid[i][nemp]!=0){
					grid[i][emp++]=grid[i][nemp];
					grid[i][nemp]=0;
				}
		}
	}
}
void slide(char *grid[]){
	int emp,nemp;
	for(emp=1;emp<=15&&grid[emp][1]!=0;emp++);
	if(emp<=15){
		for(nemp=emp+1;nemp<=15;nemp++)
			if(grid[nemp][1]!=0){
				char *temp=grid[nemp];
				grid[nemp]=grid[emp],grid[emp]=temp;
				emp++;
			}
	}
}
int count_same(char *grid[],int x,int y,char visit[][15]){
	int ret=1;
	char c=grid[y][x];
	visit[y][x]=1;
	if(visit[y][x-1]==0&&grid[y][x-1]==c) ret+=count_same(grid,x-1,y,visit);
	if(visit[y][x+1]==0&&grid[y][x+1]==c) ret+=count_same(grid,x+1,y,visit);
	if(visit[y-1][x]==0&&grid[y-1][x]==c) ret+=count_same(grid,x,y-1,visit);
	if(visit[y+1][x]==0&&grid[y+1][x]==c) ret+=count_same(grid,x,y+1,visit);
	return ret;
}
int choose_to_remove(char *grid[],int *x,int *y){
	int maxx=15,maxy=20,max=0;
	char visit[20][15]={{0}};
	int i,j;
	for(i=1;i<=15;i++){
		if(grid[i][1]==0) break;
		for(j=1;j<=10;j++){
			int n;
			if(grid[i][j]==0) break;
			if(visit[i][j]) continue;
			n=count_same(grid,j,i,visit);
			if(n>max) maxx=j,maxy=i,max=n;
		}
	}
	*x=maxx,*y=maxy;
	return max;
}
int count_ball(char *grid[]){
	int i,j,ret=0;
	for(i=1;grid[i][1]!=0;i++)
		for(j=1;grid[i][j]!=0;j++)
			ret++;
	return ret;
}
int main(){
	int i,j,x,y;
	char *grid[20];
	int cases,T,num,n_move,score;
	for(i=0;i<20;i++) grid[i]=(char *)malloc(sizeof(char[15]));
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		if(cases>1) puts("");
		printf("Game %d:\n\n",cases);
		for(i=0;i<20;i++) for(j=0;j<15;j++) grid[i][j]=0;
		scanf(" ");
		for(i=10;i>0;i--){
			for(j=1;j<=15;j++)
				grid[j][i]=getchar();
			getchar();
		}
		score=0;
		for(n_move=1;num=choose_to_remove(grid,&x,&y),num>1;n_move++){
			printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n",n_move,x,y,num,grid[y][x],(num-2)*(num-2));
			score+=(num-2)*(num-2);
			rem_cell(grid,x,y);
			drop_down(grid);
			slide(grid);
		}
		num=count_ball(grid);
		if(num==0) score+=1000;
		printf("Final score: %d, with %d balls remaining.\n",score,num);
	}
	return 0;
}
