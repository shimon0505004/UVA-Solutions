#include<stdio.h>
char check_valid(char board[][4],int O,int X){
	int i;
	char win=0;
	if(O>X||O+1<X) return 0;
	for(i=0;i<3;i++){
		if(board[i][0]!='.'&&board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
			if(win!=0&&win!=board[i][0]) return 0;
			win=board[i][0];
		}else if(board[0][i]!='.'&&board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
			if(win!=0&&win!=board[0][i]) return 0;
			win=board[0][i];
		}
	}
	if(board[0][0]!='.'&&board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
		if(win!=0&&win!=board[0][0]) return 0;
		win=board[0][0];
	}
	if(board[2][0]!='.'&&board[2][0]==board[1][1]&&board[1][1]==board[0][2]){
		if(win!=0&&win!=board[2][0]) return 0;
		win=board[2][0];
	}
	if(win=='O'&&O!=X) return 0;
	if(win=='X'&&O+1!=X) return 0;
	return 1;
}
int main(){
	char board[3][4];
	int cases,O,X,i,j;
	scanf("%d",&cases);
	while(cases--){
		O=X=0;
		for(i=0;i<3;i++){
			scanf("%s",board[i]);
			for(j=0;j<3;j++)
				if(board[i][j]=='O') O++;
				else if(board[i][j]=='X') X++;
		}
		if(check_valid(board,O,X)) puts("yes");
		else puts("no");
	}
	return 0;
}
