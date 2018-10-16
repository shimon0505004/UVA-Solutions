#include<stdio.h>
int main()
{
	char previous[25]={0},next[25]={0};
	int topo[26][26]={0};
	int alphabet[26]={0};
	int i,j,tot;
	scanf("%s",previous);
	while(1){
		memset(next,0,sizeof(next));
		scanf("%s",next);
		if(*next=='#') break;
		for(i=0;i<25;i++)
			if((previous[i]!=next[i])&&(previous[i]!=0)){
				alphabet[previous[i]-'A']=alphabet[next[i]-'A']=1;
				topo[previous[i]-'A'][next[i]-'A']=1;
				break;
			}
		memset(previous,0,sizeof(previous));
		sprintf(previous,"%s",next);
	}
	while(1){
		for(i=0;i<26;i++)
			if(alphabet[i]){
				tot=0;
				for(j=0;j<26;j++)
					tot+=topo[j][i];
				if(!tot){
					printf("%c",'A'+i);
					alphabet[i]=0;
					for(j=0;j<26;j++)
						topo[i][j]=0;
					break;
				}
			}
		if(i==26) break;
	}
	printf("\n");
	return 0;
}
