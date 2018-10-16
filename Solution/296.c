#include<stdio.h>
#include<string.h>
char match(char guess[][5],int clue[][2],int try,int G){
	char toString[5]={0};
	char A[4],B[4],*ptr;
	int i,j,m[2];
	for(i=3;i>=0;i--)
		toString[i]=try%10+'0',try/=10;
	for(i=0;i<G;i++){
		memset(A,0,sizeof(A)),memset(B,0,sizeof(B));
		memset(m,0,sizeof(m));
		for(j=0;j<4;j++) if(guess[i][j]==toString[j]) m[0]++,A[j]=1;
		if(m[0]!=clue[i][0]) return 0;
		for(j=0;j<4;j++){
			if(A[j]) continue;
			for(ptr=toString;(ptr=strchr(ptr,guess[i][j]))!=NULL;ptr++)
				if(A[ptr-toString]==0&&B[ptr-toString]==0){
					m[1]++,B[ptr-toString]=1;
					break;
				}
		}
		if(m[0]!=clue[i][0]||m[1]!=clue[i][1]) return 0;
	}
	return 1;
}
int main(){
	int N,G;
	char guess[10][5];
	int clue[10][2],i,j,answers,exact;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&G);
		for(i=0;i<G;i++)
			scanf("%s%d%*c%d",guess[i],&clue[i][0],&clue[i][1]);
		answers=0;
		for(i=0;i<10000;i++){
			if(match(guess,clue,i,G)) answers++,exact=i;
			if(answers>1) break;
		}
		if(answers==0)
			puts("impossible");
		else if(answers>1)
			puts("indeterminate");
		else
			printf("%.4d\n",exact);
	}
	return 0;
}
