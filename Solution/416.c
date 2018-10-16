#include<stdio.h>
#define UNKNOWN 0
#define BURNOUT 1
char LCD[10][7]={{1,1,1,1,1,1,0},{0,1,1,0,0,0,0},{1,1,0,1,1,0,1},{1,1,1,1,0,0,1},{0,1,1,0,0,1,1},{1,0,1,1,0,1,1},{1,0,1,1,1,1,1},{1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
char countdown(char input[][10],int n,int from){
	char status[7]={0};
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<7;j++){
			if(LCD[from-i][j]==1){
				if(input[i][j]==0) status[j]=BURNOUT;
				else if(input[i][j]==1&&status[j]==BURNOUT) return 0;
			}else if(input[i][j]==1) return 0;
		}
	return 1;
}
char check_match(char input[][10],int n){
	int i;
	for(i=9;i>=n-1;i--) if(countdown(input,n,i)) return 1;
	return 0;
}
int main(){
	int n,i,j;
	char input[10][10];
	while(scanf("%d ",&n),n){
		for(i=0;i<n;i++){
			fgets(input[i],10,stdin);
			for(j=0;j<7;j++) input[i][j]=(input[i][j]=='Y'?1:0);
		}
		if(check_match(input,n)) puts("MATCH");
		else puts("MISMATCH");
	}
	return 0;
}
