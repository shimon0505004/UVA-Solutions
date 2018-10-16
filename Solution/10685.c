#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
struct UNION{
	int parent,size;
};
int compar(const void *a,const void *b){
	char *s1=(char *)a,*s2=(char *)b;
	return strcmp(s1,s2);
}
int find_name(char creature[][35],char name[],int C){
	char (*s)[35]=bsearch(name,creature,C,sizeof(char[35]),compar);
	return s-creature;
}
struct UNION u[5005];
int find_root(int n){
	if(u[n].parent!=n) u[n].parent=find_root(u[n].parent);
	return u[n].parent;
}
void link(int a,int b){
	if(u[a].size>u[b].size){
		u[b].parent=a;
		u[a].size+=u[b].size;
	}else{
		u[a].parent=b;
		u[b].size+=u[a].size;
	}
}
int main(){
	int C,R,i;
	char creature[5005][35];
	int max;
	while(scanf("%d%d",&C,&R),C||R){
		for(i=0;i<C;i++) u[i].parent=i,u[i].size=1;
		for(i=0;i<C;i++) scanf("%s",creature[i]);
		qsort(creature,C,sizeof(char[35]),compar);
		while(R--){
			char name1[35],name2[35];
			int n1,n2,r1,r2;
			scanf("%s%s",name1,name2);
			n1=find_name(creature,name1,C),n2=find_name(creature,name2,C);
			r1=find_root(n1),r2=find_root(n2);
			if(r1!=r2) link(r1,r2);
		}
		for(i=max=0;i<C;i++) max=MAX(max,u[find_root(i)].size);
		printf("%d\n",max);
	}
	return 0;
}
