#include<stdio.h>
#include<string.h>
void printWord(int n,int len){
	int i,min=n;
	for(i=1;i<len;i++){
		n=(n>>1)+((n&1)<<(len-1));
		if(n<min) min=n;
	}
	for(i=1<<(len-1);i>0;i>>=1){
		if(min&i) putchar('b');
		else putchar('a');
	}
	puts("");
}
int main(){
	int len,now,next,i,j;
	char word[20],rew[5];
	int visit[1<<16],steps;
	int seq[1<<16];
	char rewrite[8];
	while(scanf("%d",&len)==1){
		scanf("%s",word);
		now=0;
		for(i=0;i<len;i++){
			now<<=1;
			now+=word[i]-'a';
		}
		for(i=0;i<8;i++){
			scanf("%s",rew);
			rewrite[((rew[0]-'a')<<2)+((rew[1]-'a')<<1)+(rew[2]-'a')]=rew[3]-'a';
		}
		scanf("%d",&steps);
		steps++;
		memset(visit,0,sizeof(visit));
		for(i=1;i<=steps&&visit[now]==0;i++){
			visit[now]=i;
			seq[i]=now;
			next=0;
			for(j=0;j<len;j++)
				next+=rewrite[((now&(1<<((j+2)%len)))?1<<2:0)+((now&(1<<j))?1<<1:0)+((now&(1<<((j+len-1)%len)))?1:0)]<<j;
			now=next;
		}
		if(i>steps) printWord(seq[steps],len);
		else printWord(seq[visit[now]+(steps-i)%(i-visit[now])],len);
	}
	return 0;
}
