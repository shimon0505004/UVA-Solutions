#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10245
char state[SIZE];
int prev[SIZE],depth[SIZE];
struct ADJ{
	int n;
	struct ADJ *next;
};
struct ROOM{
	struct ADJ *connect,*control;
};
int queue[SIZE],head,tail;
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
void initial(){
	head=tail=0;
}
void connect(struct ROOM *r,int n){
	struct ADJ *tmp;
	tmp=r->connect;
	r->connect=(struct ADJ *)malloc(sizeof(struct ADJ));
	r->connect->next=tmp;
	r->connect->n=n;
}
void control(struct ROOM *r,int n){
	struct ADJ *tmp;
	tmp=r->control;
	r->control=(struct ADJ *)malloc(sizeof(struct ADJ));
	r->control->next=tmp;
	r->control->n=n;
}
int chroom(int src,int room){
	return (src%(1<<10))+((room-1)<<10);
}
int chlight(int src,int light){
	return src^(1<<(light-1));
}
int get_curroom(int stat){
	return (stat>>10)+1;
}
char is_lighton(int stat,int r){
	return (stat&(1<<(r-1)))!=0;
}
void printStep(int now){
	int p=prev[now];
	int i,r1,r2;
	if(p!=-1){
		printStep(p);
		r1=get_curroom(now),r2=get_curroom(p);
		if(r1!=r2) printf("- Move to room %d.\n",r1);
		else{
			for(i=1;i<=10;i++){
				if(is_lighton(now,i)!=is_lighton(p,i)){
					if(is_lighton(now,i)) printf("- Switch on light in room %d.\n",i);
					else printf("- Switch off light in room %d.\n",i);
					break;
				}
			}
		}
	}
}
int main(){
	int r,d,s;
	int cases,dest,cur;
	struct ROOM room[15];
	for(cases=1;scanf("%d%d%d",&r,&d,&s),r|d|s;cases++){
		memset(room,0,sizeof(room));
		memset(state,0,sizeof(state));
		while(d--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			connect(&room[a],b);
			connect(&room[b],a);
		}
		while(s--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a==b) continue;
			control(&room[a],b);
		}
		dest=chroom(0,r);
		dest=chlight(dest,r);
		depth[1]=0,state[1]=1,prev[1]=-1;
		initial();
		enqueue(1);
		while(!is_empty()){
			int next,curroom;
			struct ADJ *adjPtr;
			cur=dequeue(),curroom=get_curroom(cur);
			if(cur==dest) break;
			for(adjPtr=room[curroom].connect;adjPtr!=NULL;adjPtr=adjPtr->next){
				if(is_lighton(cur,adjPtr->n)){
					next=chroom(cur,adjPtr->n);
					if(state[next]==0){
						state[next]=1,enqueue(next);
						prev[next]=cur,depth[next]=depth[cur]+1;
					}
				}
			}
			for(adjPtr=room[curroom].control;adjPtr!=NULL;adjPtr=adjPtr->next){
				next=chlight(cur,adjPtr->n);
				if(state[next]==0){
					state[next]=1,enqueue(next);
					prev[next]=cur,depth[next]=depth[cur]+1;
				}
			}
		}
		printf("Villa #%d\n",cases);
		if(cur==dest){
			printf("The problem can be solved in %d steps:\n",depth[dest]);
			printStep(dest);
		}else puts("The problem cannot be solved.");
		puts("");
	}
	return 0;
}
