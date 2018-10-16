#include<stdio.h>
long long sum_Last_non_zero_Digit(int n){
	long long result=(long long)n/10*45;
	int i,ln;
	if(n==0) return 0;
	ln=n%10;
	for(i=1;i<=ln;i++) result+=i;
	return result+sum_Last_non_zero_Digit(n/10);
}
int main(){
	int p,q;
	while(scanf("%d%d",&p,&q),p!=-1||q!=-1)
		printf("%lld\n",sum_Last_non_zero_Digit(q)-sum_Last_non_zero_Digit(p-1));
	return 0;
}
