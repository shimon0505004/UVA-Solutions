#include<stdio.h>
#include<string.h>
int main(){
	int cases,P,neigh;
	int ans[1005],foo,min,i,count;
	char input[5000],*ptr;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d ",&P);
		min=P;
		for(i=1;i<=P;i++){
			fgets(input,5000,stdin);
			for(neigh=0,ptr=input;(ptr=strchr(ptr,' '))!=NULL;neigh++,ptr++);
			if(min>neigh){
				min=neigh;
				ans[0]=i,count=1;
			}else if(min==neigh)
				ans[count++]=i;
				
		}
		printf("%d",ans[0]);
		for(i=1;i<count;i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}
