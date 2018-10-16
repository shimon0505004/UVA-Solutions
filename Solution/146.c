#include<stdio.h>
#include<string.h>
int main()
{
	char rank[55],temp;
	int i,len,mark,j;
	while(1){
		memset(rank,0,sizeof(rank));
		scanf("%s",rank);
		if(*rank=='#') break;
		len=strlen(rank);
		mark=0;
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
		if(mark){
			for(i=mark;i<len-1;i++)
				for(j=mark;j<len+mark-i-1;j++)
					if(rank[j]>rank[j+1]){
						temp=rank[j];
						rank[j]=rank[j+1];
						rank[j+1]=temp;
					}
			printf("%s\n",rank);
		}
		else
			printf("No Successor\n");
	}
	return 0;
}
