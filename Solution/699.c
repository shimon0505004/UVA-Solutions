#include<stdio.h>
#include<stdlib.h>
#define Ubound 10000
typedef struct tree{
	struct tree *lefttree;
	struct tree *righttree;
	int num;
	int pos;
}Tree;
int pos[Ubound];
int min,max;
typedef Tree *TreePtr;
void inOrder(TreePtr treePtr)
{
	if(treePtr!=NULL){
		inOrder(treePtr->lefttree);
		pos[Ubound/2+treePtr->pos]+=treePtr->num;
		inOrder(treePtr->righttree);
	}
	free(treePtr);
}
void newNode(TreePtr *newPtr)
{
	(*newPtr)=(TreePtr)malloc(sizeof(Tree));
	(*newPtr)->lefttree=NULL;
	(*newPtr)->righttree=NULL;
}
void preOrder(TreePtr *treePtr,int pos)
{
	int input;
	scanf("%d",&input);
	if(input<=0)
		return;
	else{
		newNode(treePtr);
		(*treePtr)->num=input;
		(*treePtr)->pos=pos;
		if(pos<min) min=pos;
		else if(pos>max) max=pos;
	}
	preOrder(&((*treePtr)->lefttree),(*treePtr)->pos-1);
	preOrder(&((*treePtr)->righttree),(*treePtr)->pos+1);
	return;
}
int main()
{
	int cases,i;
	TreePtr root;
	for(cases=1;;cases++){
		root=NULL;
		memset(pos,0,sizeof(pos));
		min=max=0;
		preOrder(&root,0);
		if(root==NULL) break;
		inOrder(root);
		printf("Case %d:\n",cases);
		for(i=min;i<=max;i++){
			if(i-min) printf(" ");
			printf("%d",pos[Ubound/2+i]);
		}
		printf("\n\n");
	}
	return 0;
}
