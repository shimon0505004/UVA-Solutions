#include<stdio.h>
int main()
{
	double Ncows,Ncars,Nshow,p;
	while(scanf("%lf%lf%lf",&Ncows,&Ncars,&Nshow)==3){
		p=(Ncows/(Ncows+Ncars))*(Ncars/(Ncows+Ncars-1-Nshow))+(Ncars/(Ncows+Ncars))*((Ncars-1)/(Ncars+Ncows-1-Nshow));
		printf("%.5lf\n",p);
	}
	return 0;
}
