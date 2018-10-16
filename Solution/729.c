#include<stdio.h>
int main()
{
	int cases,i,k,start=0;
	int N,H,j,hamming,test;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&N,&H);
		if(start) printf("\n");
		start=1;
		for(j=0;j<(1<<N);j++){
			hamming=0;
			for(k=0;k<N;k++)
				if((j>>k)&1){
					hamming++;
					if(hamming>H)
						break;
				}
			if(hamming==H){
				test=1<<N;
				for(k=0;k<N;k++){
					test>>=1;
					if(j&test)
						printf("1");
					else
						printf("0");
				}
				printf("\n");
			}
		}
	}
	return 0;
}
