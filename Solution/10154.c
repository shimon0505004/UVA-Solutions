#include<stdio.h>
#include<stdlib.h>
typedef struct TURTLE{
	int strength,weight;
}Turtle;
int compar(const void *a,const void *b){
	Turtle *t1=(Turtle *)a,*t2=(Turtle *)b;
	return t1->strength-t2->strength;
}
int main(){
	Turtle T[5610];
	int seq[5610],nowW,n_stack;
	int count,i,j,max,maxj;
	for(count=0;scanf("%d%d",&T[count].weight,&T[count].strength)==2;count++);
	qsort(T,count,sizeof(Turtle),compar);
	nowW=n_stack=0;
	for(i=0;i<count;i++){
		if(T[i].weight+nowW<=T[i].strength) seq[n_stack++]=i,nowW+=T[i].weight;
		else{
			for(j=0,max=maxj=-1;j<n_stack;j++)
				if(T[seq[j]].weight>max) max=T[seq[j]].weight,maxj=j;
			if(max>T[i].weight){
				seq[maxj]=i;
				nowW=nowW-max+T[i].weight;
			}
		}
	}
	printf("%d\n",n_stack);
	return 0;
}
