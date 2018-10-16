#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct word{
	char name[55];
	struct word *leftword;
	struct word *rightword;
}Dict;
char answer[55];
int max,count;
typedef Dict *DictPtr;
void inOrder(DictPtr wordPtr)
{
	if(wordPtr!=NULL){
		inOrder(wordPtr->leftword);
		if(strlen(wordPtr->name)==max) puts(wordPtr->name);
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
		count++;
	}else{
		if(strcmp((*current)->name,temp)<0)
			insertNode(&((*current)->rightword),temp);
		else if(strcmp((*current)->name,temp)>0)
			insertNode(&((*current)->leftword),temp);
	}
	return;
}
int main()
{
	char alphabet[26];
	char words[55];
	int F,N,f,i,finger,len;
	DictPtr root;
	while(scanf("%d%d",&F,&N)==2){
		memset(alphabet,0,sizeof(alphabet));
		while(F--){
			scanf("%d",&finger);
			switch(finger){
				case 1:
					alphabet['q'-'a']=1;
					alphabet['a'-'a']=1;
					alphabet['z'-'a']=1;
					break;
				case 2:
					alphabet['w'-'a']=1;
					alphabet['s'-'a']=1;
					alphabet['x'-'a']=1;
					break;
				case 3:
					alphabet['e'-'a']=1;
					alphabet['d'-'a']=1;
					alphabet['c'-'a']=1;
					break;
				case 4:
					alphabet['r'-'a']=1;
					alphabet['f'-'a']=1;
					alphabet['v'-'a']=1;
					alphabet['t'-'a']=1;
					alphabet['g'-'a']=1;
					alphabet['b'-'a']=1;
					break;
				case 7:
					alphabet['y'-'a']=1;
					alphabet['h'-'a']=1;
					alphabet['n'-'a']=1;
					alphabet['u'-'a']=1;
					alphabet['j'-'a']=1;
					alphabet['m'-'a']=1;
					break;
				case 8:
					alphabet['i'-'a']=1;
					alphabet['k'-'a']=1;
					break;
				case 9:
					alphabet['o'-'a']=1;
					alphabet['l'-'a']=1;
					break;
				case 10:
					alphabet['p'-'a']=1;
					break;
			}
		}
		root=NULL;
		max=count=0;
		while(N--){
			scanf("%s",words);
			len=strlen(words);
			for(i=0;i<len;i++)
				if(alphabet[words[i]-'a']) break;
			if(i==len){
				if(len>max){
					max=len;
					count=0;
				}else if(len<max) continue;
				insertNode(&root,words);
			}
		}
		printf("%d\n",count);
		inOrder(root);
	}
	return 0;
}
