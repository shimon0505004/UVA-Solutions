#include<stdio.h>
int main()
{
	int i;
	double snail,decrease,H,D,F,U;
	while(1){
		scanf("%lf%lf%lf%lf",&H,&U,&D,&F);
		if(!H) break;
		decrease=U*F/100.0;
		for(i=0,snail=0;;i++){
			snail+=U;
			if(snail>H){
				printf("success on day %d\n",i+1);
				break;
			}
			snail-=D;
			if(snail<0){
				printf("failure on day %d\n",i+1);
				break;
			}
			if(U)
				U-=decrease;
			if(U<0) U=0;
		}
	}
	return 0;
}
