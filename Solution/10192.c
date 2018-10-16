#include<stdio.h>
#include<string.h>
int FindLCS(char*str1,char*str2)
{
	int LCS[1050][1050];
	int i,j,len1,len2;
	memset(LCS,0,sizeof(LCS));
	len1=strlen(str1);
	len2=strlen(str2);
	for(i=0;i<len1;i++)
		for(j=0;j<len2;j++)
			if(str1[i]==str2[j])
				LCS[i+1][j+1]=LCS[i][j]+1;
			else
				LCS[i+1][j+1]=(LCS[i][j+1]>LCS[i+1][j]?LCS[i][j+1]:LCS[i+1][j]);
	return LCS[len1][len2];
}
int main()
{
	int cases=0,len,i,spn[205],max,maxi;
	char comment1[205],comment2[205];
	while(1){
		fgets(comment1,205,stdin);
		if(*comment1=='#') break;
		if(fgets(comment2,205,stdin)==NULL) break;
		printf("Case #%d: you can visit at most %d cities.\n",++cases,FindLCS(comment1,comment2)-1);
	}
	return 0;
}
