#include<stdio.h>
#include<math.h>
int pow_n(int n,int k){
	int t,now=n;
	int rem=1;
	for(t=1;t<=k;t<<=1){
		if(t&k) rem=(rem*now)%1000;
		now=(now*now)%1000;
	}
	return rem;
}
int main(){
	int T,n,k;
	double logarithm;
	int head3,tail3;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		logarithm=k*log10(n);
		logarithm-=floor(logarithm)-2;
		head3=(int)(pow(10,logarithm));
		tail3=pow_n(n%1000,k);
		printf("%.3d...%.3d\n",head3,tail3);
	}
	return 0;
}
