#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(x,y) ((x)>(y)?(y):(x))
typedef struct tree{
	char name[35];
	int NO;
	struct tree* left;
	struct tree* right;
}Cargo;
typedef Cargo *CargoPtr;
int count;
void newPtr(CargoPtr *Ptr){
	(*Ptr)=(CargoPtr)malloc(sizeof(Cargo));
	(*Ptr)->left=NULL;
	(*Ptr)->right=NULL;
}
int searchNode(CargoPtr *Ptr,char name[]){
	if(*Ptr==NULL){
		newPtr(Ptr);
		strcpy((*Ptr)->name,name);
		(*Ptr)->NO=count;
		return count++;
	}
	if(strcmp(name,(*Ptr)->name)>0)
		return searchNode(&((*Ptr)->right),name);
	if(strcmp(name,(*Ptr)->name)<0)
		return searchNode(&((*Ptr)->left),name);
	return (*Ptr)->NO;
}
int main(){
	int n,r,i,j,k,cases=0;
	while(scanf("%d%d",&n,&r),n){
		char name1[35],name2[35];
		int road[205][205]={0},c1,c2,t,load;
		CargoPtr root=NULL;
		root=NULL;
		count=0;
		while(r--){
			scanf("%s%s%d",name1,name2,&load);
			c1=searchNode(&root,name1);
			c2=searchNode(&root,name2);
			road[c1][c2]=road[c2][c1]=load;
		}
		for(k=0;k<count;k++)
			for(i=0;i<count;i++)
				for(j=0;j<i;j++)
					if(road[i][j]<(t=min(road[i][k],road[k][j])))
						road[i][j]=road[j][i]=t;
		scanf("%s%s",name1,name2);
		c1=searchNode(&root,name1);
		c2=searchNode(&root,name2);
		printf("Scenario #%d\n",++cases);
		printf("%d tons\n\n",road[c1][c2]);
	}
	return 0;
}
