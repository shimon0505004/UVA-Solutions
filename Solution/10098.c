#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compar(const void *a,const void *b){
	return *((char *)a)-*((char *)b);
}
int main()
{
	char rank[15],temp;
	int len,mark,n;
	int i,j,k;
	scanf("%d",&n);
	while(n--){
		memset(rank,0,sizeof(rank));
		scanf("%s",rank);
		len=strlen(rank);
		qsort(rank,len,sizeof(char),compar);
		mark=0;
		puts(rank);
		for(;;){
			for(i=len-1;i>0;i--)
				if(rank[i]>rank[i-1]){
					for(j=len-1;j>=i;j--){
						if(rank[j]>rank[i-1]){
							temp=rank[j];
							rank[j]=rank[i-1];
							rank[i-1]=temp;
							break;
						}
					}
					mark=i;
					break;
				}
			if(!i) break;
			qsort(rank+mark,strlen(rank+mark),sizeof(char),compar);
			puts(rank);
		}
		puts("");
	}
	return 0;
}

