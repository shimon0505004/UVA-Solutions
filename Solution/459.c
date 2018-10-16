#include<stdio.h>
int size;
void del(char Graph[][26],int pos){
	int i;
	for(i=0;i<size;i++)
		if(Graph[pos][i]){
			Graph[pos][i]=0;
			Graph[i][pos]=0;
			del(Graph,i);
		}
}
int main()
{
	int i,result,cases;
	char max[3];
	char nodes[5];
	char Graph[26][26];
	scanf("%d ",&cases);
	while(cases--){
		fgets(max,3,stdin);
		size=*max-'A'+1;
		memset(Graph,0,sizeof(Graph));
		for(i=0;i<26;i++)
			Graph[i][i]=1;
		while(fgets(nodes,5,stdin)!=NULL){
			if(*nodes=='\n') break;
			Graph[nodes[0]-'A'][nodes[1]-'A']=1;
			Graph[nodes[1]-'A'][nodes[0]-'A']=1;
		}
		result=0;
		for(i=0;i<size;i++){
			if(Graph[i][i]){
				del(Graph,i);
				Graph[i][i]=0;
				result++;
			}
		}
		printf("%d\n",result);
		if(cases) puts("");
	}
	return 0;
}
