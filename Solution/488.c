#include<stdio.h>
#include<stdlib.h>
int main(){
	int times,Amp,Fre,k,l;
	scanf("%d",&times);
	while(times--){
		scanf("%d%d",&Amp,&Fre);
		while(Fre--){
			for(l=Amp-1;l>=1-Amp;l--){
				for(k=0;k<Amp-abs(l);k++)
					printf("%d",Amp-abs(l));
				puts("");
			}
			if(Fre) puts("");
		}
		if(times) puts("");
	}
	return 0;
}
