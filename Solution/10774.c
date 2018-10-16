#include<stdio.h>
int main(){
	int T,cases,n,n_one,first_zero;
	int t,d;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d",&n);
		first_zero=-1,n_one=0;
		for(d=0,t=1;t<=n;t<<=1,d++){
			if((t&n)==0){
				if(first_zero==-1) first_zero=d;
			}else n_one++;
		}
		printf("Case %d: %d %d\n",cases,n_one-first_zero,(1<<n_one)-1);
	}
	return 0;
}
