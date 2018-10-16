#include<stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))
#define max 1050
int main()
{
	char s[2][max];
	int word[2][26],i,j,len,m;
	while(fgets(s[0],max,stdin)!=NULL){
		fgets(s[1],max,stdin);
		memset(word,0,sizeof(word));
		for(j=0;j<2;j++){
			len=strlen(s[j]);
			for(i=0;i<len-1;i++)
				word[j][s[j][i]-'a']++;
		}
		for(i=0;i<26;i++)
			if(word[0][i]&&word[1][i]){
				m=min(word[0][i],word[1][i]);
				for(j=0;j<m;j++)
					putchar(i+'a');
			}
		puts("");
	}
	return 0;
}
