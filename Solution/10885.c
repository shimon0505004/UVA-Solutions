#include<stdio.h>
struct FRAC{
	int num,den;
};
struct POINT{
	struct FRAC x,y;
};
int main(){
	struct POINT point[13];
	int pythagorean_tri[3][3]={{3,4,5},{5,12,13},{7,24,25}};
	int p,q,r,i,num_x,num_y,den,lcm;
	int x_min,y_min;
	for(i=0;i<3;i++){
		r=pythagorean_tri[i][0];
		p=pythagorean_tri[i][1];
		q=pythagorean_tri[i][2];
		num_x=r*r-p*p,den=q*q,num_y=2*p*r;
		point[i].x.num=num_x,point[i].x.den=den;
		point[i].y.num=num_y,point[i].y.den=den;
		point[i+3].x.num=num_x,point[i+3].x.den=den;
		point[i+3].y.num=-num_y,point[i+3].y.den=den;
		point[i+6].x.num=-num_x,point[i+6].x.den=den;
		point[i+6].y.num=num_y,point[i+6].y.den=den;
		point[i+9].x.num=-num_x,point[i+9].x.den=den;
		point[i+9].y.num=-num_y,point[i+9].y.den=den;
	}
	num_x=21*21-20*20,num_y=2*20*21,den=29*29;
	point[12].x.num=21*21-20*20,point[12].x.den=29*29;
	point[12].y.num=2*21*20,point[12].y.den=29*29;
	lcm=625*169*29*29;
	x_min=y_min=1000000000;
	for(i=0;i<13;i++){
		point[i].x.num*=lcm/point[i].x.den;
		point[i].y.num*=lcm/point[i].y.den;
		if(point[i].x.num<x_min) x_min=point[i].x.num;
		if(point[i].y.num<y_min) y_min=point[i].y.num;
	}
	for(i=0;i<13;i++)
		printf("%d %d\n",point[i].x.num-x_min,point[i].y.num-y_min);
	return 0;
}
