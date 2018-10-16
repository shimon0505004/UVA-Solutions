#include<stdio.h>
#define pi 3.14159265358979323846
int main(){
	int cases;
	double lx,ly,lz,dx,dy,dz;
	for(cases=1;scanf("%lf%lf%lf%lf%lf%lf",&lx,&ly,&lz,&dx,&dy,&dz)==6;cases++){
		printf("Set #%d\n",cases);
		dx/=2,dy/=2,dz/=2;
		if(dx*2>lx) printf("%.6lf\n",dy*dz*(1-(lx-dx)*(lx-dx)/(dx*dx))*pi);
		else if(dy*2>ly) printf("%.6lf\n",dx*dz*(1-(ly-dy)*(ly-dy)/(dy*dy))*pi);
		else if(dz*2>lz) printf("%.6lf\n",dy*dx*(1-(lz-dz)*(lz-dz)/(dz*dz))*pi);
		else puts("0.000000");
	}
	return 0;
}
