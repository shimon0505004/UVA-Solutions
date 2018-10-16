#include<stdio.h>
#include<stdlib.h>
int main(){
	int M,a,b;
	scanf("%d",&M);
	while(M--){
		scanf("%d%d",&a,&b);
		if(b==0) puts("1");
		else if(a==0) puts("2");
		else if(abs(a)!=abs(b)) puts("TOO COMPLICATED");
		else puts("4");
	}
	return 0;
}
