#include<stdio.h>
typedef struct POINT{
	long long x,y;
}Point;
long long myabs(long long n){
	if(n<0) return -n;
	return n;
}
long long doublearea(Point p[],int n){
	int i;
	long long sum=0;
	for(i=0;i<n-1;i++)
		sum+=p[i].x*p[i+1].y-p[i].y*p[i+1].x;
	sum+=p[n-1].x*p[0].y-p[n-1].y*p[0].x;
	return myabs(sum);
}
long long gcd(long long a,long long b){
	long long temp;
	if(a==0||b==0) return a+b;
	while(a%b!=0)
		temp=a,a=b,b=temp%b;
	return b;
}
int main(){
	Point p[1005];
	int n,i;
	long long gridp,area;
	while(scanf("%d",&n),n){
		for(i=0;i<n;i++)
			scanf("%lld%lld",&p[i].x,&p[i].y);
		area=doublearea(p,n);
		gridp=0;
		for(i=0;i<n-1;i++)
			gridp+=gcd(myabs(p[i].x-p[i+1].x),myabs(p[i].y-p[i+1].y));
		gridp+=gcd(abs(p[n-1].x-p[0].x),abs(p[n-1].y-p[0].y));
		printf("%lld\n",(area+2-gridp)/2);
	}
	return 0;
}
