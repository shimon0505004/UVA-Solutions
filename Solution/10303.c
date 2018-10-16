#include<stdio.h>
#define maxd 605 
int Catalan[1001][maxd+1];
void printbignumber(int n)
{
	int i,j;
	for(i=0;!Catalan[n][i];i++);
	for(j=i;j<=maxd;j++)
		printf("%d",Catalan[n][j]);
	puts("");
}
void multiply(int n)
{
	char temp[6]={0};
	int len,i,j;
	sprintf(temp,"%d",4*n-2);
	len=strlen(temp);
	for(i=len-1;i>=0;i--)
		for(j=maxd;j>=3;j--)
			Catalan[n][i+j-len+1]+=(temp[i]-'0')*Catalan[n-1][j];
	for(i=maxd-1;i>=0;i--){
		Catalan[n][i]+=Catalan[n][i+1]/10;
		Catalan[n][i+1]%=10;
	}
}
void divide(int n)
{
	int i,j,remainder=0;
	for(i=0;!Catalan[n][i];i++);
	for(j=i;j<=maxd;j++){
		remainder*=10;
		remainder+=Catalan[n][j];
		Catalan[n][j]=remainder/(n+1);
		remainder%=(n+1);
	}
}
int main()
{
	int i,previous=1,nodes;
	memset(Catalan,0,sizeof(Catalan));
	Catalan[0][maxd]=Catalan[1][maxd]=1;
	while(scanf("%d",&nodes)==1){
		if(nodes>previous){
			for(i=previous+1;i<=nodes;i++){
				multiply(i);
				divide(i);
			}
			previous=nodes;
		}
		printbignumber(nodes);
	}
	return 0;
}
