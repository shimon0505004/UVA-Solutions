#include<stdio.h>
#include<string.h>
int main(){
	int N,cases,i,j;
	double L[10];
	int G[10],Y[10],R[10],cycle[10];
	char valid[65],exist,start;
	for(cases=1;scanf("%d",&N),N>=0;cases++){
		printf("Case %d:",cases);
		for(i=0;i<N;i++){
			scanf("%lf%d%d%d",&L[i],&G[i],&Y[i],&R[i]);
			cycle[i]=G[i]+Y[i]+R[i];
		}
		memset(valid,0,sizeof(valid));
		exist=0;
		for(i=30;i<=60;i++){
			for(j=0;j<N;j++){
				double duration=L[j]*3600/i;
				duration-=(int)(duration/cycle[j])*cycle[j];
				if(duration>G[j]+Y[j]) break;
			}
			if(j==N) valid[i]=valid[i-1]+1,exist=1;
		}
		if(exist){
			start=0;
			for(i=30;i<=60;i++){
				if(valid[i+1]==0&&valid[i]!=0){
					if(valid[i]==1){
						if(start) printf(",");
						printf(" %d",i);
						start=1;
					}else{
						if(start) printf(",");
						printf(" %d-%d",i-valid[i]+1,i);
						start=1;
					}
				}
			}
			puts("");
		}else puts(" No acceptable speeds.");
	}
	return 0;
}
