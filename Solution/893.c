#include<stdio.h>
char is_leap(int year)
{
	if(year%4)
		return 0;
	else
		if(!(year%400))
			return 1;
		else if(!(year%100))
			return 0;
		else
			return 1;
}
char needleap(int year,int month,int day)
{
	if(month*31+day<60)
		if(is_leap(year)) return 1;
		else return 0;
	else 
		if(is_leap(year+1)) return 1;
		else return 0;
}
int main()
{
	int monthday[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	int yearday[2]={365,366};
	int days,dd,mm,yy,i;
	while(scanf("%d%d%d%d",&days,&dd,&mm,&yy)==4&&(days+dd+mm+yy)){
		yy+=(days/(400*365+100-3))*400;
		days%=(400*365+100-3);
		while(days>=yearday[needleap(yy,mm,dd)])
			days-=yearday[needleap(yy++,mm,dd)];
		while(days>=monthday[is_leap(yy)][mm]){
			days-=monthday[is_leap(yy)][mm];
			if(++mm>12) yy++,mm=1;
		}
		while((dd+days)>monthday[is_leap(yy)][mm]){
			dd=(dd+days)-monthday[is_leap(yy)][mm];
			days=0;
			if(++mm>12) yy++,mm=1;
		}
		dd+=days;
		printf("%d %d %d\n",dd,mm,yy);
	}
	return 0;
}
