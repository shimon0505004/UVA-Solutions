#include<stdio.h>
int totlen;
void insert(char input[],int depth,char rest[]){
	int i,j;
	char copy[15]={0};
	if(depth==totlen){
		puts(input);
		return;
	}
	for(i=0;i<depth+1;i++){
		strncpy(copy,input,depth);
		for(j=depth;j>i;j--)
			copy[j]=copy[j-1];
		copy[i]=*rest;
		insert(copy,depth+1,rest+1);
	}
}
int main()
{
	char input[15];
	while(scanf("%s ",input)==1){
		totlen=strlen(input);
		insert(input,1,input+1);
		if(!feof(stdin)) puts("");
	}
	return 0;
}
