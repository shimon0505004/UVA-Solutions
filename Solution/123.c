#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct DICT{
	char word[15];
	struct DICT *left,*right;
}Dict;
typedef Dict *TreePtr;
int compar(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
void insertNode(TreePtr *ptr,char word[]){
	if((*ptr)==NULL){
		(*ptr)=(TreePtr)malloc(sizeof(Dict));
		(*ptr)->left=(*ptr)->right=NULL;
		strcpy((*ptr)->word,word);
	}else if(strcmp(word,(*ptr)->word)>0)
		insertNode(&((*ptr)->right),word);
	else if(strcmp(word,(*ptr)->word)<0)
		insertNode(&((*ptr)->left),word);
	return;
}
void inOrder(TreePtr now,char Title[][10005],int titles){
	int i,j,len;
	char temp[10005],*ptr;
	if(now==NULL) return;
	inOrder(now->left,Title,titles);
	len=strlen(now->word);
	for(i=0;i<titles;i++){
		strcpy(temp,Title[i]);
		for(ptr=temp;(ptr=strstr(ptr,now->word))!=NULL;){
			if(ptr!=temp&&isalpha(*(ptr-1))){
				ptr+=len;
				continue;
			}
			if(isalpha(*(ptr+strlen(now->word)))){
				ptr+=len;
				continue;
			}
			for(j=0;j<len;j++)
				ptr[j]=toupper(ptr[j]);
			printf(temp);
			for(j=0;j<len;j++)
				ptr[j]=tolower(ptr[j]);
			ptr+=len;
		}
	}
	inOrder(now->right,Title,titles);
	free(now);
}
int main(){
	char skip[55][15];
	char Title[205][10005];
	char input[100],*ptr,word[15];
	int ignore,titles,len,i;
	TreePtr root=NULL;
	for(ignore=0;scanf("%s",skip[ignore]),strcmp(skip[ignore],"::");ignore++);
	qsort(skip,ignore,sizeof(char[15]),compar);
	scanf(" ");
	for(titles=0;fgets(Title[titles],10005,stdin)!=NULL;titles++){
		len=strlen(Title[titles]);
		for(i=0;i<len;i++) Title[titles][i]=tolower(Title[titles][i]);
		for(ptr=Title[titles];sscanf(ptr,"%s%n",word,&len)==1;ptr+=len)
			if(bsearch(word,skip,ignore,sizeof(char[15]),compar)==NULL)
				insertNode(&root,word);
	}
	inOrder(root,Title,titles);
	return 0;
}
