#include<stdio.h>
#include<string.h>
#include<ctype.h>
int FindLCS(char str1[501][30],char str2[501][30],int len1,int len2)
{
	int LCS[501][501];
	int i,j;
	memset(LCS,0,sizeof(LCS));
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			if(!strcmp(str1[i],str2[j]))
				LCS[i+1][j+1]=LCS[i][j]+1;
			else
				LCS[i+1][j+1]=(LCS[i][j+1]>LCS[i+1][j]?LCS[i][j+1]:LCS[i+1][j]);
	return LCS[len1][len2];
}
int main()
{
	char s[2][1005],w[2][501][30],*tokPtr,*tempPtr;
	int i,n,count[2],match,cases=0,len,j;
	while(1){
		memset(w,0,sizeof(w));
		if(gets(s[0])==NULL) break;
		gets(s[1]);
		if(*s[0]=='\0'||*s[1]=='\0'){
			printf("%2d. Blank!\n",++cases);
			continue;
		}
		for(i=0;i<2;i++){
			len=strlen(s[i]);
			for(j=0;j<len;j++)
				if(!isalpha(s[i][j])&&!isdigit(s[i][j]))
					s[i][j]=' ';
			count[i]=0;
			tokPtr=s[i];
			n=0;
			for(tokPtr=strtok(s[i]," ");tokPtr!=NULL;tokPtr=strtok(NULL," "))
				sprintf(w[i][count[i]++],"%s",tokPtr);
		}
		match=FindLCS(w[0],w[1],count[0],count[1]);
		printf("%2d. Length of longest match: %d\n",++cases,match);
	}
	return 0;
}
