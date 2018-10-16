#include<stdio.h>
#include<string.h>
#define SIZE 201
int queue[SIZE*SIZE],head,tail;
void initial(){
	head=tail=0;
}
void enqueue(int n){
	queue[head++]=n;
	head%=SIZE*SIZE;
}
int dequeue(){
	int result=queue[tail++];
	tail%=SIZE*SIZE;
	return result;
}
char is_empty(){
	return head==tail;
}
int encode(int a,int b){
	return a*SIZE+b;
}
void decode(int code,int *a,int *b){
	*b=code%SIZE,code/=SIZE;
	*a=code;
}
int used[SIZE*SIZE],volume[SIZE*SIZE];
int v(int a,int b,int c,int d){
	int res=0;
	if(a>res&&a<=d) res=a;
	if(b>res&&b<=d) res=b;
	if(c>res&&c<=d) res=c;
	return res;
}
int pour(int *from,int *to,int vv){
	int tfrom=*from,tto=*to;
	if(*to+*from>vv) *to=vv;
	else *to+=*from;
	*from=tfrom+tto-*to;
	return tfrom-*from;
}
void printAns(int total,int need){
	int i,vv=0,use=0x7f7f7f7f;
	for(i=0;i<SIZE*SIZE;i++)
		if(used[i]!=0x7f7f7f7f){
			int a,b,c,t;
			decode(i,&a,&b);
			c=total-a-b;
			t=v(a,b,c,need);
			if(t>vv&&t<=need) vv=t,use=used[i];
			else if(t==vv&&use>used[i]) use=used[i];
		}
	printf("%d %d\n",use,vv);
}
int main(){
	int cases,code;
	int a,b,c,d,ca,cb,cc;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		memset(used,127,sizeof(used));
		ca=cb=0,cc=c;
		code=encode(ca,cb);
		used[code]=0;
		volume[code]=v(ca,cb,cc,d);
		initial();
		enqueue(code);
		while(!is_empty()){
			int cur=dequeue();
			int na,nb,nc,uu,next;
			decode(cur,&ca,&cb);
			cc=c-ca-cb;
			{
				na=ca,nb=cb,nc=cc;
				uu=pour(&na,&nb,b);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}{
				na=ca,nb=cb,nc=cc;
				uu=pour(&nb,&na,a);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}{
				na=ca,nb=cb,nc=cc;
				uu=pour(&na,&nc,c);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}{
				na=ca,nb=cb,nc=cc;
				uu=pour(&nc,&na,a);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}{
				na=ca,nb=cb,nc=cc;
				uu=pour(&nb,&nc,c);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}{
				na=ca,nb=cb,nc=cc;
				uu=pour(&nc,&nb,b);
				next=encode(na,nb);
				if(uu+used[cur]<used[next]){
					used[next]=uu+used[cur];
					volume[next]=v(na,nb,nc,d);
					enqueue(next);
				}
			}
		}
		printAns(c,d);
	}
	return 0;
}
