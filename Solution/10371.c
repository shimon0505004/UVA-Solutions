#include<stdio.h>
#include<string.h>
struct TIMEZONE{
	char name[5];
	int offset;
}zone[32]={
	{"UTC",0},{"GMT",0},{"BST",2},{"IST",2},{"WET",0},{"WEST",2},{"CET",2},{"CEST",4},
	{"EET",4},{"EEST",6},{"MSK",6},{"MSD",8},{"AST",40},{"ADT",42},{"NST",41},{"NDT",43},
	{"EST",38},{"EDT",40},{"CST",36},{"CDT",38},{"MST",34},{"MDT",36},{"PST",32},{"PDT",34},
	{"HST",28},{"AKST",30},{"AKDT",32},{"AEST",20},{"AEDT",22},{"ACST",19},{"ACDT",21},{"AWST",16}
};
int zone_diff(char z1[],char z2[]){
	int i,iz1,iz2;
	for(i=0;i<32;i++){
		if(strcmp(zone[i].name,z1)==0) iz1=i;
		if(strcmp(zone[i].name,z2)==0) iz2=i;
	}
	return ((zone[iz2].offset-zone[iz1].offset+48)%48)*30;
}
int getTime(){
	char t[10],apm[10];
	int h,m;
	scanf("%s",t);
	if(strcmp(t,"noon")==0) return 12*60;
	if(strcmp(t,"midnight")==0) return 0;
	sscanf(t,"%d%*c%d",&h,&m);
	if(h==12) h=0;
	scanf("%s",apm);
	if(*apm=='a') return h*60+m;
	return (h+12)*60+m;
}
void printTime(int time){
	int h,m;
	time%=24*60;
	if(time==0) puts("midnight");
	else if(time==12*60) puts("noon");
	else{
		h=time/60,m=time%60;
		if(h>=12){
			if(h>12) h-=12;
			printf("%d:%.2d p.m.\n",h,m);
		}else{
			if(h==0) h=12;
			printf("%d:%.2d a.m.\n",h,m);
		}
	}
	
}
int main(){
	int cases;
	char z1[5],z2[5];
	scanf("%d",&cases);
	while(cases--){
		int t=getTime();
		int difference;
		scanf("%s%s",z1,z2);
		difference=zone_diff(z1,z2);
		printTime(t+difference);
	}
	return 0;
}
