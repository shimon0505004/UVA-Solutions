#include<stdio.h>
#include<math.h>
struct FLOAT_POINT{
	int expo;
	long double mantissa;
};
void multiply(struct FLOAT_POINT *dest,int n){
	dest->mantissa*=(long double)n;
	if(dest->mantissa<1e-1)
		while(dest->mantissa<1e-1) dest->mantissa*=10,dest->expo--;
	else if(dest->mantissa>1)
		while(dest->mantissa>1) dest->mantissa/=10,dest->expo++;
}
void divide(struct FLOAT_POINT *dest,int n){
	dest->mantissa/=(long double)n;
	if(dest->mantissa<1e-1)
		while(dest->mantissa<1e-1) dest->mantissa*=10,dest->expo--;
	else if(dest->mantissa>1)
		while(dest->mantissa>1) dest->mantissa/=10,dest->expo++;
}
int main(){
	int p,q,r,s,i;
	struct FLOAT_POINT comb;
	long double result;
	while(scanf("%d%d%d%d",&p,&q,&r,&s)==4){
		if(2*q>p) q=p-q;
		if(2*s>r) s=r-s;
		comb.mantissa=(long double)1;
		comb.expo=0;
		for(i=1;i<=q;i++) multiply(&comb,p-i+1),divide(&comb,i);
		for(i=1;i<=s;i++) divide(&comb,r-i+1),multiply(&comb,i);
		result=comb.mantissa;
		result*=pow(10,comb.expo);
		printf("%.5LF\n",result);
	}
	return 0;
}
