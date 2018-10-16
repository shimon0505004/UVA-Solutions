#include<stdio.h>
static char sod[10000005]={0};
int self[1000000];
int n_self(int n){
	int i;
	if(n<10) return (n+1)/2;
	for(i=(n-9)/10;10*i+sod[i]+9>n;i--);
	return self[i];
}
int main(){
	int i,j,T,cases,n1,n2;
	for(i=1;i<10000000;i++)
		sod[i]=sod[i/10]+i%10;
	self[0]=5;
	for(i=1;i<1000000;i++){
		int s=10*i+sod[i]+9;
		for(j=(s-63>0?s-63:0);j<s;j++)
			if(j+sod[j]==s) break;
		if(j==s) self[i]=self[i-1]+1;
		else self[i]=self[i-1];
	}
	scanf("%d ",&T);
	for(cases=1;cases<=T;cases++){
		char input[25];
		fgets(input,25,stdin);
		printf("Case %d: ",cases);
		if(sscanf(input,"%d%d",&n1,&n2)==1){
			for(i=(n1-63>0?n1-63:0);i<n1;i++)
				if(i+sod[i]==n1) break;
			if(i==n1) puts("-1");
			else printf("%d\n",i);
		}else{
			printf("%d\n",n_self(n2)-n_self(n1-1));
		}
	}
	return 0;
}
