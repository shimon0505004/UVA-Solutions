#include<stdio.h>
#include<string.h>
int main(){
	int h=0,m=0,s=0;
	int speed=0,tmpspeed,elapsed=0;
	double distance=0;
	char input[20];
	while(fgets(input,20,stdin)!=NULL){
		if(sscanf(input,"%d%*c%d%*c%d%d",&h,&m,&s,&tmpspeed)==4){
			distance+=(double)speed*((h*3600+m*60+s)-elapsed)/3600;
			speed=tmpspeed;
			elapsed=h*3600+m*60+s;
		}else{
			distance+=(double)speed*((h*3600+m*60+s)-elapsed)/3600;
			printf("%.2d:%.2d:%.2d %.2lf km\n",h,m,s,distance);
			elapsed=h*3600+m*60+s;
		}
	}
	return 0;
}
