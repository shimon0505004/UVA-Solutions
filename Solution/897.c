#include<stdio.h>
int cal_digit(int n){
	int i;
	for(i=0;n;i++,n/=10);
	return i;
}
int main(){
	int n,i;
	int ana_prime[22]={2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
	while(scanf("%d",&n),n){
		for(i=0;i<22&&n>=ana_prime[i];i++);
		if(i==22) puts("0");
		else if(cal_digit(ana_prime[i])==cal_digit(n)) printf("%d\n",ana_prime[i]);
		else puts("0");
	}
	return 0;
}
