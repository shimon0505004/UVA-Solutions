#include<stdio.h>
int main(){
	int cases;
	int a,b;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&a,&b);
		if(a>b) puts(">");
		else if(a<b) puts("<");
		else puts("=");
	}
	return 0;
}
