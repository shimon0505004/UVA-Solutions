#include<stdio.h>
int main()
{
	int cases,divide,box,smaller,i,j,k,all; 
	int inner,candy;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d%d",&divide,&box);
		all=0;
		for(j=0;j<box;j++){
			candy=1;
			scanf("%d",&smaller);
			for(k=0;k<smaller;k++){
				scanf("%d",&inner);
				candy*=(inner%divide);
				candy%=divide;
			}
			all+=(candy%divide);
		}
		printf("%d\n",all%divide);
	}
	return 0;
}
