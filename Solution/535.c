#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi 3.14159265358979323846
#define R 6378
#define SQR(x) ((x)*(x))
struct CITY{
	char name[35];
	double lat,lon;
};
int find_name(struct CITY c[],char name[],int n_city){
	int n;
	for(n=0;strcmp(c[n].name,name)&&n<n_city;n++);
	return n;
}
int distance(struct CITY *c1,struct CITY *c2){
	double x1,y1,z1,x2,y2,z2;
	double line_dis;
	x1=R*cos(c1->lat)*cos(c1->lon);
	y1=R*cos(c1->lat)*sin(c1->lon);
	z1=R*sin(c1->lat);
	x2=R*cos(c2->lat)*cos(c2->lon);
	y2=R*cos(c2->lat)*sin(c2->lon);
	z2=R*sin(c2->lat);
	line_dis=sqrt(SQR(x1-x2)+SQR(y1-y2)+SQR(z1-z2));
	return (int)floor(R*acos((2*SQR(R)-SQR(line_dis))/(2*SQR(R)))+0.5);
}
int main(){
	int n_city,i,j;
	char city1[35],city2[35];
	int dis[105][105];
	struct CITY cities[105];
	for(n_city=0;scanf("%s",cities[n_city].name),*(cities[n_city].name)!='#';n_city++){
		scanf("%lf%lf",&cities[n_city].lat,&cities[n_city].lon);
		cities[n_city].lat*=pi/180,cities[n_city].lon*=pi/180;
	}
	for(i=0;i<n_city;i++)
		for(j=0;j<i;j++)
			dis[i][j]=dis[j][i]=distance(&cities[i],&cities[j]);
	while(scanf("%s%s",city1,city2),*city1!='#'&&*city2!='#'){
		int c1=find_name(cities,city1,n_city),c2=find_name(cities,city2,n_city);
		printf("%s - %s\n",city1,city2);
		if(c1==n_city||c2==n_city) puts("Unknown");
		else printf("%d km\n",dis[c1][c2]);
	}
	return 0;
}
