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
	char str1[1005],str2[1005];
	int i,j;
	while(fgets(str1,1005,stdin)!=NULL){
		fgets(str2,1005,stdin);
		printf("%d\n",FindLCS(str1,str2)-1);
	}
	return 0;
}
