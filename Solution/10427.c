#include<stdio.h>
int main(){
	int N,d,pos;
	const int ten[8]={1,10,100,1000,10000,100000,1000000,10000000};
	const int digits[9]={1,10,190,2890,38890,488890,5888890,68888890,788888890};
	while(scanf("%d",&N)==1){
		N++;
		for(d=0;d<9;d++)
			if(N<=digits[d]) break;
		N-=digits[d-1];
		pos=(d-(N%d))%d;
		N=(N-1)/d+ten[d-1];
		printf("%d\n",N/ten[pos]%10);
	}
	return 0;
}
