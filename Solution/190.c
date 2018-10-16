#include<stdio.h>
#include<math.h>
double distance(double,double,double,double);
int main()
{
	double ax,ay,bx,by,cx,cy,ab,bc,ca,area,r,s,ox,oy;
	double vabx,vaby,vacx,vacy,acdotab,vaox,vaoy,x,y;
	char operax[5],operay[5];
	while(scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy)!=EOF){
		ab=distance(ax,ay,bx,by);
		bc=distance(bx,by,cx,cy);
		ca=distance(cx,cy,ax,ay);
		vabx=bx-ax;
		vaby=by-ay;
		vacx=cx-ax;
		vacy=cy-ay;
		acdotab=vabx*vacx+vaby*vacy;
		x=0.5*(pow(ab*ca,2)-pow(ca,2)*acdotab)/(pow(ab*ca,2)-pow(acdotab,2));
		y=0.5*(pow(ca*ab,2)-pow(ab,2)*acdotab)/(pow(ca*ab,2)-pow(acdotab,2));
		vaox=x*vabx+y*vacx;
		vaoy=x*vaby+y*vacy;
		ox=ax+vaox;
		oy=ay+vaoy;
		s=(ab+bc+ca)/2.0;
		area=sqrt(s*(s-ab)*(s-bc)*(s-ca));
		r=ab*bc*ca/(4.0*area);
		if(ox<0)
			sprintf(operax,"%s"," + ");
		else
			sprintf(operax,"%s"," - ");
		if(oy<0)
			sprintf(operay,"%s"," + ");
		else
			sprintf(operay,"%s"," - ");
		printf("(x%s",operax);
		printf("%.3lf",fabs(ox));
		printf(")^2 + (y%s",operay);
		printf("%.3lf",fabs(oy));
		printf(")^2 = %.3lf^2\n",r);
		printf("x^2 + y^2%s",operax);
		printf("%.3lfx",2*fabs(ox));
		printf("%s",operay);
		printf("%.3lfy",2*fabs(oy));
		printf("%s%.3lf",ox*ox+oy*oy-r*r>0?" + ":" - ",fabs(ox*ox+oy*oy-r*r));
		printf(" = 0\n\n");
	}
	return 0;
}
double distance(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
