#include<stdio.h>
#include<string.h>
char *suit[4]={"Clubs","Diamonds","Hearts","Spades"};
char *face[13]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
void printCard(int n){
	printf("%s of %s\n",face[n%13],suit[n/13]);
}
int main(){
	int cases,i,j,k,n;
	int shuffle[105][53];
	int rearrange[53],temp[53];
	char input[10];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			for(j=1;j<=52;j++)
				scanf("%d",&shuffle[i][j]);
		scanf(" ");
		for(i=1;i<=52;i++) rearrange[i]=i;
		while(fgets(input,10,stdin)!=NULL&&*input!='\n'){
			sscanf(input,"%d",&k);
			for(i=1;i<=52;i++) temp[i]=rearrange[shuffle[k][i]];
			memcpy(rearrange,temp,sizeof(int[53]));
		}
		for(i=1;i<=52;i++) printCard(rearrange[i]-1);
		if(cases) puts("");
	}
	return 0;
}
