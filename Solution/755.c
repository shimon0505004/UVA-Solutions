#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define Ubound 9
typedef struct phone{
	char name[Ubound];
	struct phone *lefttree;
	struct phone *righttree;
	int times;
}PhoneNum;
typedef PhoneNum *PhoneNumPtr;
const char *map="22233344455566670778889990";
int nodup;
void newNode(PhoneNumPtr *newPtr)
{
	(*newPtr)=(PhoneNumPtr)malloc(sizeof(PhoneNum));
	(*newPtr)->lefttree=NULL;
	(*newPtr)->righttree=NULL;
	(*newPtr)->times=1;
}
void insertNode(PhoneNumPtr *root,char *temp)
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
		else{
			(*root)->times++;
			nodup=1;
		}
	}
	return;
}
void inOrder(PhoneNumPtr treePtr)
{
	if(treePtr!=NULL){
		inOrder(treePtr->lefttree);
		if(treePtr->times>1)
			printf("%s %d\n",treePtr->name,treePtr->times);
		inOrder(treePtr->righttree);
	}
	free(treePtr);
}
int main()
{
	int runs,count,cases,i;
	PhoneNumPtr root;
	char temp[Ubound],a;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		if(i) puts("");
		scanf("%d ",&runs);
		nodup=0;
		root=NULL;
		while(runs--){
			count=0;
			memset(temp,0,sizeof(temp));
			while((a=getchar())&&a!='\n'){
				if(isdigit(a))
					temp[count++]=a;
				else if(isalpha(a))
					temp[count++]=map[a-'A'];
				if(count==3) temp[count++]='-';
			}
			insertNode(&root,temp);
		}
		if(!nodup)
			puts("No duplicates.");
		else 
			inOrder(root);
	}
	return 0;
}
