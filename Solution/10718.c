#include<stdio.h>
int main(){
	unsigned N,L,U,M,t;
	int i;
	while(scanf("%u%u%u",&N,&L,&U)==3){
		M=0;
		for(i=31,t=1U<<31;t>0;t>>=1,i--){
			if(!(t&N)){
				if(((M+t)>>i)>=(L>>i)&&((M+t)>>i)<=(U>>i))
					M+=t;
			}else if((M>>i)<(L>>i))
				M+=t;
		}
		printf("%u\n",M);
	}
	return 0;
}
