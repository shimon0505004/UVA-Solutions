#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char word[55];
	struct node *prev;
	struct node *next;
}Compress;
typedef Compress *CompPtr;
CompPtr head=NULL;
void newnode(CompPtr *Ptr){
	(*Ptr)=(CompPtr)malloc(sizeof(Compress));
	(*Ptr)->prev=NULL;
	(*Ptr)->next=NULL;
}
void insertNode(CompPtr *Ptr,char string[]){
	if((*Ptr)==NULL){
		newnode(Ptr);
		strcpy((*Ptr)->word,string);
	}else{
		insertNode(&((*Ptr)->prev),string);
		(*Ptr)->prev->next=(*Ptr);
		head=(*Ptr)->prev;
	}
}
void decompress(int n){
	CompPtr Ptr,tempPtr;
	int i;
	for(Ptr=head,i=1;i<n;Ptr=Ptr->next,i++);
	printf("%s",Ptr->word);
	if(Ptr->next!=NULL)
		Ptr->next->prev=Ptr->prev;
	if(Ptr->prev!=NULL)
		Ptr->prev->next=Ptr->next;
	tempPtr=head;
	head=Ptr;
	Ptr->next=tempPtr;
	tempPtr->prev=Ptr;
	Ptr->prev=NULL;
}
int main()
{
	char temp[500];
	int n;
	if(scanf("%[^A-Za-z]",temp)==1)
		printf("%s",temp);
	while(scanf("%[A-Za-z]",temp)==1){
		printf("%s",temp);
		insertNode(&head,temp);
		if(scanf("%[^0-9A-Za-z]",temp)==1)
			printf("%s",temp);
		while(scanf("%d",&n)==1){
			if(!n) return 0;
			if(n==1) printf("%s",head->word);
			else decompress(n);
			if(scanf("%[^0-9A-Za-z]",temp)==1)
				printf("%s",temp);
		}
	}
	return 0;
}
