#include<stdio.h>
#include<string.h>
#define Q_SIZE 10005
int queue[Q_SIZE];
int head,tail;
void enqueue(int key){
	queue[head++]=key;
	head%=Q_SIZE;
}
int dequeue(){
	int result=queue[tail++];
	tail%=Q_SIZE;
	return result;
}
char is_empty(){
	return head==tail;
}
void initial(){
	head=tail=0;
}
int getNumbyDigit(){
	int i,tmp,result=0;
	for(i=0;i<4;i++){
		scanf("%d",&tmp);
		result=result*10+tmp;
	}
	return result;
}
int main(){
	int cases;
	int start,end,i;
	char forbidden[Q_SIZE];
	int depth[Q_SIZE];
	int n_forbidden;
	int visit[Q_SIZE];
	int ten_pow[4]={1,10,100,1000};
	scanf("%d",&cases);
	while(cases--){
		memset(visit,0,sizeof(visit));
		memset(forbidden,0,sizeof(forbidden));
		memset(depth,0,sizeof(depth));
		start=getNumbyDigit();
		end=getNumbyDigit();
		scanf("%d",&n_forbidden);
		for(i=0;i<n_forbidden;i++)
			forbidden[getNumbyDigit()]=1;
		if(start==end){
			puts("0");
			continue;
		}
		initial();
		enqueue(start);
		while(!is_empty()){
			int now=dequeue();
			for(i=0;i<4;i++){
				int c_d=(now/ten_pow[i])%10,next;
				next=now-c_d*ten_pow[i]+((c_d+1)%10)*ten_pow[i];
				if(visit[next]==0&&forbidden[next]==0){
					visit[next]=1;
					depth[next]=depth[now]+1;
					if(next==end) break;
					enqueue(next);
				}
				next=now-c_d*ten_pow[i]+((c_d+9)%10)*ten_pow[i];
				if(visit[next]==0&&forbidden[next]==0){
					visit[next]=1;
					depth[next]=depth[now]+1;
					if(next==end) break;
					enqueue(next);
				}
			}
			if(i<4) break;
		}
		if(depth[end]==0) puts("-1");
		else printf("%d\n",depth[end]);
	}
	return 0;
}
