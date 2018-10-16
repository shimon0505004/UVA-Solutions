#include<stdio.h>
#include<math.h>
#define EPS 1e-6
char issquare(int n){
	int t=(int)sqrt(n);
	if(fabs(t*t-n)<EPS) return 1;
	return 0;
}
int main(){
	int cases,N,in=0,i,j;
	int answer[55],top[55];
	for(i=1;in<55;i++){
		for(j=0;j<in;j++)
			if(issquare(i+top[j])){
				top[j]=i;
				break;
			}
		if(j==in) top[in++]=i;
		answer[in]=i;
	}
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		printf("%d\n",answer[N]);
	}
	return 0;
}
