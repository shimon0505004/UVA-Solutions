#include<stdio.h>
void cal(int p,int q,int n,long long *result){
	int i;
	long long t,m;
	long long foo,bar;
	if(n==0) *result=2;
	else if(n==1) *result=p;
	else if(n%2==0){
		t=(cal(p,q,n/2,&foo),foo),m=1;
		for(i=0;i<n/2;i++)
			m*=q;
		*result=t*t-2*m;
	}else
		*result=(cal(p,q,n-1,&foo),foo)*p-(cal(p,q,n-2,&bar),bar)*q;
}
int main()
{
	int p,q,n;
	long long result;
	while(scanf("%d%d%d",&p,&q,&n)==3){
		if(p==2&&q==1) puts("2");
		else if(p==1&&q==0) puts("1");
		else if(p==0&&q==0) puts("0");
		else{
			if(p==0&&q==1) n%=4;
			cal(p,q,n,&result);
			printf("%lld\n",result);
		}
	}
	return 0;
}
