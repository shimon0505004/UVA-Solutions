#include<stdio.h>
int main(){
	int mon,day,year;
	char *mon_name[]={"",
		"January","February","March","April","May",
		"June","July","August",	"September","October",
		"November","December"};
	char *day_name[]={
		"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
	char isLeap;
	char argu[13]={0,5,1,1,4,6,2,4,0,3,5,1,3};
	int days[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int distance;
	while(scanf("%d%d%d",&mon,&day,&year),mon||day||year){
		if(mon>12||day>days[mon]){
			printf("%d/%d/%d is an invalid date.\n",mon,day,year);
			continue;
		}
		if(year>1752||(year==1752&&mon>9)||(year==1752&&mon==9&&day>=14)){
			isLeap=(year%400==0)?1:((year%100==0)?0:((year%4==0)?1:0));
			if(isLeap==0&&mon==2&&day==29){
				printf("%d/%d/%d is an invalid date.\n",mon,day,year);
				continue;
			}
			distance=(year+(year+3)/4-(year+99)/100+(year+399)/400)%7;
			printf("%s %d, %d is a %s\n",mon_name[mon],day,year,
					day_name[(day+argu[mon]+distance+(mon>2?isLeap:0))%7]);
		}else if(year==1752&&mon==9&&day>2){
			printf("%d/%d/%d is an invalid date.\n",mon,day,year);
		}else{
			isLeap=(year%4==0)?1:0;
			if(isLeap==0&&mon==2&&day==29){
				printf("%d/%d/%d is an invalid date.\n",mon,day,year);
				continue;
			}
			distance=(year+(year+3)/4)%7;
			printf("%s %d, %d is a %s\n",mon_name[mon],day,year,
					day_name[(day+argu[mon]+distance+(mon>2?isLeap:0)+5)%7]);
		}

	}
	return 0;
}
