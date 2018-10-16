#include<stdio.h>
int main(){
	int cases;
	int w,h;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&w,&h);
		printf("%d\n",(w/3)*(h/3));
	}
}
