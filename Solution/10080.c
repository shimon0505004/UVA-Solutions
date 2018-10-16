#include<stdio.h>
#include<string.h>
#include<math.h>
#define EPS 1e-5
#define SIZE 205
struct POINT{
	double x,y;
};
double dis(struct POINT *p1,struct POINT *p2){
	double x=p1->x-p2->x,y=p1->y-p2->y;
	return sqrt(x*x+y*y);
}
char safe(struct POINT *g,struct POINT *h,int v,int s){
	if(s*v+EPS>dis(g,h)) return 1;
	return 0;
}
int queue[SIZE],head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE;
}
int dequeue(){
	int res=queue[tail++];
	tail%=SIZE;
	return res;
}
char is_empty(){
	return head==tail;
}
int prev[SIZE],cap[SIZE][SIZE];
char visit[SIZE];
int n_v;
char find_flow(){
	int i;
	memset(visit,0,sizeof(visit));
	initial(),enqueue(0),visit[0]=1;
	while(!is_empty()){
		int now=dequeue();
		if(now==n_v-1) return 1;
		for(i=0;i<n_v;i++)
			if(cap[now][i]>0&&visit[i]==0){
				visit[i]=1;
				prev[i]=now;
				enqueue(i);
			}
	}
	return 0;
}
int main(){
	int n,m,s,v,i,j,update,flow;
	struct POINT gopher[105],hole[105];
	while(scanf("%d%d%d%d",&n,&m,&s,&v)==4){
		for(i=0;i<n;i++) scanf("%lf%lf",&gopher[i].x,&gopher[i].y);
		for(i=0;i<m;i++) scanf("%lf%lf",&hole[i].x,&hole[i].y);
		memset(cap,0,sizeof(cap));
		for(i=1;i<=n;i++) 
			cap[0][i]=1;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(safe(&gopher[i-1],&hole[j-1],v,s))
					cap[i][j+n]=1;
		for(j=1;j<=m;j++)
			cap[j+n][m+n+1]=1;
		n_v=n+m+2;
		flow=0;
		while(find_flow()){
			int p,q;
			update=10;
			for(p=n_v-1;p!=0;p=q){
				q=prev[p];
				if(cap[q][p]<update)
					update=cap[q][p];
			}
			flow+=update;
			for(p=n_v-1;p!=0;p=q){
				q=prev[p];
				cap[p][q]+=update;
				cap[q][p]-=update;
			}
		}
		printf("%d\n",n-flow);
	}
	return 0;
}
