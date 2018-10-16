#include<stdio.h>
struct FRAC{
	long long num,den;
	long long integer;
};
long long gcd(long long a,long long b){
	long long temp;
	while(a%b)
		temp=a,a=b,b=temp%a;
	return b;
}
void reduce(struct FRAC *f){
	long long g;
	f->integer+=f->num/f->den;
	f->num%=f->den;
	g=gcd(f->num,f->den);
	f->num/=g,f->den/=g;
	return;
}
void printFrac(struct FRAC *f){
	char foo[100],dash[25]="------------------------";
	int len=sprintf(foo,"%lld",f->integer)+1;
	dash[sprintf(foo,"%lld",f->den)]=0;
	if(f->num==0)
		printf("%lld\n",f->integer);
	else{
		printf("%*s%lld\n",len,"",f->num);
		printf("%lld %s\n",f->integer,dash);
		printf("%*s%lld\n",len,"",f->den);
	}
}
int main(){
	int i,j,n;
	struct FRAC ans[34];
	ans[1].integer=1,ans[1].num=0,ans[1].den=1;
	for(i=2;i<34;i++){
		ans[i].integer=ans[i-1].integer+1;
		ans[i].den=ans[i-1].den*(i-1);
		ans[i].num=ans[i-1].integer*ans[i-1].den+ans[i-1].num*i;
		reduce(ans+i);
	}
	while(scanf("%lld",&n)==1)
		printFrac(ans+n);
	return 0;
}
