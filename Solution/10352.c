#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TREE{
	struct TREE *left,*right;
	char first[10],last[10];
	int count;
};
int mystrcmp(char str1[],char str2[]){
	int cmp;
	if((cmp=strncmp(str1,str2,2))!=0) return cmp;
	if(str1[2]==0&&str2[2]!=0) return -1;
	if(str1[2]!=0&&str2[2]==0) return 1;
	return strncmp(str1+3,str2+3,2);
}
void insert(struct TREE **cur,char str[]){
	int cmp;
	if(*cur==NULL){
		*cur=(struct TREE *)malloc(sizeof(struct TREE));
		(*cur)->left=(*cur)->right=NULL;
		(*cur)->count=1;
		strcpy((*cur)->first,str);
		strcpy((*cur)->last,str);
	}else{
		cmp=mystrcmp((*cur)->first,str);
		if(cmp<0) insert(&((*cur)->right),str);
		else if(cmp>0) insert(&((*cur)->left),str);
		else strcpy((*cur)->last,str),(*cur)->count++;
	}
}
void inOrder(struct TREE *now){
	if(now!=NULL){
		inOrder(now->left);
		printf("%s %d\n",now->last,now->count);
		inOrder(now->right);
	}
}
int main(){
	char input[25]={0};
	struct TREE *root;
	int cases;
	for(cases=1;scanf("%s",input)==1;cases++){
		root=NULL;
		input[5]=0;
		insert(&root,input);
		memset(input,0,sizeof(input));
		while(scanf("%s",input),*input!='#'){
			input[5]=0;
			insert(&root,input);
			memset(input,0,sizeof(input));
		}
		printf("Set #%d:\n",cases);
		inOrder(root);
		puts("");
	}
	return 0;
}
