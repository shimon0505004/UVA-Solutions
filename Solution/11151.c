#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	char s1[1005],s2[1005];
	int n,len,i,j;
	int table[1005][1005];
	scanf("%d%*c",&n);
	while(n--){
		fgets(s1+1,1005,stdin);
		len=strlen(s1+1)-1;
		for(i=1;i<=len;i++) s2[len-i+1]=s1[i];
		memset(table,0,sizeof(table));
		for(i=1;i<=len;i++)
			for(j=1;j<=len;j++)
				if(s1[i]==s2[j]) table[i][j]=table[i-1][j-1]+1;
				else table[i][j]=MAX(table[i][j-1],table[i-1][j]);
		printf("%d\n",table[len][len]);
	}
	return 0;
}
