#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Ubound 4500
#define NAMELEN 20
#define LINELEN 250
struct AUTHOR{
	struct AUTHOR *adj;
	int n;
};
int find_author(char names[][NAMELEN],int *n_author,char find[]){
	int i;
	for(i=0;i<*n_author&&strcmp(names[i],find)!=0;i++);
	if(i==*n_author) strcpy(names[(*n_author)++],find);
	return i;
}
int queue[Ubound];
int head,tail;
void enqueue(int n){
	queue[head++]=n;
	head%=Ubound;
}
int dequeue(){
	int result=queue[tail++];
	tail%=Ubound;
	return result;
}
char is_empty(){
	return head==tail;
}
void addadj(struct AUTHOR *auth,int n){
	struct AUTHOR *tmp=auth->adj;
	auth->adj=(struct AUTHOR *)malloc(sizeof(struct AUTHOR));
	auth->adj->adj=tmp;
	auth->adj->n=n;
}
int main(){
	int T,P,N;
	int cases;
	struct AUTHOR author[Ubound];
	char names[Ubound][NAMELEN];
	char line[LINELEN];
	char visit[Ubound];
	int NO[Ubound],n_author,i,j;
	int Erdos[Ubound],Erdos_P;
	char temp1[Ubound],temp2[Ubound];
	scanf("%d",&T);
	for(cases=1;cases<=T;cases++){
		scanf("%d%d ",&P,&N);
		n_author=0;
		for(i=0;i<Ubound;i++) author[i].adj=NULL;
		memset(visit,0,sizeof(visit));
		memset(Erdos,0,sizeof(Erdos));
		while(P--){
			char *ptr,sep;
			int len,l;
			int n;
			fgets(line,LINELEN,stdin);
			for(n=0,ptr=line,sep=0;sep!=':';ptr+=len,n++){
				sscanf(ptr,"%s%s%n",temp1,temp2,&len);
				strcat(temp1,temp2);
				l=strlen(temp1);
				sep=temp1[l-1];
				temp1[l-1]=0;
				NO[n]=find_author(names,&n_author,temp1);
			}
			for(i=0;i<n;i++)
				for(j=0;j<i;j++)
					addadj(&author[NO[i]],NO[j]),addadj(&author[NO[j]],NO[i]);
		}
		head=tail=0;
		Erdos_P=find_author(names,&n_author,"Erdos,P.");
		enqueue(Erdos_P);
		visit[Erdos_P]=1;
		while(!is_empty()){
			int now=dequeue();
			struct AUTHOR *ptr;
			for(ptr=author[now].adj;ptr!=NULL;ptr=ptr->adj)
				if(visit[ptr->n]==0){
					visit[ptr->n]=1;
					enqueue(ptr->n);
					Erdos[ptr->n]=Erdos[now]+1;
				}
		}
		printf("Scenario %d\n",cases);
		while(N--){
			int n;
			fgets(line,LINELEN,stdin);
			printf("%.*s ",strlen(line)-1,line);
			sscanf(line,"%s%s",temp1,temp2);
			strcat(temp1,temp2);
			n=find_author(names,&n_author,temp1);
			if(visit[n]==0) puts("infinity");
			else printf("%d\n",Erdos[n]);
		}
		for(i=0;i<n_author;i++){
			struct AUTHOR *ptr=author[i].adj,*tmp;
			while(ptr!=NULL){
				tmp=ptr;
				ptr=ptr->adj;
				free(tmp);
			}
		}
	}
	return 0;
}
