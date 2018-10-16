#include<stdio.h>
#include<string.h>
#define MAX 30000
struct POINT{
	int x,y,z;
};
struct POINT queue[MAX];
int head,tail;
void initial_queue(){
	head=tail=0;
}
void enqueue(struct POINT p){
	queue[tail++]=p;
	tail%=MAX;
}
struct POINT dequeue(){
	struct POINT result=queue[head++];
	head%=MAX;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int i,j,time,x,y,z;
	char map[33][33][33],*ptr,out;
	int depth[33][33][33],ans;
	struct POINT p,dir[6];
	dir[0].x=0,dir[0].y=0,dir[0].z=-1;
	dir[1].x=0,dir[1].y=0,dir[1].z=1;
	dir[2].x=0,dir[2].y=-1,dir[2].z=0;
	dir[3].x=0,dir[3].y=1,dir[3].z=0;
	dir[4].x=-1,dir[4].y=0,dir[4].z=0;
	dir[5].x=1,dir[5].y=0,dir[5].z=0;
	while(scanf("%d%d%d",&x,&y,&z),x|y|z){
		memset(map,'#',sizeof(map));
		memset(depth,0,sizeof(depth));
		for(i=1;i<=x;i++)
			for(j=1;j<=y;j++){
				scanf("%s",map[i][j]+1);
				if((ptr=strchr(map[i][j],'S'))!=NULL)
					p.x=i,p.y=j,p.z=ptr-map[i][j];
				map[i][j][z+1]='#';
			}
		initial_queue();
		enqueue(p);
		out=0;
		while(!is_empty()&&!out){
			struct POINT now=dequeue(),check;
			for(i=0;i<6;i++){
				check.x=now.x+dir[i].x,check.y=now.y+dir[i].y,check.z=now.z+dir[i].z;
				if(map[check.x][check.y][check.z]=='.'){
					enqueue(check);
					map[check.x][check.y][check.z]='#';
					depth[check.x][check.y][check.z]=depth[now.x][now.y][now.z]+1;
				}else if(map[check.x][check.y][check.z]=='E'){
					ans=depth[now.x][now.y][now.z]+1;
					out=1;
					break;
				}
			}
		}
		if(out) printf("Escaped in %d minute(s).\n",ans);
		else puts("Trapped!");
	}
	return 0;
}
