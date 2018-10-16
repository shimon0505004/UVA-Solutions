#include<stdio.h>
int inOrder[10005],postOrder[10005],invIn[10005];
int ans,min;
void dfs(int hIn,int tIn,int hPost,int tPost,int now){
	int root=invIn[postOrder[tPost]];
	if(hIn>tIn||hPost>tPost||now+inOrder[root]>min) return;
	if(hIn==tIn){
		if(now+inOrder[root]<min) min=now+inOrder[root],ans=inOrder[root];
		else if(now+inOrder[root]==min&&ans>inOrder[root]) ans=inOrder[root];
		return;
	}
	dfs(hIn,root-1,hPost,hPost+root-hIn-1,now+inOrder[root]);
	dfs(root+1,tIn,tPost-tIn+root,tPost-1,now+inOrder[root]);
}
int main(){
	char input[50000],check;
	int count;
	while(!feof(stdin)){
		count=0;
		while(scanf("%d%c",&inOrder[count],&check)){
			invIn[inOrder[count]]=count;
			count++;
			if(check=='\n') break;
		}
		count=0;
		while(scanf("%d%c",&postOrder[count++],&check)==2&&check!='\n');
		min=ans=1000000000;
		dfs(0,count-1,0,count-1,0);
		printf("%d\n",ans);
		scanf(" ");
	}
	return 0;
}
