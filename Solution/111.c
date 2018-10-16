#include<stdio.h>
int FindLCS(int*str1,int*str2,int size)
{
	int LCS[30][30];
	int i,j,result;
	memset(LCS,0,sizeof(LCS));
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			if(str1[i]==str2[j])
				LCS[i+1][j+1]=LCS[i][j]+1;
			else
				LCS[i+1][j+1]=(LCS[i][j+1]>LCS[i+1][j]?LCS[i][j+1]:LCS[i+1][j]);
	result=LCS[size][size];
	return result;
}
int main()
{
	int q,ques[30],i,guess[30];
	int exit=0,temp;
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&temp);
		ques[temp-1]=i;
	}
	while(1){
		for(i=0;i<q;i++){
			if(scanf("%d",&temp)!=1){
				exit=1;
				break;
			}
			guess[temp-1]=i;
		}
		if(exit) break;
		printf("%d\n",FindLCS(ques,guess,q));
	}
	return 0;
}
