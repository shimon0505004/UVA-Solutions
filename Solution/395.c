#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int row[10],col[10],sub[20],add[20];
char check;
char move(char board[][10],int x,int y,int d_x,int d_y,int dest,char ans[]){
	int i,j;
	int t_x=x+d_x*dest,t_y=y+d_y*dest;
	if(t_x<1||t_x>8||t_y<1||t_y>8||board[t_x][t_y]==check) return 0;
	for(i=x,j=y;j!=t_y||i!=t_x;i+=d_x,j+=d_y)
		if(board[i][j]!='.'&&board[i][j]!=check) return 0;
	sprintf(ans,"%c%d-%c%d",'A'+x-1,y,'A'+t_x-1,t_y);
	return 1;
}
int compar(const void *a,const void *b){
	return strcmp((char *)b,(char *)a);
}
int main(){
	char board[10][10];
	int i,j,n_answer;
	char start=0,ans[8][10],is_answer;
	while(!feof(stdin)){
		if(start) puts("");
		else start=1;
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		memset(sub,0,sizeof(sub));
		memset(add,0,sizeof(add));
		memset(board,0,sizeof(board));
		for(i=1;i<=8;i++){
			fgets(board[i]+1,10,stdin);
			for(j=1;j<=8;j++)
				if(board[i][j]!='.')
					row[i]++,col[j]++,sub[i-j+8]++,add[i+j]++;
		}
		scanf("%c ",&check);
		is_answer=0;
		for(i=1;i<=8;i++)
			for(j=1;j<=8;j++)
				if(board[i][j]==check){
					n_answer=0;
					memset(ans,0,sizeof(ans));
					n_answer+=move(board,i,j,-1,-1,sub[i-j+8],ans[0]);
					n_answer+=move(board,i,j,-1,0,col[j],ans[1]);
					n_answer+=move(board,i,j,-1,1,add[i+j],ans[2]);
					n_answer+=move(board,i,j,0,-1,row[i],ans[3]);
					n_answer+=move(board,i,j,0,1,row[i],ans[4]);
					n_answer+=move(board,i,j,1,-1,add[i+j],ans[5]);
					n_answer+=move(board,i,j,1,0,col[j],ans[6]);
					n_answer+=move(board,i,j,1,1,sub[i-j+8],ans[7]);
					qsort(ans,8,sizeof(char[10]),compar);
					if(n_answer) is_answer=1;
					while(n_answer--) puts(ans[n_answer]);
				}
		if(!is_answer) puts("No moves are possible");
	}
	return 0;
}
