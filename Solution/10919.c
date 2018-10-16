#include<stdio.h>
#include<stdlib.h>
typedef struct course{
	int cNum;
	struct course *leftcourse;
	struct course *rightcourse;
}cNum;
typedef cNum *cNumPtr;
void newNode(cNumPtr *newPtr)
{
	(*newPtr)=(cNumPtr)malloc(sizeof(cNum));
	(*newPtr)->leftcourse=NULL;
	(*newPtr)->rightcourse=NULL;
}
void insertNode(cNumPtr *current,int num)
{
	if((*current)==NULL){
		newNode(current);
		(*current)->cNum=num;
	}
	else{
		if((*current)->cNum<num)
			insertNode(&((*current)->rightcourse),num);
		else if((*current)->cNum>num)
			insertNode(&((*current)->leftcourse),num);
	}
	return;
}
int searchNode(cNumPtr current,int dest)
{
	if(current==NULL) return 0;
	if(current->cNum<dest)
		return searchNode(current->rightcourse,dest);
	else if(current->cNum>dest)
		return searchNode(current->leftcourse,dest);
	else
		return 1;
}
int main()
{
	int k,M,i,temp,flag,r,c,j;
	cNumPtr head;
	while(scanf("%d%d",&k,&M),k){
		head=NULL,flag=0;
		for(i=0;i<k;i++){
			scanf("%d",&temp);
			insertNode(&head,temp);
		}
		for(i=0;i<M;i++){
			scanf("%d%d",&r,&c);
			for(j=0;j<r;j++){
				scanf("%d",&temp);
				if(searchNode(head,temp)) c--;
			}
			if(c>0) flag=1;
		}
		if(flag) puts("no");
		else puts("yes");
	}
	return 0;
}
