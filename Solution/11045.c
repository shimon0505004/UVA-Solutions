#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SIZE 100
int cap[SIZE][SIZE];
int queue[SIZE],tail,head;
char visit[SIZE];
int prev[SIZE],n;
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
char find_flow(){
	int i;
	memset(visit,0,sizeof(visit));
	initial(),enqueue(0),visit[0]=1;
	while(!is_empty()){
		int now=dequeue();
		if(now==n-1) return 1;
		for(i=0;i<n;i++)
			if(cap[now][i]>0&&visit[i]==0){
				visit[i]=1;
				enqueue(i);
				prev[i]=now;
			}
	}
	return 0;
}
int str2size(char s[]){
	if(strcmp(s,"XXL")==0) return 1;
	if(strcmp(s,"XL")==0) return 2;
	if(strcmp(s,"L")==0) return 3;
	if(strcmp(s,"M")==0) return 4;
	if(strcmp(s,"S")==0) return 5;
	if(strcmp(s,"XS")==0) return 6;
	return -1;
}
int main(){
	int cases,M,N,flow;
	int i;
	char s1[5],s2[5];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&N,&M),N/=6;
		memset(cap,0,sizeof(cap));
		for(i=1;i<=M;i++){
			cap[0][i]=1;
			scanf("%s%s",s1,s2);
			cap[i][str2size(s1)+M]=1;
			cap[i][str2size(s2)+M]=1;
		}
		for(i=M+1;i<=M+6;i++)
			cap[i][M+7]=N;
		n=M+8;
		flow=0;
		while(find_flow()){
			int update=2147483647;
			int p,q;
			for(p=n-1;p!=0;p=q)
				q=prev[p],update=MIN(update,cap[q][p]);
			flow+=update;
			for(p=n-1;p!=0;p=q)
				q=prev[p],cap[q][p]-=update,cap[p][q]+=update;
		}
		if(flow==M) puts("YES");
		else puts("NO");
	}
	return 0;
}
