#include<stdio.h>
#include<string.h>
char isB2(int B2[],char used[],int N){
	int i,j;
	if(B2[0]<1) return 0;
	for(i=1;i<N;i++){
		if(B2[i]<=B2[i-1]) return 0;
		for(j=0;j<=i;j++)
			if(used[B2[i]+B2[j]]) return 0;
			else used[B2[i]+B2[j]]=1;
	}
	return 1;
}
int main(){
	int N,i;
	int B2[105];
	char used[20005];
	int cases;
	for(cases=1;scanf("%d",&N)==1;cases++){
		for(i=0;i<N;i++) scanf("%d",&B2[i]);
		memset(used,0,sizeof(used));
		printf("Case #%d: ",cases);
		if(isB2(B2,used,N)) puts("It is a B2-Sequence.");
		else puts("It is not a B2-Sequence.");
		puts("");
	}
	return 0;
}
