#include<stdio.h>
#include<string.h>
struct CARPET{
	char incor,cor;
	char is_acc;
};
int main(){
	int N,i,j,sum,step;
	int table[26][35];
	struct CARPET carpet[26];
	while(scanf("%d",&N)==1){
		for(i=0;i<N;i++){
			scanf(" %*c %c %c %c",&(carpet[i].incor),&(carpet[i].cor),&(carpet[i].is_acc));
			carpet[i].incor-='A',carpet[i].cor-='A';
		}
		scanf("%d",&step);
		memset(table,0,sizeof(table));
		table[0][0]=1;
		for(i=1;i<=step;i++)
			for(j=0;j<N;j++)
				table[carpet[j].incor][i]+=table[j][i-1],table[carpet[j].cor][i]+=table[j][i-1];
		sum=0;
		for(i=0;i<N;i++)
			if(carpet[i].is_acc=='x')
				sum+=table[i][step];
		printf("%d\n",sum);
	}
	return 0;
}
