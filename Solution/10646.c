#include<stdio.h>
int main(){
	int cases,i,j;
	char card[3],ans[3];
	scanf("%d",&cases);
	for(i=1;i<=cases;i++){
		for(j=0;j<52;j++){
			scanf("%s",card);
			if(j==32) strcpy(ans,card);
		}
		printf("Case %d: %s\n",i,ans);
	}
	return 0;
}
