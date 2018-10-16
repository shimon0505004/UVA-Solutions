#include<stdio.h>
#include<string.h>
#include<math.h>
#define pi 3.14159265358979323846
#define R 6378
#define sqr(a) ((a)*(a))
struct LOC{
	double lat,lon;
};
int findLoc(char name[][25],char find[]){
	int n;
	for(n=0;strcmp(name[n],find)!=0;n++);
	return n;
}
int distance(struct LOC loc[],int c1,int c2){
	double x1,y1,z1,x2,y2,z2,d;
	x1=R*cos(loc[c1].lat)*cos(loc[c1].lon);
	y1=R*cos(loc[c1].lat)*sin(loc[c1].lon);
	z1=R*sin(loc[c1].lat);
	x2=R*cos(loc[c2].lat)*cos(loc[c2].lon);
	y2=R*cos(loc[c2].lat)*sin(loc[c2].lon);
	z2=R*sin(loc[c2].lat);
	d=sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
	return (int)floor(R*acos((2*R*R-d*d)/(2*R*R))+0.5);
}
int main(){
	struct LOC loc[105];
	char name[105][25],city1[25],city2[25];
	int dis[105][105],d;
	int N,M,Q;
	int i,j,k;
	int c1,c2;
	int cases;
	for(cases=1;scanf("%d%d%d",&N,&M,&Q),N+M+Q;cases++){
		if(cases>1) puts("");
		printf("Case #%d\n",cases);
		for(i=0;i<N;i++){
			scanf("%s%lf%lf",name[i],&loc[i].lat,&loc[i].lon);
			loc[i].lat*=pi/180,loc[i].lon*=pi/180;
		}
		for(i=0;i<N;i++){
			dis[i][i]=0;
			for(j=0;j<i;j++)
				dis[i][j]=dis[j][i]=1000000000;
		}
		while(M--){
			scanf("%s%s",city1,city2);
			c1=findLoc(name,city1),c2=findLoc(name,city2);
			dis[c1][c2]=distance(loc,c1,c2);
		}
		for(k=0;k<N;k++)
			for(i=0;i<N;i++)
				for(j=0;j<N;j++)
					if((d=dis[i][k]+dis[k][j])<dis[i][j]) dis[i][j]=d;
		while(Q--){
			scanf("%s%s",city1,city2);
			c1=findLoc(name,city1),c2=findLoc(name,city2);
			if(c1==-1||c2==-1||dis[c1][c2]==1000000000) puts("no route exists");
			else printf("%d km\n",dis[c1][c2]);
		}
	}
	return 0;
}
