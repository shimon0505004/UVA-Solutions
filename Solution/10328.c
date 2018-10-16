#include<stdio.h>
#include<string.h>
void add(char dest[],char src[]){
	int i;
	for(i=0;i<30;i++)
		dest[i]+=src[i];
	for(i=1;i<30;i++){
		dest[i]+=dest[i-1]/10;
		dest[i-1]%=10;
	}
}
void subtract(char dest[],char src[]){
	int i;
	for(i=0;i<30;i++){
		dest[i]=dest[i]+10-src[i];
		dest[i+1]--;
		dest[i+1]+=dest[i]/10;
		dest[i]%=10;
	}
}
int main(){
	int n,m,i,j;
	char ans[100+1][100+1][30];
	memset(ans,0,sizeof(ans));
	ans[0][0][0]=1;
	for(i=1;i<=100;i++){
		for(j=0;j<=i;j++){
			int t=i>j?i-j-1:0;
			add(ans[i][j],ans[i-1][j]);
			subtract(ans[i][j],ans[t][j]);
			add(ans[i][j],ans[i-1][j]);
			add(ans[i][j],ans[t][0]);
		}
	}
	while(scanf("%d%d",&n,&m)==2){
		for(i=30-1;i>0&&ans[n][m][i]==0;i--);
		for(;i>=0;i--) printf("%d",ans[n][m][i]);
		puts("");
	}
	return 0;
}
