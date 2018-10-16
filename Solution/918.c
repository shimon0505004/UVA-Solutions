#include<stdio.h>
#define EPS 1e-8
int magnitude(double I,double R){
	int i;
	double Z_i=0,Z_r=0,next_i,next_r;
	for(i=0;i<13;i++){
		if(Z_i*Z_i+Z_r*Z_r>4+1e-5) return i;
		next_i=2*Z_i*Z_r;
		next_r=Z_r*Z_r-Z_i*Z_i;
		Z_r=next_r+R,Z_i=next_i+I;
	}
	return i;
}
int main(){
	int cases;
	char ASCII[15];
	double MINI,MAXI,PRECI,MINR,MAXR,PRECR;
	double i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf(" %s%lf%lf%lf%lf%lf%lf",ASCII,&MINI,&MAXI,&PRECI,&MINR,&MAXR,&PRECR);
		ASCII[13]=' ';
		for(i=MINI;i<MAXI+EPS;i+=PRECI,puts(""))
			for(j=MINR;j<MAXR+EPS;j+=PRECR)
				putchar(ASCII[magnitude(i,j)]);
		if(cases) puts("");
	}
	return 0;
}
