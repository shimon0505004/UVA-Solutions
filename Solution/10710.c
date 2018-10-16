#include<stdio.h>
int Mod(int a,int p,int modulus){
	long long result;
	if(p==1) return a%modulus;
	if(p%2==0){
		result=Mod(a,p/2,modulus);
		return (int)((result*result)%modulus);
	}
	return ((long long)a*Mod(a,p-1,modulus))%modulus;
}
int main(){
	int n;
	while(scanf("%d",&n),n>0){
		if(n%2==0) printf("%d is not a Jimmy-number\n",n);
		else if(Mod(2,n-1,n)==1) printf("%d is a Jimmy-number\n",n);
		else printf("%d is not a Jimmy-number\n",n);
	}
	return 0;
}
