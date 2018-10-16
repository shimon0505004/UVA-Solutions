#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct word{
	char name[205];
	struct word *leftword;
	struct word *rightword;
}Dict;
typedef Dict *DictPtr;
void inOrder(DictPtr wordPtr)
{
	if(wordPtr!=NULL){
		inOrder(wordPtr->leftword);
		puts(wordPtr->name);
		inOrder(wordPtr->rightword);
	}
	free(wordPtr);
}
void newNode(DictPtr *newPtr)
{
	(*newPtr)=(DictPtr)malloc(sizeof(Dict));
	(*newPtr)->leftword=NULL;
	(*newPtr)->rightword=NULL;
}
void insertNode(DictPtr *current,char *temp)
{
	if((*current)==NULL){
		newNode(current);
		strcpy((*current)->name,temp);
	}
	else{
		if(strcmp((*current)->name,temp)<0)
			insertNode(&((*current)->rightword),temp);
		else if(strcmp((*current)->name,temp)>0)
			insertNode(&((*current)->leftword),temp);
	}
	return;
}
int main()
{
	char character,*tokPtr;
	char nonalpha[128]={0},input[250];
	int i,len;
	DictPtr root=NULL;
	for(i=0,character=1;character<127;character++)
		if(!isalpha(character))
			nonalpha[i++]=character;
	while(fgets(input,250,stdin)!=NULL){
		input[strlen(input)-1]=0;
		for(tokPtr=strtok(input,nonalpha);tokPtr!=NULL;tokPtr=strtok(NULL,nonalpha)){
			len=strlen(tokPtr);
			for(i=0;i<len;i++)
				tokPtr[i]=tolower(tokPtr[i]);
			insertNode(&root,tokPtr);
		}
	}
	inOrder(root);
	return 0;
}
