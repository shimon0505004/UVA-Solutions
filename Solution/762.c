#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 680
int cities[MAX_SIZE];
char visit[MAX_SIZE];
void cputchar(int n){
	putchar(n/26+'A');
	putchar(n%26+'A');
}
struct CITY{
	int others[MAX_SIZE];
	int parent;
	char isExist;
}city[MAX_SIZE];
int queue[MAX_SIZE],tail,head,count;
void enqueue(int node){
	queue[tail++]=node;
	tail%=MAX_SIZE;
}
int dequeue(){
	int result=queue[head++];
	head%=MAX_SIZE;
	return result;
}
int is_empty(){
	return tail==head;
}
void clearqueue(){
	tail=head=0;
}
int toN(char *name){
	return (name[0]-'A')*26+name[1]-'A';
}
void print(int c){
	int p=city[c].parent;
	if(p>=0){
		cputchar(c);
		putchar(' ');
		cputchar(p);
		puts("");
		print(p);
	}
}
void bfs(int c1,int depth,int c2){
	int i,t,c;
	enqueue(c2);
	while(!is_empty()){
		t=dequeue();
		if(city[t].others[c1]==1){
			city[c1].parent=t;
			city[c2].parent=-1;
			print(c1);
			return;
		}
		for(i=0;i<count;i++){
			c=cities[i];
			if(city[t].others[c]==1&&!visit[c]){
				city[c].parent=t;
				enqueue(c);
				visit[c]=1;
			}
		}
	}
	puts("No route");
}
int main()
{
	int routes,c1,c2,i,j,k,t,start=0;
	char city1[3],city2[3];
	while(scanf("%d",&routes)==1){
		if(start) puts("");
		start=1;
		for(i=0;i<MAX_SIZE;i++){
			city[i].isExist=0;
			city[i].parent=-1;
			for(j=0;j<MAX_SIZE;j++)
				city[i].others[j]=0;
		}
		memset(visit,0,sizeof(visit));
		count=head=tail=0;
		while(routes--){
			scanf("%s%s",city1,city2);
			c1=toN(city1);
			c2=toN(city2);
			if(!city[c1].isExist) cities[count++]=c1;
			if(!city[c2].isExist) cities[count++]=c2;
			city[c1].others[c2]=city[c2].others[c1]=1;
			city[c1].isExist=city[c2].isExist=1;
		}
		scanf("%s%s",city1,city2);
		c1=toN(city1);
		c2=toN(city2);
		clearqueue();
		bfs(c1,0,c2);
	}
	return 0;
}
