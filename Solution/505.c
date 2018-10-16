#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int days_of_month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
char *day_of_week[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
char *month_of_year[12]={"JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};
struct TIME{
	int day,date;
	int year,month;
	int hour,min,sec;
	int timezone;
};
int getDay(char day[]){
	int n;
	for(n=0;strcmp(day_of_week[n],day);n++);
	return n;
}
int getMonth(char month[]){
	int n;
	for(n=0;strcmp(month_of_year[n],month);n++);
	return n;
}
int getYear(char year[]){
	if(strlen(year)==2) return 1900+atoi(year);
	return atoi(year);
}
int getTimezone(char timezone[]){
	int res;
	if(strcmp(timezone,"UT")==0) return 0;
	if(strcmp(timezone,"GMT")==0) return 0;
	if(strcmp(timezone,"EDT")==0) return -240;
	if(strcmp(timezone,"CDT")==0) return -300;
	if(strcmp(timezone,"MDT")==0) return -360;
	if(strcmp(timezone,"PDT")==0) return -420;
	res=((timezone[1]-'0')*10+timezone[2]-'0')*60+((timezone[3]-'0')*10+timezone[4]-'0');
	if(*timezone=='-') res*=-1;
	return res;
}
int is_leap(struct TIME *t){
	if(t->month!=1) return 0;
	if(t->year%400==0) return 1;
	if(t->year%100==0) return 0;
	if(t->year%4==0) return 1;
	return 0;
}
int main(){
	char day[5],month[5],year[5],timezone[10];
	struct TIME t;
	while(scanf("%3s%*c%d%s%s%d%*c%d%*c%d%s",day,&t.date,month,year,&t.hour,&t.min,&t.sec,timezone)==8){
		t.day=getDay(day);
		t.month=getMonth(month);
		t.year=getYear(year);
		t.timezone=getTimezone(timezone);
		t.min+=180-t.timezone+1440,t.date--,t.day--;
		t.hour+=t.min/60,t.min%=60;
		t.date+=t.hour/24,t.day+=t.hour/24,t.hour%=24;
		t.day%=7;
		if(t.date==0){
			if(t.month==0){
				t.date=31;
				t.month=11,t.year--;
			}else{
				t.date=days_of_month[--t.month];
				t.date+=is_leap(&t);
			}
		}else if(t.date>days_of_month[t.month]+is_leap(&t)){
			t.date=1;
			if(t.month==11) t.month=0,t.year++;
			else t.date=1,t.month++;
		}
		printf("%s, %.2d %s %.4d %.2d:%.2d:%.2d +0300\n",day_of_week[t.day],t.date,month_of_year[t.month],t.year,t.hour,t.min,t.sec);
	}
	return 0;
}
