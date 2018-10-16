#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char chess[92][9],visit[9]={0},add[19]={0},subtract[17]={0};
char p[9];
int soln=0;
void dfs(int depth){
	int i;
	if(depth==9){
		for(i=1;i<=8;i++)
			chess[soln][i]=p[i];
		soln++;
	}else{
		for(i=1;i<=8;i++){
			if(visit[i]) continue;
			if(!visit[i]&&!add[depth+i]&&!subtract[depth-i+8]){
				p[depth]=i;
				visit[i]=1;
				add[depth+i]=1;
				subtract[depth-i+8]=1;
				dfs(depth+1);
				subtract[depth-i+8]=0;
				add[depth+i]=0;
				p[depth]=0;
				visit[i]=0;
			}
		}
	}
}
char getPos(int pos[]){
	int i;
	for(i=1;i<=8;i++)
		if(scanf("%d",&pos[i])!=1)
			return 0;
	return 1;
}
int minMove(int pos[]){
	int min=8;
	int i,j;
	for(i=0;i<soln;i++){
		int move=0;
		for(j=1;j<=8;j++)
			if(pos[j]!=chess[i][j]) move++;
		if(min>move) min=move;
	}
	return min;
}
int main(){
	int cases;
	int pos[9];
	dfs(1);
	for(cases=1;getPos(pos);cases++)
		printf("Case %d: %d\n",cases,minMove(pos));
	return 0;
}
