#include<stdio.h>
int DEPTH;
char output[35];
void dfs(char alpha[],int pos,int depth){
	int i;
	if(depth==DEPTH){
		puts(output);
		return;
	}
	for(i=pos;i<26;i++){
		if(alpha[i]){
			output[depth]=i+'a';
			alpha[i]--;
			dfs(alpha,i,depth+1);
			alpha[i]++;
		}
	}
}
int main()
{
	char s[35];
	char alpha[26];
	int r,i;
	while(scanf("%s%d",s,&r)==2){
		DEPTH=r;
		memset(alpha,0,sizeof(alpha));
		memset(output,0,sizeof(output));
		for(i=0;s[i]!=0;i++) alpha[s[i]-'a']++;
		dfs(alpha,0,0);
	}
	return 0;
}
