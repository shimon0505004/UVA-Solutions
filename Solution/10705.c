#include<stdio.h>
int main(){
	int cases,k,i;
	long long N;
	unsigned long long U,L,t;
	char pn[70];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%s%lld",&k,&pn,&N);
		L=U=0;
		for(i=0;i<k;i++){
			U<<=1,L<<=1;
			if(pn[i]=='p') U++;
			else L++;
		}
		if(N>0&&N>U) puts("Impossible");
		else if(N<0&&(unsigned long long)(-N)>L) puts("Impossible");
		else{
			N+=L,N^=L;
			for(t=1LLU<<(k-1);t>0;t>>=1)
				if(N&t) putchar('1');
				else putchar('0');
			puts("");
		}
	}
	return 0;
}
