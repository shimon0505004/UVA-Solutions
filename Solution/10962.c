#include<stdio.h>
struct GARBAGE{
	double amount,offset;
};
int main(){
	int cases,s,g,N,C,i;
	struct GARBAGE garbage[2005];
	double t,R,r;
	scanf("%d",&cases);
	while(cases--){
		scanf("%lf%lf%d%d",&R,&r,&N,&C);
		t=0;
		for(i=0;i<N;i++){
			scanf("%d%d",&s,&g);
			t+=(double)g/R;
			garbage[i].amount=(double)s-g,garbage[i].offset=t;
		}
		for(i=0;i<N-1;i++)
			if(garbage[i].amount/r+garbage[i].offset>garbage[i+1].offset)
				garbage[i+1].amount+=garbage[i].amount-(garbage[i+1].offset-garbage[i].offset)*r;
		i=-1;
		while(C--){
			scanf("%lf",&t);
			for(;i<N-1&&garbage[i+1].offset<t+1e-5;i++);
			if(i==-1) puts("clear");
			else{
				if(garbage[i].offset+garbage[i].amount/r+1e-5>t) puts("full");
				else puts("clear");
			}
		}
		if(cases) puts("");
	}
	return 0;
}
