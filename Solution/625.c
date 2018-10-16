#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct TREE{
	struct TREE *left,*right;
	char id[45];
	int code;
};
char *keyword[16]={"var","end","for","then","else","case","goto","const",
	"label","while","begin","until","repeat","downto","function","procedure"};
int n_id;
struct TREE *root;
int find_id(struct TREE **now,char id[]){
	int cp;
	if(*now==NULL){
		*now=(struct TREE *)malloc(sizeof(struct TREE));
		strcpy((*now)->id,id);
		(*now)->left=(*now)->right=NULL;
		(*now)->code=n_id++;
		return -1;
	}
	cp=strcmp((*now)->id,id);
	if(cp>0) return find_id(&((*now)->left),id);
	if(cp<0) return find_id(&((*now)->right),id);
	return (*now)->code;
}
void printEncoded(char id[]){
	int i,t;
	for(i=0;i<16;i++)
		if(strcmp(id,keyword[i])==0){
			printf("&%d",i);
			return;
		}
	if((t=find_id(&root,id))==-1) printf(id);
	else printf("&%d",t);
}
int main(){
	int cases,len;
	char line[500],*ptr,id[45];
	scanf("%d%*c",&cases);
	while(cases--){
		scanf("%*c");
		root=NULL;
		n_id=16;
		while(fgets(line,500,stdin),strcmp(line,"end.\n")!=0){
			len=0;
			for(ptr=line;*ptr;ptr++){
				if(isalnum(*ptr)) id[len++]=*ptr;
				else{
					id[len]='\0';
					if(len<3) printf(id);
					else printEncoded(id);
					len=0;
					putchar(*ptr);
				}
			}
		}
		puts("&1.");
		if(cases) puts("");
	}
	return 0;
}
