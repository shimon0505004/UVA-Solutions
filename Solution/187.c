#include<stdio.h>
#include<string.h>
int main()
{
	char name[1000][35];
	double money[1000][1000]={0},balance;
	int seqorder[1000]={0};
	int accorder[1000]={0};
	int account,sequence,i=0,j,l;
	while(scanf("%d",&account)){
		fgets(name[account],35,stdin);
		if(!account) break;
		accorder[i++]=account;
		name[account][strlen(name[account])-1]=0;
	}
	i=0;
	while(scanf("%3d%3d",&sequence,&account)){
		if(!i||seqorder[i-1]!=sequence)
			seqorder[i++]=sequence;
		scanf("%lf",&money[sequence][account]);
		money[sequence][account]/=100;
		if(!sequence) break;
	}
	for(j=0;j<i;j++){
		for(l=0,balance=0;accorder[l];l++)
			balance+=money[seqorder[j]][accorder[l]];
		if(balance){
			printf("*** Transaction %.3d is out of balance ***\n",seqorder[j]);
			for(l=0;accorder[l];l++)
				if(money[seqorder[j]][accorder[l]])
					printf("%.3d %-30s %10.2lf\n",accorder[l],name[accorder[l]],money[seqorder[j]][accorder[l]]);
			printf("%.3d %-30s %10.2lf\n\n",999,"Out of Balance",-balance);
		}
	}
	return 0;
}
