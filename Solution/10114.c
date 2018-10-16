#include<stdio.h>
int main(){
	int months,deps,prev,next,i;
	double down_payment,loan,car_value,d,pay;
	double depreciation[105];
	while(scanf("%d%lf%lf%d",&months,&down_payment,&loan,&deps),months>=0){
		scanf("%d",&prev);
		while(--deps){
			scanf("%lf%d",&d,&next);
			for(i=prev;i<next;i++) depreciation[i]=d;
			prev=next;
		}
		scanf("%lf",&d);
		for(i=prev;i<=months;i++) depreciation[i]=d;
		pay=loan/months;
		car_value=(down_payment+loan)*(1-depreciation[0]);
		for(i=0;car_value<loan;){
			loan-=pay;
			car_value*=(1-depreciation[++i]);
		}
		if(i==1) puts("1 month");
		else printf("%d months\n",i);
	}
	return 0;
}
