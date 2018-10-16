#include<stdio.h>
#include<math.h>
#define Ubound 1005
#define max(a,b) ((a)>(b)?(a):(b))
typedef struct POINT{
	int x;
	int y;
}Point;
double dissqr(Point p1,Point p2){
	double x1=p1.x,x2=p2.x,y1=p1.y,y2=p2.y;
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	int n,i,j,k,cases=0,t;
	Point p[Ubound];
	double dis[Ubound][Ubound];
	while(scanf("%d",&n),n){
		printf("Scenario #%d\n",++cases);
		for(i=0;i<n;i++){
			scanf("%d%d",&p[i].x,&p[i].y);
			for(j=0;j<n;j++)
				dis[j][i]=dis[i][j]=dissqr(p[i],p[j]);
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
					if(dis[i][j]>(t=max(dis[i][k],dis[k][j])))
						dis[i][j]=t;
		printf("Frog Distance = %.3lf\n\n",sqrt(dis[0][1]));
	}
	return 0;
}
