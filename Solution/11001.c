#include<stdio.h>
int main(){
	int v_t,v_0;
	while(scanf("%d%d",&v_t,&v_0),v_t||v_0){
		if(v_t%2!=0) puts("0");
		else if(2*((v_t/2)%v_0)==v_0) puts("0");
		else printf("%.0lf\n",(double)v_t/2/v_0);
	}
	return 0;
}
