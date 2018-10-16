#include<stdio.h>
#include<math.h>
int main(){
	int i,cases,N;
	double Clog[100001]={0};
	double ham[50005]={0};
	Clog[1]=0;
	for(i=2;i<100001;i++)
		Clog[i]=Clog[i-1]+log(i);
	for(i=2;i<=50001;i++)
		ham[i]=1-exp(Clog[2*i-2]-2*Clog[i-1]-(2*i-2)*log(2));
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&N);
		if(N==2){
			puts("0.0000");
			continue;
		}
		N>>=1;
		printf("%.4lf\n",ham[N]);
	}
	return 0;
}
