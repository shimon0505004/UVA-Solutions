#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int queue[26];
int head,tail;
void init(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=26;
}
int dequeue(){
	int result=queue[tail++];
	tail%=26;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	char map[26][26];
	char c1[30],c2[30];
	char level[26];
	char parent[26];
	char visit[26];
	int cases,i;
	int pair,query;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&pair,&query);
		memset(map,0,sizeof(map));
		memset(level,0,sizeof(level));
		memset(visit,0,sizeof(visit));
		while(pair--){
			scanf("%s%s",c1,c2);
			map[*c1-'A'][*c2-'A']=map[*c2-'A'][*c1-'A']=1;
		}
		enqueue('R'-'A');
		while(!is_empty()){
			int now=dequeue();
			visit[now]=1;
			for(i=0;i<26;i++)
				if(map[now][i]&&visit[i]==0)
					enqueue(i),level[i]=level[now]+1,parent[i]=now;
		}
		while(query--){
			int minl,now1,now2,commonl;
			char route[26]={0};
			int route_len,common;
			scanf("%s%s",c1,c2);
			now1=*c1-'A',now2=*c2-'A';
			minl=MIN(level[now1],level[now2]);
			while(level[now1]>minl) now1=parent[now1];
			while(level[now2]>minl) now2=parent[now2];
			while(now1!=now2) now1=parent[now1],now2=parent[now2];
			commonl=level[now1];
			now1=*c1-'A',now2=*c2-'A';
			route_len=(level[now1]-commonl)+(level[now2]-commonl)+1;
			common=level[now1]-commonl;
			for(i=0;i<=common;i++,now1=parent[now1])
				route[i]=now1+'A';
			for(i=route_len-1;i>common;i--,now2=parent[now2])
				route[i]=now2+'A';
			puts(route);
		}
		if(cases) puts("");
	}
	return 0;
}
