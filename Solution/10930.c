#include<stdio.h>
#include<string.h>
int main(){
	int D,i,cases,input[35],j;
	char seq[1005];
	for(cases=1;scanf("%d",&D)==1;cases++){
		printf("Case #%d:",cases);
		for(i=0;i<D;i++){
			scanf("%d",&input[i]);
			printf(" %d",input[i]);
		}
		puts("");
		for(i=1;i<D;i++)
			if(input[i]<input[i-1]){
				puts("This is not an A-sequence.");
				break;
			}
		if(i<D) continue;
		memset(seq,0,sizeof(seq));
		for(i=0;i<D;i++){
			if(seq[input[i]]) break;
			for(j=1000;j>=1;j--){
				if(j+input[i]>1000) continue;
				if(seq[j]) seq[input[i]+j]=1;
			}
			seq[input[i]]=1;
		}
		if(i<D) puts("This is not an A-sequence.");
		else puts("This is an A-sequence.");
	}
	return 0;
}
