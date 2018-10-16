#include<stdio.h>
#include<string.h>
#define LU 1
#define U 2
#define L 4
char p1[105][35];
char p2[105][35];
int table[105][105];
char common[105][105];
void printLCS(int n1,int n2){
	if(common[n1][n2]==U) printLCS(n1-1,n2);
	else if(common[n1][n2]==L) printLCS(n1,n2-1);
	else if(common[n1][n2]==LU){
		if(table[n1][n2]==1)
			printf("%s",p1[n1]);
		else{
			printLCS(n1-1,n2-1);
			printf(" %s",p1[n1]);
		}
	}
}
int main(){
	int n1,n2,i,j;
	while(!feof(stdin)){
		memset(table,0,sizeof(table));
		for(n1=1;scanf("%s",p1[n1]),p1[n1][0]!='#';n1++);
		for(n2=1;scanf("%s",p2[n2]),p2[n2][0]!='#';n2++);
		n1--,n2--;
		for(i=1;i<=n1;i++)
			for(j=1;j<=n2;j++){
				if(strcmp(p1[i],p2[j])==0){
					table[i][j]=table[i-1][j-1]+1;
					common[i][j]=LU;
				}else if(table[i-1][j]>table[i][j-1]){
					table[i][j]=table[i-1][j];
					common[i][j]=U;
				}else{
					table[i][j]=table[i][j-1];
					common[i][j]=L;
				}
			}
		printLCS(n1,n2);
		puts("");
		scanf(" ");
	}
	return 0;
}
