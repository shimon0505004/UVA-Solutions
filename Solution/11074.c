#include<stdio.h>
int main(){
	int S,T,N,cases;
	int i,j,k,l,W;
	for(cases=1;scanf("%d%d%d",&S,&T,&N),S|T|N;cases++){
		W=S*N+T*(N+1);
		printf("Case %d:\n",cases);
		for(i=0;i<T;i++,puts(""))
			for(j=0;j<W;j++)
				putchar('*');
		for(i=0;i<N;i++){
			for(j=0;j<S;j++,puts("")){
				for(k=0;k<T;k++) putchar('*');
				for(k=0;k<N;k++){
					for(l=0;l<S;l++) putchar('.');
					for(l=0;l<T;l++) putchar('*');
				}
			}
			for(j=0;j<T;j++,puts(""))
				for(k=0;k<W;k++)
					putchar('*');
		}
		puts("");
	}
	return 0;
}
