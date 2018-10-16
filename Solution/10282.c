#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word{
	char foreign[11];
	char domestic[11];
	struct word *leftword;
	struct word *rightword;
}Dict;
typedef Dict *DictPtr;
void findNode(DictPtr current,char *query)
{
	if(current==NULL)
		puts("eh");
	else
		if(strcmp(current->foreign,query)<0)
			findNode(current->rightword,query);
		else if(strcmp(current->foreign,query)>0)
			findNode(current->leftword,query);
		else
			puts(current->domestic);
	return;
}
void newNode(DictPtr *newPtr)
{
	(*newPtr)=(DictPtr)malloc(sizeof(Dict));
	(*newPtr)->leftword=NULL;
	(*newPtr)->rightword=NULL;
}
void insertNode(DictPtr *current,char *foreign,char *domestic)
{
	if((*current)==NULL){
		newNode(current);
		strcpy((*current)->foreign,foreign);
		strcpy((*current)->domestic,domestic);
	}
	else{
		if(strcmp((*current)->foreign,foreign)<0)
			insertNode(&((*current)->rightword),foreign,domestic);
		else if(strcmp((*current)->foreign,foreign)>0)
			insertNode(&((*current)->leftword),foreign,domestic);
	}
	return;
}
int main()
{
	char foreign[11],domestic[11],query[11],input[23];
	DictPtr root=NULL;
	while(1){
		fgets(input,23,stdin);
		if(*input=='\n') break;
		sscanf(input,"%s%s",domestic,foreign);
		insertNode(&root,foreign,domestic);
	}
	while(scanf("%s",query)==1)
		findNode(root,query);
	return 0;
}
