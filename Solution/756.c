#include<stdio.h>
#define PHY_CYCLE 23
#define EMO_CYCLE 28
#define INT_CYCLE 33
#define LCM_CYCLE (21252)
int main(){
	int physical,emotional,intellectual,day;
	int p[PHY_CYCLE],e[EMO_CYCLE],i[INT_CYCLE],j;
	int peak,cases=0;
	for(j=0;j<PHY_CYCLE;j++)
		p[EMO_CYCLE*INT_CYCLE*j%PHY_CYCLE]=j;
	for(j=0;j<EMO_CYCLE;j++)
		e[PHY_CYCLE*INT_CYCLE*j%EMO_CYCLE]=j;
	for(j=0;j<INT_CYCLE;j++)
		i[EMO_CYCLE*PHY_CYCLE*j%INT_CYCLE]=j;
	while(scanf("%d%d%d%d",&physical,&emotional,&intellectual,&day),day>=0){
		peak=PHY_CYCLE*EMO_CYCLE*i[intellectual%INT_CYCLE];
		peak+=EMO_CYCLE*INT_CYCLE*p[physical%PHY_CYCLE];
		peak+=PHY_CYCLE*INT_CYCLE*e[emotional%EMO_CYCLE];
		peak=(peak+LCM_CYCLE-day)%LCM_CYCLE;
		if(peak==0) peak=LCM_CYCLE;
		printf("Case %d: the next triple peak occurs in %d days.\n",++cases,peak);
	}
	return 0;
}
