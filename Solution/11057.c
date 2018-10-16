#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main(){
	char array[1000005];
	int books[10005];
	int allowance,mini;
	int n,i;
	while(scanf("%d",&n)==1){
		memset(array,0,sizeof(array));
		for(i=0;i<n;i++) scanf("%d",&books[i]),array[books[i]]++;
		scanf("%d",&allowance);
		qsort(books,n,sizeof(int),compar);
		for(i=0;allowance-books[i]>1000000;i++);
		for(;i<n&&2*books[i]<=allowance;i++)
			if(2*books[i]==allowance){
				if(array[books[i]]>1) mini=i;
			}else if(array[books[i]]&&array[allowance-books[i]]) mini=i;
		printf("Peter should buy books whose prices are %d and %d.\n\n",books[mini],allowance-books[mini]);
	}
	return 0;
}
