#include<stdio.h>
enum STATUS{UNKNOWN,UP,DOWN};
int main(){
	int seq[35],n,i;
	int UPtimes,DOWNtimes,UPruns,DOWNruns,runs;
	double U,D;
	enum STATUS status;
	while(n=0,scanf("%d",&seq[n++]),seq[0]){
		while(scanf("%d",&seq[n]),seq[n++]);
		n--;
		UPtimes=DOWNtimes=UPruns=DOWNruns=runs=0;
		status=UNKNOWN;
		for(i=1;i<n;i++){
			if(status==UNKNOWN){
				if(seq[i]>seq[i-1]) status=UP;
				else if(seq[i]<seq[i-1]) status=DOWN;
				runs++;
			}else if(status==UP){
				if(seq[i]>=seq[i-1]) runs++;
				else{
					UPruns+=runs,UPtimes++;
					status=DOWN;
					runs=1;
				}
			}else{
				if(seq[i]<=seq[i-1]) runs++;
				else{
					DOWNruns+=runs,DOWNtimes++;
					status=UP;
					runs=1;
				}
			}
		}
		if(status==UP) UPruns+=runs,UPtimes++;
		else if(status==DOWN) DOWNruns+=runs,DOWNtimes++;
		U=D=0;
		if(UPtimes) U=(double)UPruns/UPtimes;
		if(DOWNtimes) D=(double)DOWNruns/DOWNtimes;
		printf("Nr values = %d:  %.6lf %.6lf\n",n,U,D);
	}
	return 0;
}
