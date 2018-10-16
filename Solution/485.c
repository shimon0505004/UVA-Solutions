#include<stdio.h>
#include<string.h>
#define Ubound 204
char Pascal[206][70];
void print(int n){
	int i;
	for(i=0;Pascal[n][i]==0;i++);
	printf(" ");
	for(;i<70;i++)
		printf("%d",Pascal[n][i]);
}
void add(int n){
	int i;
	Pascal[n][69]+=Pascal[n-1][69];
	for(i=68;i>=0;i--){
		Pascal[n][i]+=Pascal[n-1][i];
		Pascal[n][i]+=Pascal[n][i+1]/10;
		Pascal[n][i+1]%=10;
	}
}
int main()
{
	int i,j;
	memset(Pascal,0,sizeof(Pascal));
	Pascal[0][69]=1;
	for(i=0;i<=Ubound;i++){
		printf("1");
		for(j=1;j<i+1;j++)
			print(j);
		puts("");
		for(j=i+1;j>0;j--)
			add(j);
	}
	return 0;
}
