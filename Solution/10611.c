#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	int ladies,queries,i,j;
	int H[50001],Luchu,count;
	int Lbound,Ubound,t,*find;
	scanf("%d",&ladies);
	scanf("%d",&H[0]);
	for(i=1,count=1;i<ladies;i++){
		scanf("%d",&H[count]);
		if(H[count]>H[count-1]) count++;
	}
	ladies=count;
	scanf("%d",&queries);
	for(i=0;i<queries;i++){
		scanf("%d",&Luchu);
		if(Luchu>H[ladies-1]) printf("%d X\n",H[ladies-1]);
		else if(Luchu<H[0]) printf("X %d\n",H[0]);
		else if((find=(int *)bsearch(&Luchu,H,ladies,sizeof(int),compar))!=NULL){
			if(find==H) printf("X %d\n",find[1]);
			else if(find==H+ladies) printf("%d X\n",find[-1]);
			else printf("%d %d\n",find[-1],find[1]);
		}else{
			Lbound=0,Ubound=ladies;
			while(Lbound+1<Ubound){
				t=(Lbound+Ubound)>>1;
				if(H[t]<Luchu) Lbound=t;
				else Ubound=t;
			}
			printf("%d %d\n",H[Lbound],H[Ubound]);
		}
	}
	return 0;
}
