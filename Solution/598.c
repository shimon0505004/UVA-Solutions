#include<stdio.h>
#include<string.h>
int DEPTH,n;
char output[15][35];
void dfs(char news[][35],int pos,int depth){
	int i;
	if(depth==DEPTH){
		printf(output[0]);
		for(i=1;i<DEPTH;i++)
			printf(", %s",output[i]);
		puts("");
		return;
	}
	for(i=pos;i<n-DEPTH+1+depth;i++){
		strcpy(output[depth],news[i]);
		dfs(news,i+1,depth+1);
	}
}
int main()
{
	int cases,i,a,*b;
	char need[10];
	char news[15][35];
	scanf("%d ",&cases);
	while(cases--){
		fgets(need,10,stdin);
		b=(int *)malloc(sizeof(int));
		switch(sscanf(need,"%d%d",&a,b)){
			case 0:
				a=1,b=&n;
				break;
			case 1:
				*b=a;
				break;
		}
		for(n=0;fgets(news[n],35,stdin)!=NULL&&*news[n]!='\n';n++)
			news[n][strlen(news[n])-1]=0;
		for(i=a;i<=(*b);i++){
			printf("Size %d\n",i);
			DEPTH=i;
			dfs(news,0,0);
			puts("");
		}
		if(cases) puts("");
	}
	return 0;
}
