#include<stdio.h>
int main(){
	int T,cases,i,j,t,inf,sup;
	int Kaprekar[20],n_Kaprekar=0;
	for(i=2;i<40005;i++){
		t=i*i;
		for(j=10;j<=100000000&&j<=t;j*=10){
			if(t%j+t/j==i&&t%j!=0&&t/j!=0){
				Kaprekar[n_Kaprekar++]=i;
				break;
			}
		}
	}
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		if(cases>1) puts("");
		printf("case #%d\n",cases);
		scanf("%d%d",&inf,&sup);
		for(i=0;i<n_Kaprekar&&Kaprekar[i]<inf;i++);
		if(i==n_Kaprekar) puts("no kaprekar numbers");
		else{
			for(j=i;j<n_Kaprekar&&Kaprekar[j]<=sup;j++)
				printf("%d\n",Kaprekar[j]);
			if(i==j) puts("no kaprekar numbers");
		}
	}
	return 0;
}
