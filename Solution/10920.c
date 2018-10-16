#include<stdio.h>
#include<math.h>
int main(){
	int SZ,P,k,L,C;
	while(scanf("%d%d",&SZ,&P),SZ+P){
		SZ=(SZ+1)>>1;
		k=((int)sqrt(P)-1)/2;
		L=SZ+k,C=SZ+k,P-=((k<<1)+1)*((k<<1)+1);
		if(P==0){
			printf("Line = %d, column = %d.\n",L,C);
			continue;
		}
		k++;
		L=SZ+k,C=SZ+k;
		if(P<=(k<<1)){
			printf("Line = %d, column = %d.\n",L,C-P);
			continue;
		}
		P-=(k<<1);
		L=SZ+k,C=SZ-k;
		if(P<=(k<<1)){
			printf("Line = %d, column = %d.\n",L-P,C);
			continue;
		}
		P-=(k<<1);
		L=SZ-k,C=SZ-k;
		if(P<=(k<<1)){
			printf("Line = %d, column = %d.\n",L,C+P);
			continue;
		}
		P-=(k<<1);
		L=SZ-k,C=SZ+k;
		printf("Line = %d, column = %d.\n",L+P,C);
	}
	return 0;
}
