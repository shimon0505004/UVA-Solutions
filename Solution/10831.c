#include<stdio.h>
int main(){
	int index,t;
	long long a,p,mod,rem;
	while(scanf("%lld%lld",&a,&p),a>=0&&p>0){
		if(p<=2||a%p==0){
			puts("Yes");
			continue;
		}
		index=p/2;
		mod=a%p,rem=1;
		for(t=1;t<=index;t<<=1){
			if(t&index) rem=(rem*mod)%p;
			mod=(mod*mod)%p;
		}
		if(rem==1) puts("Yes");
		else puts("No");
	}
	return 0;
}
