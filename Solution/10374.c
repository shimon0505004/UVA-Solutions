#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct candidate{
	char name[100];
	char party[100];
	int votes;
	struct candidate *left;
	struct candidate *right;
}Cand;
typedef Cand *CandPtr;
int flag,max;
char winner[100];
void inOrder(CandPtr Ptr)
{
	if(Ptr!=NULL){
		inOrder(Ptr->left);
		/*printf("%-15s gets %3d votes\n",Ptr->name,Ptr->votes);*/
		if(Ptr->votes>max){
			strcpy(winner,Ptr->party);
			max=Ptr->votes;
			flag=0;
		}else if(Ptr->votes==max)
			flag=1;
		inOrder(Ptr->right);
	}
	free(Ptr);
}
void newNode(CandPtr *newPtr)
{
	(*newPtr)=(CandPtr)malloc(sizeof(Cand));
	(*newPtr)->left=NULL;
	(*newPtr)->right=NULL;
	(*newPtr)->votes=0;
}
void insertNode(CandPtr *current,char *name,char *party)
{
	if((*current)==NULL){
		newNode(current);
		strcpy((*current)->name,name);
		strcpy((*current)->party,party);
	}else{
		if(strcmp((*current)->name,name)<0)
			insertNode(&((*current)->right),name,party);
		else if(strcmp((*current)->name,name)>0)
			insertNode(&((*current)->left),name,party);
	}
	return;
}
void elec(char name[],CandPtr current){
	if(current==NULL)
		return;
	else if(strcmp(current->name,name)<0)
		elec(name,current->right);
	else if(strcmp(current->name,name)>0)
		elec(name,current->left);
	else if(strcmp(current->name,name)==0)
		current->votes++;
}
int main()
{
	CandPtr root;
	int cases,i,n;
	char name[100],party[100];
	scanf("%d",&cases);
	while(cases--){
		root=NULL;
		scanf("%d ",&n);
		while(n--){
			fgets(name,100,stdin);
			fgets(party,100,stdin);
			name[strlen(name)-1]=0;
			party[strlen(party)-1]=0;
			insertNode(&root,name,party);
		}
		scanf("%d ",&n);
		while(n--){
			fgets(name,100,stdin);
			name[strlen(name)-1]=0;
			elec(name,root);
		}
		flag=0;
		max=0;
		inOrder(root);
		if(flag)
			puts("tie");
		else
			puts(winner);
		if(cases) puts("");
	}
	return 0;
}
