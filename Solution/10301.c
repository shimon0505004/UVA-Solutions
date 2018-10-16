#include<stdio.h>
#include<string.h>
#include<math.h>
struct CIRCLE{
	double x,y,radius;
	int parent,size;
}c[105];
double distance(struct CIRCLE *c1,struct CIRCLE *c2){
	double x=c1->x-c2->x,y=c1->y-c2->y;
	return sqrt(x*x+y*y);
}

int find_root(int n){
	if(c[n].parent!=n) c[n].parent=find_root(c[n].parent);
	return c[n].parent;
}
void link(int a,int b){
	if(c[a].size<c[b].size) c[a].parent=b,c[b].size+=c[a].size;
	else c[b].parent=a,c[a].size+=c[b].size;
}
int main(){
	int i,j,max,n;
	while(scanf("%d",&n),n>=0){
		for(i=0;i<n;i++)
			scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].radius),c[i].parent=i,c[i].size=1;
		for(i=0;i<n;i++)
			for(j=0;j<i;j++){
				double d=distance(&c[i],&c[j]);
				int r1=find_root(i),r2=find_root(j);
				if(r1!=r2&&d<c[i].radius+c[j].radius&&d>fabs(c[i].radius-c[j].radius))
					link(r1,r2);
			}
		max=0;
		for(i=0;i<n;i++)
			if(c[i].size>max) max=c[i].size;
		printf("The largest component contains %d ring",max);
		if(max!=1) printf("s");
		puts(".");
	}
	return 0;
}
