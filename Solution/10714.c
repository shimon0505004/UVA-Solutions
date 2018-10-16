#include<stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int cases,i,L,n,ants[1000001],F,S,t;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&L,&n);
		F=S=0;
		for(i=0;i<n;i++){
			scanf("%d",&ants[i]);
			if((t=MIN(L-ants[i],ants[i]))>F) F=t;
			if((t=MAX(L-ants[i],ants[i]))>S) S=t;
		}
		printf("%d %d\n",F,S);
	}
	return 0;
}
