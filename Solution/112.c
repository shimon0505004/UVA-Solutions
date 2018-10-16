#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct TREE{
	int value;
	struct TREE *left;
	struct TREE *right;
}tree;
typedef tree *treePtr;
treePtr head;
int need;
void newtree(treePtr *ptr){
	(*ptr)=(treePtr)malloc(sizeof(tree));
	(*ptr)->left=NULL;
	(*ptr)->right=NULL;
	(*ptr)->value=0;
}
void gettree(treePtr *ptr){
	int node,neg=0;
	char a;
	while(isspace(a=getchar()));
	if(a==')') *ptr=NULL;
	else{
		if(a=='-') neg=1,a=getchar();
		for(node=a-'0';isdigit(a=getchar());node=node*10+a-'0');
		if(neg) node*=-1;
		(*ptr)->value=node;
		newtree(&((*ptr)->left));
		if(a!='(') while(getchar()!='(');
		gettree(&((*ptr)->left));
		newtree(&((*ptr)->right));
		while(getchar()!='(');
		gettree(&((*ptr)->right));
		while(getchar()!=')');
	}
}
int dfs(treePtr head,int tot){
	tot+=head->value;
	if(head->left==NULL&&head->right==NULL)
		if(tot==need) return 1;
	if(head->left!=NULL)
		if(dfs(head->left,tot)) return 1;
	if(head->right!=NULL)
		if(dfs(head->right,tot)) return 1;
	return 0;
}
void cleantree(treePtr ptr)
{
	if(ptr->left!=NULL)
		cleantree(ptr->left);
	if(ptr->right!=NULL)
		cleantree(ptr->right);
	ptr->left=NULL;
	ptr->right=NULL;
	free(ptr);
	ptr=NULL;
}
int main()
{
	char paren[3];
	while(scanf("%d",&need)==1){
		newtree(&head);
		while(getchar()!='(');
		gettree(&head);
		if(head!=NULL){
			if(dfs(head,0)) puts("yes");
			else puts("no");
			cleantree(head);
		}else puts("no");
	}
	return 0;
}
