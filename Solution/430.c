#include<stdio.h>
#include<string.h>
int main(){
	int P;
	int vote[30];
	int table[10000],n_vote,pass_vote;
	int nowP,i,j;
	char line[85],*ptr;
	int len;
	while(fgets(line,85,stdin)!=NULL){
		ptr=line;
		sscanf(ptr,"%d%n",&pass_vote,&len);
		ptr+=len;
		for(P=0;sscanf(ptr,"%d%n",&vote[P],&len)==1;P++,ptr+=len);
		n_vote=0;
		for(nowP=0;nowP<P;nowP++){
			int temp,p_index=0;
			if(nowP) putchar(' ');
			memset(table,0,sizeof(table));
			table[0]=1;
			temp=vote[nowP],vote[nowP]=vote[0],vote[0]=temp;
			for(i=1;i<P;i++)
				for(j=pass_vote-vote[i];j>=0;j--)
					table[j+vote[i]]+=table[j];
			for(i=pass_vote-vote[0];i<pass_vote;i++)
				p_index+=table[i];
			printf("%d",p_index);
		}
		puts("");
	}
	return 0;
}
