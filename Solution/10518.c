#include<stdio.h>
int main(){
	int cases,b,i,tmp1,tmp2,t,circle[10005],loop;
	long long n;
	for(cases=1;scanf("%lld%d",&n,&b),b;cases++){
		printf("Case %d: %lld %d",cases,n,b);
		if(b==1){
			puts(" 0");
			continue;
		}else if(b==2){
			puts(" 1");
			continue;
		}else if(n==0){
			puts(" 1");
			continue;
		}
		tmp1=1,tmp2=1;
		for(i=2;i<n+1;i++){
			t=(tmp1+tmp2+1)%b;
			tmp1=tmp2,tmp2=t;
			if(tmp1==1&&tmp2==1) break;
		}
		loop=i-1;
		if(i<n){
			n%=loop;
			tmp1=1,tmp2=1;
			for(i=2;i<n+1;i++){
				t=(tmp1+tmp2+1)%b;
				tmp1=tmp2,tmp2=t;
				if(tmp1==1&&tmp2==1) break;
			}
			printf(" %d\n",tmp2);
		}
		else printf(" %d\n",tmp2);
	}
	return 0;
}
