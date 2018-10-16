#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word{
	char name[80];
	struct word *leftword;
	struct word *rightword;
	int count;
}Dict;
typedef Dict *DictPtr;
void inOrder(DictPtr wordPtr)
{
	if(wordPtr!=NULL){
		inOrder(wordPtr->leftword);
		printf("%s %d\n",wordPtr->name,wordPtr->count);
		inOrder(wordPtr->rightword);
	}
	free(wordPtr);
}
void newNode(DictPtr *newPtr)
{
	(*newPtr)=(DictPtr)malloc(sizeof(Dict));
	(*newPtr)->leftword=NULL;
	(*newPtr)->rightword=NULL;
	(*newPtr)->count=0;
}
void insertNode(DictPtr *current,char *temp)
{
	if((*current)==NULL){
		newNode(current);
		strcpy((*current)->name,temp);
		(*current)->count++;
	}
	else{
		if(strcmp((*current)->name,temp)<0)
			insertNode(&((*current)->rightword),temp);
		else if(strcmp((*current)->name,temp)>0)
			insertNode(&((*current)->leftword),temp);
		else
			(*current)->count++;
	}
	return;
}
int main()
{
	char input[80],name[80];
	DictPtr root=NULL;
	int n;
	scanf("%d ",&n);
	while(n--){
		fgets(input,80,stdin);
		sscanf(input,"%s",name);
		insertNode(&root,name);
	}
	inOrder(root);
	return 0;
}
