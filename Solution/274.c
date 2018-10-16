#include<stdio.h>
#include<string.h>
#define MAX 105
int Queue[MAX];
int head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	Queue[head++]=n;
	head%=MAX;
}
int dequeue(){
	int result=Queue[tail++];
	tail%=MAX;
	return result;
}
char is_empty(){
	return head==tail;
}
int main(){
	int rooms,chome,mhome,T,cases=0,from,to,i,j,k;
	char mouse[105][105],mousereach[105],input[10];
	char cat[105][105],catreach[105];
	char flag1,flag2;
	scanf("%d",&T);
	for(cases=0;cases<T;cases++){
		if(cases) puts("");
		scanf("%d%d%d ",&rooms,&chome,&mhome);
		memset(cat,0,sizeof(cat));
		memset(mouse,0,sizeof(mouse));
		for(;;){
			fgets(input,10,stdin);
			sscanf(input,"%d%d",&from,&to);
			if(from<0) break;
			cat[from][to]=1;
		}
		for(;;){
			if(fgets(input,10,stdin)==NULL||*input=='\n') break;
			sscanf(input,"%d%d",&from,&to);
			mouse[from][to]=1;
		}
		if(chome==mhome){
			puts("Y N");
			continue;
		}
		flag1=flag2=0;
		initial();
		memset(catreach,0,sizeof(catreach));
		enqueue(chome);
		catreach[chome]=1;
		while(!is_empty()){
			int now=dequeue();
			for(i=1;i<=rooms;i++){
				if(catreach[i]) continue;
				if(cat[now][i]){
					catreach[i]=1;
					enqueue(i);
				}
			}
		}
		if(catreach[mhome]){
			puts("Y N");
			continue;
		}
		initial();
		memset(mousereach,0,sizeof(mousereach));
		enqueue(mhome);
		mousereach[mhome]=1;
		while(!is_empty()){
			int now=dequeue();
			for(i=1;i<=rooms;i++){
				if(mouse[now][i]&&i==mhome&&mousereach[now]==1) flag2=1;
				if(mousereach[i]) continue;
				if(mouse[now][i]){
					mousereach[i]=mousereach[now];
					if(catreach[i]) flag1=1,mousereach[i]=-1;
					enqueue(i);
				}
			}
			if(flag1&&flag2) break;
		}
		if(flag1) putchar('Y');
		else putchar('N');
		putchar(' ');
		if(flag2) putchar('Y');
		else putchar('N');
		puts("");
	}
	return 0;
}
