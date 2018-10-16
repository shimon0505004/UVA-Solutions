#include<stdio.h>
#include<string.h>
#define MAX 205
int queue[MAX];
int tail,head;
void initial(){
	tail=head=0;
}
void enqueue(int n){
	queue[tail++]=n;
	tail%=MAX;
}
int dequeue(){
	int result=queue[head++];
	head%=MAX;
	return result;
}
char is_empty(){
	return head==tail;
}
char Distance(char s1[],char s2[]){
	int len,i,result=0;
	if((len=strlen(s1))!=strlen(s2)) return 0;
	for(i=0;i<len;i++) if(s1[i]!=s2[i]) result++;
	return result==1;
}
int main(){
	int cases,i,j,n_word,n_from,n_to;
	int depth[MAX];
	char dis[MAX][MAX],goal,visit[MAX];
	char word[MAX][15],from[15],to[15],input[30];
	scanf("%d",&cases);
	while(cases--){
		for(n_word=0;scanf("%s",word[n_word]),*word[n_word]!='*';n_word++);
		for(i=0;i<n_word;i++)
			for(j=0;j<i;j++)
				dis[i][j]=dis[j][i]=Distance(word[i],word[j]);
		scanf(" ");
		while(fgets(input,30,stdin)!=NULL&&*input!='\n'){
			memset(visit,0,sizeof(visit));
			memset(depth,0,sizeof(depth));
			sscanf(input,"%s%s",from,to);
			for(n_from=0;strcmp(word[n_from],from);n_from++);
			for(n_to=0;strcmp(word[n_to],to);n_to++);
			initial();
			enqueue(n_from);
			goal=depth[n_from]=0;
			visit[n_from]=1;
			while(!is_empty()&&!goal){
				int now=dequeue();
				for(i=0;i<n_word;i++){
					if(visit[i]) continue;
					if(dis[i][now]){
						visit[i]=1;
						depth[i]=depth[now]+1;
						if(i==n_to){
							goal=1;
							break;
						}
						enqueue(i);
					}
				}
			}
			printf("%s %s %d\n",from,to,depth[n_to]);
		}
		if(cases) puts("");
	}
	return 0;
}
