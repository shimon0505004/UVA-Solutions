#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TRAVELLER{
	char name[30];
	int debt;
};
int find_name(struct TRAVELLER tvl[],char name[]){
	int n;
	for(n=0;strcmp(tvl[n].name,name);n++);
	return n;
}
int main(){
	int N,n_trans,i,tvl1,tvl2;
	int cases,borrow,min,min1,min2;
	char traveller1[30],traveller2[30];
	struct TRAVELLER tvl[25];
	for(cases=1;scanf("%d%d",&N,&n_trans),N|n_trans;cases++){
		memset(tvl,0,sizeof(tvl));
		for(i=0;i<N;i++) scanf("%s",tvl[i].name);
		while(n_trans--){
			scanf("%s%s%d",traveller1,traveller2,&borrow);
			tvl1=find_name(tvl,traveller1),tvl2=find_name(tvl,traveller2);
			tvl[tvl1].debt-=borrow,tvl[tvl2].debt+=borrow;
		}
		printf("Case #%d\n",cases);
		for(;;){
			min=2147483647;
			for(i=0;i<N;i++)
				if(tvl[i].debt!=0&&abs(tvl[i].debt)<min)
					min=abs(tvl[i].debt),min1=i;
			if(min==2147483647) break;
			if(tvl[min1].debt>0){
				min=2147483647;
				for(i=0;i<N;i++)
					if(tvl[i].debt<0&&-tvl[i].debt<min)
						min=-tvl[i].debt,min2=i;
				printf("%s %s %d\n",tvl[min1].name,tvl[min2].name,tvl[min1].debt);
				tvl[min2].debt+=tvl[min1].debt,tvl[min1].debt=0;
			}else{
				min=2147483647;
				for(i=0;i<N;i++)
					if(tvl[i].debt>0&&tvl[i].debt<min)
						min=tvl[i].debt,min2=i;
				printf("%s %s %d\n",tvl[min2].name,tvl[min1].name,-tvl[min1].debt);
				tvl[min2].debt+=tvl[min1].debt,tvl[min1].debt=0;
			}
		}
		puts("");
	}
	return 0;
}
