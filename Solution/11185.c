#include<stdio.h>
void printTernany(int n){
	if(n>=3) printTernany(n/3),printf("%d",n%3);
	else printf("%d",n);
}
int main(){
	int n;
	while(scanf("%d",&n),n>=0) printTernany(n),puts("");
	return 0;
}
