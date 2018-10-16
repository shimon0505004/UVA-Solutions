#include<stdio.h>
int gcd(long long n1,long long n2){
	long long temp;
	while(n1%n2)
		temp=n1,n1=n2,n2=temp%n2;
	return (int)n2;
}
int main()
{
	int price1,price2,g;
	long long num,box1,box2,temp;
	while(scanf("%lld",&num)==1,num){
		scanf("%d%lld%d%lld",&price1,&box1,&price2,&box2);
		g=gcd(box1,box2);
		if(num%g!=0)
			puts("failed");
		else if(box1>num){
			if(num%box2==0) printf("0 %lld\n",num/box2);
			else puts("failed");
		}else if(box2>num){
			if(num%box1==0) printf("%lld 0\n",num/box1);
			else puts("failed");
		}else{
			long long a=box1,b=box2,p,t,p1,q,b1,b2;
			p=t=0,p1=1;
			while(a%b){
				p*=-(a/b);
				temp=a,a=b,b=temp%b;
				p+=p1,p1=t,t=p;
			}
			b1=box1/b,b2=box2/b;
			p%=b2;
			if(p<0) p+=b2;
			if((double)price1/box1<(double)price2/box2){
				q=(b-p*box1)/box2;
				q=((q%b1)*((num/b)%b1))%b1;
				if(q<0) q+=b1;
				p=(num-q*box2)/box1;
			}else{
				p=((p%b2)*((num/b)%b2))%b2;
				if(p<0) p+=b2;
				q=(num-p*box1)/box2;
			}
			if(p>=0&&q>=0)
				printf("%lld %lld\n",p,q);
			else
				puts("failed");
		}
	}
	return 0;
}
