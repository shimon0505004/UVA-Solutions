#include<stdio.h>
#include<math.h>
#define pi 3.14159265358979323846
struct LAT_LON{
	double lat,lon;
};
double distance(struct LAT_LON *p1,struct LAT_LON *p2){
	double x1,y1,z1,x2,y2,z2;
	double lat1=p1->lat*pi/180,lon1=p1->lon*pi/180;
	double lat2=p2->lat*pi/180,lon2=p2->lon*pi/180;
	x1=cos(lat1)*cos(lon1);
	y1=cos(lat1)*sin(lon1);
	z1=sin(lat1);
	x2=cos(lat2)*cos(lon2);
	y2=cos(lat2)*sin(lon2);
	z2=sin(lat2);
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2);
}
int main(){
	int n,i,j,mini;
	struct LAT_LON pos[1005];
	double max_dis[1005],min;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++) scanf("%lf%lf",&pos[i].lat,&pos[i].lon);
		for(i=0;i<n;i++) max_dis[i]=0;
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				double d=distance(&pos[i],&pos[j]);
				if(d>max_dis[i]) max_dis[i]=d;
				if(d>max_dis[j]) max_dis[j]=d;
			}
		}
		min=max_dis[0],mini=0;
		for(i=1;i<n;i++) if(min>max_dis[i]||fabs(max_dis[i]-min)<1e-6) min=max_dis[i],mini=i;
		printf("%.2lf %.2lf\n",pos[mini].lat,pos[mini].lon);
	}
	return 0;
}
