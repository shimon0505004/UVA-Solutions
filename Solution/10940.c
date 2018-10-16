#include<stdio.h>
int main(){
	int n,i,t;
	while(scanf("%d",&n),n){
		if(n==1){
			puts("1");
			continue;
		}
		t=n-1;
		for(i=0;t>>=1;i++);
		printf("%d\n",(n-(1<<i))<<1);
	}
	return 0;
}
