#include<stdio.h>
#define SECPERYEAR 	(31536000)
#define SECPERDAY 	(86400)
#define SECPERHOUR 	(3600)
#define SECPERMIN 	(60)
int main(){
	int daypermonth[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	int year1,month1,day1,hour1,min1,sec1;
	int year2,month2,day2,hour2,min2,sec2;
	int block,ans;
	char unit[10];
	while(scanf("%d",&year1)==1){
		scanf("%d%d%d%d%d",&month1,&day1,&hour1,&min1,&sec1);
		scanf("%d%d%d%d%d%d",&year2,&month2,&day2,&hour2,&min2,&sec2);
		scanf("%d%s",&block,unit);
		if(*unit=='y'){
			if(month1!=1||day1!=1||hour1!=0||min1!=0||sec1!=0) year1++;
			ans=year2-year1;
		}else if(*unit=='m'&&*(unit+1)=='o'){
			if(day1!=1||hour1!=0||min1!=0||sec1!=0) month1++;
			ans=(year2-year1)*12+month2-month1;
		}else{
			if(*unit=='d'){
				if(hour1!=0||min1!=0||sec1!=0) day1++;
				hour1=min1=sec1=0;
			}else if(*unit=='h'){
				if(min1!=0||sec1!=0) hour1++;
				min1=sec1=0;
			}else if(*unit=='m'){
				if(sec1!=0) min1++;
				sec1=0;
			}
			ans=(year2-year1)*SECPERYEAR;
			ans+=(daypermonth[month2-1]-daypermonth[month1-1]+day2-day1)*SECPERDAY;
			ans+=((year2-1)/4-(year1-1)/4)*SECPERDAY;
			if(year2%4==0&&month2>2) ans+=SECPERDAY;
			if(year1%4==0&&month1>2) ans-=SECPERDAY;
			ans+=(hour2-hour1)*SECPERHOUR;
			ans+=(min2-min1)*SECPERMIN;
			ans+=sec2-sec1;
		}
		if(ans<0) ans=0;
		if(*unit=='y'||(*unit=='m'&&*(unit+1)=='o')) printf("%d\n",ans/block); 
		else if(*unit=='d') printf("%d\n",ans/SECPERDAY/block);
		else if(*unit=='h') printf("%d\n",ans/SECPERHOUR/block);
		else if(*unit=='m') printf("%d\n",ans/SECPERMIN/block);
		else printf("%d\n",ans/block);
	}
	return 0;
}
