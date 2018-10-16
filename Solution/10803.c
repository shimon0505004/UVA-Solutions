#include<stdio.h>
#include<math.h>
#define UBOUND 100000
struct POINT{
	int x,y;
};
double distance(struct POINT p1,struct POINT p2){
	int x=p1.x-p2.x,y=p1.y-p2.y;
	double d=sqrt(x*x+y*y);
	if(d>10)
		return UBOUND;
	return sqrt(x*x+y*y);
}
int main(){
	int N,n,i,j,k,cases;
	struct POINT p[105];
	double dis[105][105],max,t,d;
	scanf("%d",&N);
	for(cases=1;cases<=N;cases++){
		printf("Case #%d:\n",cases);
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(i=0;i<n;i++){
			dis[i][i]=0;
			for(j=0;j<i;j++)
				dis[i][j]=dis[j][i]=distance(p[i],p[j]);
		}
		for(k=0;k<n;k++)
			for(i=0;i<n;i++)
				for(j=0;j<i;j++)
					if(dis[i][j]>(t=dis[i][k]+dis[k][j]))
						dis[i][j]=dis[j][i]=t;
		max=0;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				if(dis[i][j]>max)
					max=dis[i][j];
		if(max<UBOUND)
			printf("%.4lf\n",max);
		else
			puts("Send Kurdy");
		puts("");
	}
	return 0;
}
