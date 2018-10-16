#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Ubound 30 
int max,maxj;
int predecessor[Ubound];
int dim,cases,flag;
struct b{
	int box[10];
	int order;
};
struct b B[Ubound];
int cmp(const void *a,const void *b)
{
	return *((int *)a)-*((int *)b);
}
char is_nesting(int *box1,int *box2,int dim)
{
	int i;
	for(i=0;i<dim;i++) if(box1[i]>=box2[i]) return 0;
	return 1;
}
int FindLIS()
{
	int length[Ubound];
	int i,j;
	max=1,maxj=0;
	for(i=0;i<cases;i++){
		predecessor[i]=-1;
		length[i]=1;
	}
	for(i=0;i<cases-1;i++)
		for(j=i+1;j<cases;j++)
			if(is_nesting(B[i].box,B[j].box,dim))
				if(length[i]>=length[j]){
					length[j]=length[i]+1;
					if(length[j]>max){
						max=length[j];
						maxj=j;
					}
					predecessor[j]=i;
				}
	return max;
}
void printLIS(int current)
{
	if(current<0) return;
	printLIS(predecessor[current]);
	if(flag) putchar(' ');
	flag=1;
	printf("%d",B[current].order);
}
int main()
{
	int i,j;
	while(scanf("%d%d",&cases,&dim)==2){
		for(i=0;i<cases;i++){
			for(j=0;j<dim;j++){
				scanf("%d",&B[i].box[j]);
				B[i].order=i+1;
			}
			qsort(B[i].box,dim,sizeof(int),cmp);
		}
		qsort(&B,cases,sizeof(struct b),cmp);
#ifdef RANK
		for(i=0;i<cases;i++){
			for(j=0;j<dim;j++)
				printf("%2d ",B[i].box[j]);
			printf("order:%d\n",B[i].order);
			puts("");
		}
#endif
		memset(predecessor,0,sizeof(predecessor));
		printf("%d\n",FindLIS());
		flag=0;
		printLIS(maxj);
		puts("");
	}
	return 0;
}
