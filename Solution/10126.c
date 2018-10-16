#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree{
	char name[25];
	struct tree *lefttree;
	struct tree *righttree;
	int num;
}Tree;
int freq,flag;
typedef Tree *TreePtr;
void inOrder(TreePtr treePtr)
{
	if(treePtr!=NULL){
		inOrder(treePtr->lefttree);
		if(treePtr->num==freq){
			printf("%s\n",treePtr->name);
			flag=1;
		}
		inOrder(treePtr->righttree);
	}
	free(treePtr);
}
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
int main()
{
	char nonalpha[128]={0};
	TreePtr root;
	char sentence[1010],*Ptr,temp[1010];
	int i,wordlen,len,start=0;
	char character;
	for(i=0,character=1;character<127;character++)
		if(!isalpha(character))
			nonalpha[i++]=character;
	while(1){
		if(scanf("%d ",&freq)!=1) break;
		if(start) printf("\n");
		start=1,root=NULL,flag=1;
		while(fgets(sentence,1010,stdin)!=NULL){
			for(Ptr=strtok(sentence,nonalpha);Ptr!=NULL;Ptr=strtok(NULL,nonalpha)){
				if(!strcmp(Ptr,"EndOfText")){
					flag=0;
					break;
				}
				len=strlen(Ptr);
				for(i=0;i<len;i++)
					Ptr[i]=tolower(Ptr[i]);
				insertNode(&root,Ptr);
			}
			if(!flag) break;
		}
		flag=0;
		inOrder(root);
		if(!flag)
			printf("There is no such word.\n");
	}
	return 0;
}
