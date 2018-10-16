#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE (105*13)
struct ADJ{
	int n,arr,dep;
	struct ADJ *next;
};
struct STATION{
	struct ADJ *adj;
};
int find_name(char name[][35],int *n_city,char find[]){
	int i;
	for(i=0;i<*n_city;i++)
		if(strcmp(name[i],find)==0) return i;
	strcpy(name[*n_city],find);
	return (*n_city)++;
}
int encode(int pos,int time){
	return pos*13+time;
}
void decode(int code,int *pos,int *time){
	*time=code%13,code/=13;
	*pos=code;
}
int queue[SIZE],head,tail,depth[SIZE];
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
void insert(struct STATION *s,int adj,int f,int t){
	struct ADJ *tmpadj=s->adj;
	s->adj=(struct ADJ *)malloc(sizeof(struct ADJ));
	s->adj->n=adj;
	s->adj->dep=f,s->adj->arr=t;
	s->adj->next=tmpadj;
}
int main(){
	int T,cases,routes;
	char name[105][35];
	int n_city;
	int code;
	struct STATION s[105];
	char name1[35],name2[35];
	int start,dest,now,i,min;
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		printf("Test Case %d.\n",cases);
		n_city=0;
		memset(s,0,sizeof(s));
		scanf("%d",&routes);
		while(routes--){
			int c1,c2,dep,dura;
			scanf("%s%s%d%d",name1,name2,&dep,&dura);
			if(dep>=18) dep-=18;
			else if(dep<6) dep+=6;
			else continue;
			dura+=dep;
			if(dura<=12){
				c1=find_name(name,&n_city,name1),c2=find_name(name,&n_city,name2);
#ifdef DEBUG
				printf("%s -> %s, %d -> %d\n",name[c1],name[c2],dep,dura);
#endif
				insert(&s[c1],c2,dep,dura);
			}
		}
		scanf("%s%s",name1,name2);
		start=find_name(name,&n_city,name1),dest=find_name(name,&n_city,name2);
		for(i=0;i<SIZE;i++) depth[i]=SIZE;
		initial();
		depth[encode(start,0)]=0;
		enqueue(encode(start,0));
		while(!is_empty()){
			int time;
			struct ADJ *adjPtr;
			code=dequeue();
			decode(code,&now,&time);
			for(adjPtr=s[now].adj;adjPtr!=NULL;adjPtr=adjPtr->next){
				int next=adjPtr->n;
				int nextcode=encode(next,adjPtr->arr);
				if(time<=adjPtr->dep){
					if(depth[nextcode]>depth[code]){
						depth[nextcode]=depth[code];
						enqueue(nextcode);
					}
				}else{
					if(depth[nextcode]>depth[code]+1){
						depth[nextcode]=depth[code]+1;
						enqueue(nextcode);
					}
				}
			}
		}
		min=SIZE;
		for(i=0;i<13;i++) if(min>depth[encode(dest,i)]) min=depth[encode(dest,i)];
		if(min<SIZE) printf("Vladimir needs %d litre(s) of blood.\n",min);
		else puts("There is no route Vladimir can take.");
	}
	return 0;
}
