#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct queueNode{
	int data;
	struct queueNode *nextPtr;
	struct queueNode *previousPtr;
};
typedef struct queueNode Queue;
typedef Queue *QueuePtr;
void enqueue(QueuePtr *,QueuePtr *,int);
int dequeue(QueuePtr *Ptr);
int main()
{
	int i,n,count,result,rest;
	QueuePtr headPtr,tailPtr,tempPtr;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		for(count=1;;count++){
			headPtr=NULL;
			tailPtr=NULL;
			for(i=1;i<=n;i++)
				enqueue(&headPtr,&tailPtr,i);
			tailPtr->nextPtr=headPtr;
			headPtr->previousPtr=tailPtr;
			tempPtr=headPtr;
			rest=n;
			while(rest>1){
				headPtr=tempPtr->previousPtr;
				if(dequeue(&tempPtr)==13) break;
				rest--;
				tempPtr=headPtr;
				for(i=0;i<(count%rest);i++)
					tempPtr=tempPtr->nextPtr;
			}
			if(rest==1){
				result=count;
				break;
			}
			else
				while(tempPtr!=NULL){
					tempPtr=headPtr->nextPtr;
					dequeue(&headPtr);
				}
		}
		printf("%d\n",result);
	}
	return 0;
}
void enqueue(QueuePtr *headPtr,QueuePtr *tailPtr,int data)
{
	QueuePtr newPtr;
	newPtr=malloc(sizeof(Queue));
	newPtr->data=data;
	newPtr->nextPtr=NULL;
	newPtr->previousPtr=(*tailPtr);
	if((*headPtr)==NULL)
		(*headPtr)=newPtr;
	else
		(*tailPtr)->nextPtr=newPtr;
	(*tailPtr)=newPtr;
	return; 
}
int dequeue(QueuePtr *Ptr)
{
	int data;
	QueuePtr tempPtr;
	data=(*Ptr)->data;
	if((*Ptr)->nextPtr!=(*Ptr)){
		(*Ptr)->previousPtr->nextPtr=(*Ptr)->nextPtr;
		(*Ptr)->nextPtr->previousPtr=(*Ptr)->previousPtr;
	}
	free(*Ptr);
	(*Ptr)=NULL;
	return data;
}
