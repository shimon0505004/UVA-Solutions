#include<stdio.h>
int main(){
	int N;
	int Catalan[11]={1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796};
	char start=0;
	while(scanf("%d",&N)==1){
		if(start) puts("");
		else start=1;
		printf("%d\n",Catalan[N]);
	}
	return 0;
}
