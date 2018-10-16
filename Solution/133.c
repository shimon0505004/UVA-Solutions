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
	int i,n,count,result,rest,k,m;
	QueuePtr headPtr,tailPtr,tempmPtr,tempkPtr,mPtr,kPtr;
	while(scanf("%d%d%d",&n,&k,&m)==3&&(n+k+m)){
		if(!n) break;
		headPtr=NULL;
		tailPtr=NULL;
		for(i=1;i<=n;i++)
			enqueue(&headPtr,&tailPtr,i);
		tailPtr->nextPtr=headPtr;
		headPtr->previousPtr=tailPtr;
		rest=n;
		tempkPtr=headPtr->previousPtr;
		tempmPtr=headPtr;
		while(rest>0){
			kPtr=tempkPtr;
			for(i=0;i<(k%rest);i++)
				kPtr=kPtr->nextPtr;
			tempkPtr=kPtr->previousPtr;
			mPtr=tempmPtr;
			for(i=0;i<(m%rest);i++)
				mPtr=mPtr->previousPtr;
/*			printf("mPtr=%d\n",mPtr->data);*/
			tempmPtr=mPtr->nextPtr;
			if(kPtr!=mPtr){
				if(kPtr==tempmPtr)
					tempmPtr=tempmPtr->nextPtr;
				printf("%3d",dequeue(&kPtr));
				rest--;
			}
			if(mPtr==tempkPtr)
				tempkPtr=tempkPtr->previousPtr;
			printf("%3d",dequeue(&mPtr));
			rest--;
			if(rest) printf(",");
		}
		printf("\n");
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
