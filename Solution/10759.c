#include<stdio.h>
long long GCD(long long a,long long b){
	long long temp;
	while((a/b)*b!=a)
		temp=a,a=b,b=temp-temp/b*b;
	return b;
}
int main(){
	long long sixpow[25]={0LL,6LL,36LL,216LL,1296LL,7776LL,46656LL,279936LL,1679616LL,10077696LL,60466176LL,362797056LL,2176782336LL,13060694016LL,78364164096LL,470184984576LL,2821109907456LL,16926659444736LL,101559956668416LL,609359740010496LL,3656158440062976LL,21936950640377856LL,131621703842267136LL,789730223053602816LL,4738381338321616896LL};
	long long table[25][151]={0},num,den,gcd;
	int i,j,k,n,x;
	for(i=1;i<=6;i++) table[1][i]=1;
	for(i=2;i<=24;i++)
		for(j=150;j>=i;j--)
			for(k=j-6>0?j-6:1;k<j;k++)
				table[i][j]+=table[i-1][k];
	for(i=1;i<=24;i++)
		for(j=149;j>=0;j--)
			table[i][j]+=table[i][j+1];
	while(scanf("%d%d",&n,&x),n+x){
		num=table[n][x];
		den=sixpow[n];
		gcd=GCD(num,den);
		printf("%lld",num/gcd);
		if(den/gcd>1) printf("/%lld",den/gcd);
		puts("");
	}
	return 0;
}
