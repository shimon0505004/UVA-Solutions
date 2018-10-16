#include<stdio.h>
#include<string.h>
void dfs(int L,int *n,char output[],int len){
	int i,j;
	if(*n<0) return;
	if(*n==0){
		for(i=0;putchar(output[i]),++i<len;){
			if(i==64) puts("");
			else if(i%4==0) putchar(' ');
		}
		puts("");
		printf("%d\n",len);
		return;
	}
	for(i=0;i<L;i++){
		output[len]=i+'A';
		for(j=len;j>len/2;j--)
			if(strncmp(output+j,output+2*j-len-1,len-j+1)==0) break;
		if(j==len/2) (*n)--,dfs(L,n,output,len+1);
	}
}
int main(){
	int n,L,len;
	char output[85];
	while(scanf("%d%d",&n,&L),n||L){
		len=0;
		dfs(L,&n,output,len);
	}
	return 0;
}
