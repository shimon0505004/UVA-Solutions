#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TREE{
	struct TREE *left,*right;
	char word[30];
	int len;
};
void insert(struct TREE **now,char word[],int len){
	if(*now==NULL){
		(*now)=(struct TREE *)malloc(sizeof(struct TREE));
		(*now)->left=(*now)->right=NULL;
		(*now)->len=len;
		strcpy((*now)->word,word);
	}else{
		if((*now)->len>len) insert(&((*now)->left),word,len);
		else if((*now)->len<len) insert(&((*now)->right),word,len);
		else if(strcmp((*now)->word,word)>0) insert(&((*now)->left),word,len);
		else if(strcmp((*now)->word,word)<0) insert(&((*now)->right),word,len);
	}
}
void inOrder(struct TREE *now){
	if(now!=NULL){
		inOrder(now->left);
		puts(now->word);
		inOrder(now->right);
	}
}
void dfs(int x,int y,char visit[][25],char square[][25],struct TREE **root,int length,char word[]){
	int i;
	visit[x][y]=1;
	word[length-1]=square[x][y];
	word[length]=0;
	for(i=0;i<=length-3;i++) insert(root,word+i,length-i);
	if(square[x-1][y]>square[x][y]) dfs(x-1,y,visit,square,root,length+1,word);
	if(square[x+1][y]>square[x][y]) dfs(x+1,y,visit,square,root,length+1,word);
	if(square[x][y-1]>square[x][y]) dfs(x,y-1,visit,square,root,length+1,word);
	if(square[x][y+1]>square[x][y]) dfs(x,y+1,visit,square,root,length+1,word);
	if(square[x-1][y-1]>square[x][y]) dfs(x-1,y-1,visit,square,root,length+1,word);
	if(square[x+1][y-1]>square[x][y]) dfs(x+1,y-1,visit,square,root,length+1,word);
	if(square[x-1][y+1]>square[x][y]) dfs(x-1,y+1,visit,square,root,length+1,word);
	if(square[x+1][y+1]>square[x][y]) dfs(x+1,y+1,visit,square,root,length+1,word);
}
int main(){
	int cases,size;
	char square[25][25];
	char visit[25][25];
	char word[30];
	struct TREE *root;
	int i,j;
	scanf("%d",&cases);
	while(cases--){
		memset(square,0,sizeof(square));
		memset(visit,0,sizeof(visit));
		scanf("%d",&size);
		for(i=1;i<=size;i++) scanf("%s",square[i]+1);
		root=NULL;
		for(i=1;i<=size;i++)
			for(j=1;j<=size;j++){
				if(visit[i][j]) continue;
				dfs(i,j,visit,square,&root,1,word);
			}
		inOrder(root);
		if(cases) puts("");
	}
	return 0;
}
