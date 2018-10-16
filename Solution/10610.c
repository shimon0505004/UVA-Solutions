#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SIZE 1005
typedef struct POINT{
	double x,y;
}Point;
double distance(Point *p1,Point *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
int queue[SIZE];
int head,tail;
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int result=queue[tail++];
	tail%=SIZE;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int v,m,i,j;
	char input[25];
	Point hole[SIZE];
	double dis[SIZE][SIZE];
	int depth[SIZE],threshold;
	int n;
	while(scanf("%d%d ",&v,&m),v+m){
		threshold=60*v*m;
		for(n=0;fgets(input,25,stdin),*input!='\n';n++)
			sscanf(input,"%lf%lf",&hole[n].x,&hole[n].y);
		for(i=0;i<n;i++)
			for(j=0;j<i;j++)
				dis[i][j]=dis[j][i]=distance(&hole[i],&hole[j]);
		memset(depth,0,sizeof(depth));
		head=tail=0;
		enqueue(0);
		depth[0]=1;
		while(!is_empty()){
			int now=dequeue();
			for(i=0;i<n;i++)
				if(depth[i]==0&&dis[now][i]+1e-5<threshold){
					depth[i]=depth[now]+1;
					if(i==1) break;
					enqueue(i);
				}
			if(i==1) break;
		}
		if(depth[1]==0) puts("No.");
		else printf("Yes, visiting %d other holes.\n",depth[1]-2);
	}
	return 0;
}
