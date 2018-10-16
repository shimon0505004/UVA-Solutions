#include<stdio.h>
#include<stdlib.h>
#define SIZE 260
typedef struct TREE{
	int n;
	struct TREE *left;
	struct TREE *right;
}Tree;
typedef Tree *TreePtr;
TreePtr queue[SIZE];
int h,t,flag;
void enqueue(TreePtr Ptr){
	if(Ptr!=NULL){
		queue[h++]=Ptr;
		h%=SIZE;
	}
}
TreePtr dequeue(){
	TreePtr result=queue[t++];
	t%=SIZE;
	return result;
}
char is_empty(){
	return h==t;
}
void clearQueue(){
	h=t=0;
}
void newNode(TreePtr *Ptr){
	(*Ptr)=(TreePtr)malloc(sizeof(Tree));
	(*Ptr)->left=NULL;
	(*Ptr)->right=NULL;
	(*Ptr)->n=0;
}
void insertNode(TreePtr *nowPtr,int n,char LR[]){
	if(*nowPtr==NULL) newNode(nowPtr);
	if(*LR==0){
		if((*nowPtr)->n) flag=1;
		(*nowPtr)->n=n;
	}else if(*LR=='L')
		insertNode(&((*nowPtr)->left),n,LR+1);
	else if(*LR=='R')
		insertNode(&((*nowPtr)->right),n,LR+1);
}
void clearTree(TreePtr ptr){
	if(ptr!=NULL){
		clearTree(ptr->left);
		clearTree(ptr->right);
	}
	free(ptr);
}
int main(){
	char LR[SIZE];
	TreePtr root,nowPtr;
	int n,t,seq[SIZE],count,i;
	while(!feof(stdin)){
		root=NULL;
		flag=0;
		clearQueue();
		clearTree(root);
		while((t=scanf(" %*c%d,%[^)]%*c",&n,LR))>0){
			if(t==1) insertNode(&root,n,""),scanf("%*c ");
			else insertNode(&root,n,LR);
		}
		scanf("%*c ");
		if(flag){
			puts("not complete");
			continue;
		}
		count=0;
		enqueue(root);
		while(!is_empty()){
			nowPtr=dequeue();
			if(nowPtr->n==0){
				flag=1;
				break;
			}
			seq[count++]=nowPtr->n;
			enqueue(nowPtr->left);
			enqueue(nowPtr->right);
		}
		if(flag)
			puts("not complete");
		else{
			printf("%d",seq[0]);
			for(i=1;i<count;i++) printf(" %d",seq[i]);
			puts("");
		}
	}
	return 0;
}
