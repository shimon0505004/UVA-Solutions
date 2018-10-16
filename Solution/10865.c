#include<stdio.h>
struct POINT{
	int x,y;
};
int main(){
	long long check;
	int ps,i,stan,ollie;
	struct POINT p[200005],line;
	while(scanf("%d",&ps),ps){
		for(i=0;i<ps;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		line=p[ps>>1];
		stan=ollie=0;
		for(i=0;i<ps;i++){
			check=(long long)(p[i].x-line.x)*(p[i].y-line.y);
			if(check>0) stan++;
			else if(check<0) ollie++;
		}
		printf("%d %d\n",stan,ollie);
	}
	return 0;
}
