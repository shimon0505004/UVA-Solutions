#include<stdio.h>
#include<stdlib.h>
struct SCHEDULE{
	int start,end,during;
};
int compar(const void *a,const void *b){
	struct SCHEDULE *s1=(struct SCHEDULE *)a,*s2=(struct SCHEDULE *)b;
	return s1->start-s2->start;
}
int main(){
	int DAY=0,i,h1,m1,h2,m2,NapTime,NapStart;
	int schedule;
	struct SCHEDULE s[105];
	char detail[255];
	while(scanf("%d",&schedule)==1){
		for(i=0;i<schedule;i++){
			scanf("%d%*c%d%d%*c%d%[^\n]",&h1,&m1,&h2,&m2,detail);
			s[i].start=h1*60+m1;
			s[i].end=h2*60+m2;
			s[i].during=s[i].end-s[i].start;
		}
		qsort(s,schedule,sizeof(struct SCHEDULE),compar);
		NapTime=s[0].start-600;
		NapStart=600;
		for(i=1;i<schedule;i++)
			if(NapTime<s[i].start-s[i-1].end)
				NapTime=s[i].start-s[i-1].end,NapStart=s[i-1].end;
		if(NapTime<1080-s[schedule-1].end)
			NapTime=1080-s[schedule-1].end,NapStart=s[schedule-1].end;
		printf("Day #%d: the longest nap starts at %.2d:%.2d and will last for ",++DAY,NapStart/60,NapStart%60);
		if(NapTime>=60) printf("%d hours and ",NapTime/60);
		printf("%d minutes.\n",NapTime%60);
	}
	return 0;
}
