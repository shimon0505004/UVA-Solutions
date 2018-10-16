#include<stdio.h>
#include<stdlib.h>
typedef struct QUEUE{
	struct QUEUE *next,*prev;
	int value;
}Queue;
typedef Queue *QueuePtr;
QueuePtr head,tail;
QueuePtr Teammate[1010];
int t[1000050];
void enqueue(int n){
	QueuePtr TeamPtr=Teammate[t[n]],newPtr;
	newPtr=(QueuePtr)malloc(sizeof(Queue)),newPtr->value=n;
	if(TeamPtr==NULL){
		newPtr->next=NULL;
		newPtr->prev=tail;
		if(head==NULL) head=newPtr;
		else tail->next=newPtr;
		tail=newPtr;
	}else{
		newPtr->next=TeamPtr->next;
		newPtr->prev=TeamPtr;
		TeamPtr->next=newPtr;
		if(newPtr->next==NULL) tail=newPtr;
		else newPtr->next->prev=newPtr;
	}
	Teammate[t[n]]=newPtr;
}
int dequeue(){
	int result=head->value;
	QueuePtr delPtr=head;
	head=head->next;
	free(delPtr);
	if(head==NULL) tail=NULL;
	else{
		head->prev=NULL;
		if(t[head->value]!=t[result])
			Teammate[t[result]]=NULL;
	}
	return result;
}
void clear(){
	QueuePtr delPtr=tail;
	if(delPtr==NULL) return;
	while(delPtr->prev!=NULL){
		delPtr=delPtr->prev;
		free(delPtr->next);
	}
	free(delPtr);
}
int main(){
	int Teams,elements,element,i,node,cases;
	char instr[10];
	for(cases=1;scanf("%d",&Teams),Teams;cases++){
		head=tail=NULL;
		for(i=0;i<Teams;i++){
			scanf("%d",&elements);
			while(elements--) scanf("%d",&element),t[element]=i;
			Teammate[i]=NULL;
		}
		printf("Scenario #%d\n",cases);
		while(scanf("%s",instr),*instr!='S'){
			if(*instr=='E'){
				scanf("%d",&node);
				enqueue(node);
			}else printf("%d\n",dequeue());
		}
		puts("");
		clear();
	}
	return 0;
}
