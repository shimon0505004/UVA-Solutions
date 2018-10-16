#include<stdio.h>
int main()
{
	int deg,pos,code1,code2,code3;
	while(1){
		deg=1080;
		scanf("%d%d%d%d",&pos,&code1,&code2,&code3);
		if(code1+code2+code3==0)
			break;
		deg+=(code1-pos>0?360:0)+(pos-code1)*9;
		deg+=(code2-code1>0?0:360)+(code2-code1)*9;
		deg+=(code3-code2>0?360:0)+(code2-code3)*9;
		printf("%d\n",deg);
	}
	return 0;
}
