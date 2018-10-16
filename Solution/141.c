#include<stdio.h>
#include<string.h>
char rotate(char m1[][52],char m2[][52],int N){
	int i,j;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			if(m1[i][j]!=m2[i][j]) break;
		if(j<=N) break;
	}
	if(i>N) return 1;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			if(m1[i][j]!=m2[j][N-i+1]) break;
		if(j<=N) break;
	}
	if(i>N) return 1;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			if(m1[i][j]!=m2[N+1-i][N+1-j]) break;
		if(j<=N) break;
	}
	if(i>N) return 1;
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
			if(m1[i][j]!=m2[N-j+1][i]) break;
		if(j<=N) break;
	}
	if(i>N) return 1;
	return 0;
}
int main(){
	int N,x,y,i,j;
	char map[105][52][52],instr;
	while(scanf("%d",&N),N){
		memset(map,'.',sizeof(map));
		for(i=1;i<=(N<<1);i++){
			memcpy(map+i,map+i-1,sizeof(int[52][52]));
			scanf("%d%d %c",&x,&y,&instr);
			if(instr=='+')
				map[i][x][y]='*';
			else map[i][x][y]='.';
		}
		for(i=1;i<=(N<<1);i++){
			for(j=0;j<i;j++)
				if(rotate(map[i],map[j],N)){
					printf("Player %d wins on move %d\n",i%2+1,i);
					break;
				}
			if(j<i) break;
		}
		if(i>(N<<1)) puts("Draw");
	}
	return 0;
}
