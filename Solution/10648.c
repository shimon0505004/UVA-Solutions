#include<stdio.h>
#include<math.h>
int main(){
	int n,m,i,j,cases=0;
	double result,p;
	double fac_log[105];
	for(fac_log[1]=0,i=2;i<105;i++)
		fac_log[i]=fac_log[i-1]+log(i);
	for(cases=1;scanf("%d%d",&n,&m),n>=0;cases++){
		result=0;
		for(i=1;i<m;i++){
			p=exp(fac_log[m]-fac_log[i]-fac_log[m-i]+(log(m-i)-log(m))*n);
			if(i&1) result+=p;
			else result-=p;
		}
		printf("Case %d: %.7lf\n",cases,result);
	}
	return 0;
}
