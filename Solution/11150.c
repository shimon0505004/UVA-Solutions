#include<stdio.h>
int main(){
	int N,sum;
	while(scanf("%d",&N)==1){
		for(sum=N;N>=3;sum+=N/3,N=N/3+N%3);
		if(N==2) sum++;
		printf("%d\n",sum);
	}
	return 0;
}
