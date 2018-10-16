#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree{
	char name[50];
	struct tree *lefttree;
	struct tree *righttree;
	int num;
}Tree;
int total;
typedef Tree *TreePtr;
void newNode(TreePtr *newPtr)
{
	(*newPtr)=(TreePtr)malloc(sizeof(Tree));
	(*newPtr)->lefttree=NULL;
	(*newPtr)->righttree=NULL;
	(*newPtr)->num=1;
}
void insertNode(TreePtr *root,char *temp)
{
	if((*root)==NULL){
		newNode(root);
		strcpy((*root)->name,temp);
	}
	else{
		if(strcmp((*root)->name,temp)<0)
			insertNode(&((*root)->righttree),temp);
		else if(strcmp((*root)->name,temp)>0)
			insertNode(&((*root)->lefttree),temp);
		else
			(*root)->num++;
	}
	return;
}
void inOrder(TreePtr treePtr)
{
	if(treePtr!=NULL){
		inOrder(treePtr->lefttree);
		printf("%s %.4lf\n",treePtr->name,(double)treePtr->num/total*100);
		inOrder(treePtr->righttree);
	}
	free(treePtr);
}
int main()
{
	int cases;
	TreePtr root=NULL;
	char temp[50];
	scanf("%d ",&cases);
	while(cases--){
		total=0;
		while(fgets(temp,50,stdin)!=NULL&&*temp!='\n'){
			temp[strlen(temp)-1]=0;
			insertNode(&root,temp);
			total++;
		}
		inOrder(root);
		if(cases) printf("\n");
	}
	return 0;
}
