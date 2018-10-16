#include<stdio.h>
#include<string.h>
void print(long long n,char isprint1){
	if(isprint1){
		if(n==1) printf("+ 1");
		else if(n==-1) printf("- 1");
		else if(n<0) printf("- %lld",-n);
		else printf("+ %lld",n);
	}else{
		if(n==1) printf("+ ");
		else if(n==-1) printf("- ");
		else if(n<0) printf("- %lld",-n);
		else printf("+ %lld",n);
	}
}
int main(){
	int deg,i,j;
	long long root;
	long long coeffecient[55];
	while(scanf("%d",&deg)==1){
		memset(coeffecient,0,sizeof(coeffecient));
		coeffecient[0]=1;
		for(i=1;i<=deg;i++){
			scanf("%lld",&root);
			root*=-1;
			for(j=i+1;j>0;j--)
				coeffecient[j]+=root*coeffecient[j-1];
		}
		if(deg==1){
			printf("x ");
			print(coeffecient[1],1);
			puts(" = 0");
			continue;
		}
		printf("x^%d ",deg);
		for(i=1;i<deg-1;i++){
			if(coeffecient[i]!=0){
				print(coeffecient[i],0);
				printf("x^%d ",deg-i);
			}
		}
		if(coeffecient[deg-1]!=0){
			print(coeffecient[deg-1],0);
			printf("x ");
		}
		print(coeffecient[deg],1);
		puts(" = 0");
	}
	return 0;
}
