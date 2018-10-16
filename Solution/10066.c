#include<stdio.h>
int FindLCS(int*str1,int*str2,int len1,int len2)
{
	int LCS[1050][1050];
	int i,j;
	memset(LCS,0,sizeof(LCS));
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
	int t1,t2;
	int tower1[105],tower2[105];
	int i,cases=0;
	while(scanf("%d%d",&t1,&t2)==2&&(t1+t2)){
		for(i=0;i<t1;i++)
			scanf("%d",&tower1[i]);
		for(i=0;i<t2;i++)
			scanf("%d",&tower2[i]);
		printf("Twin Towers #%d\n",++cases);
		printf("Number of Tiles : %d\n\n",FindLCS(tower1,tower2,t1,t2));
	}
	return 0;
}
