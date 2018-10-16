#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 210
char matrix[SIZE][SIZE];
int map[SIZE][SIZE];
void neighbor(int x,int y,int no){
	int i,j;
	char c=matrix[x][y];
	map[x][y]=no;
	for(i=-1;i<=1;i++)
		for(j=-1;j<=1;j++)
			if(i==0&&j==0) continue;
			else if(matrix[x+i][y+j]==c&&map[x+i][y+j]==0)
				neighbor(x+i,y+j,no);
	return;
}
int caldig(int n){
	if(n<10) return 1;
	if(n<100) return 2;
	if(n<1000) return 3;
	if(n<10000) return 4;
	return 5;
}
int main(){
	char input[SIZE],foo[10];
	int col,row,i,j,len,count,digits[SIZE],ret;
	for(;;){
		memset(matrix,0,sizeof(matrix));
		memset(map,0,sizeof(map));
		memset(digits,0,sizeof(digits));
		for(row=1;fgets(input,SIZE,stdin)!=NULL;row++){
			if(*input=='%') break;
			len=strlen(input);
			for(i=0,col=1;i<len;i++)
				if(isalpha(input[i])) matrix[row][col++]=input[i];
		}
		count=0;
		for(i=1;i<row;i++)
			for(j=1;j<col;j++){
				if(map[i][j]==0) neighbor(i,j,++count);
				len=caldig(map[i][j]);
				if(digits[j]<len) digits[j]=len;
			}
		for(i=1;i<row;i++){
			printf("%*d",digits[1],map[i][1]);
			for(j=2;j<col;j++)
				printf(" %*d",digits[j],map[i][j]);
			puts("");
		}
		puts("%");
		if(feof(stdin)) break;
	}
	return 0;
}
