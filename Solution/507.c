#include<stdio.h>
int main(){
	int b,s;
	int cases,i;
	int seq,max,maxl,maxi;
	int begin[20005],so_far_max[20005];
	scanf("%d",&b);
	for(cases=1;cases<=b;cases++){
		scanf("%d",&s);
		begin[1]=1,so_far_max[1]=0;
		for(i=2;i<=s;i++){
			scanf("%d",&seq);
			if(so_far_max[i-1]<0) so_far_max[i]=seq,begin[i]=i-1;
			else so_far_max[i]=so_far_max[i-1]+seq,begin[i]=begin[i-1];
		}
		max=maxl=0;
		for(i=2;i<=s;i++){
			if(so_far_max[i]>max) max=so_far_max[i],maxl=i-begin[i],maxi=i;
			else if(so_far_max[i]==max&&i-begin[i]>maxl) max=so_far_max[i],maxl=i-begin[i],maxi=i;
		}
		if(max>0) printf("The nicest part of route %d is between stops %d and %d\n",cases,begin[maxi],maxi);
		else printf("Route %d has no nice parts\n",cases);
	}
	return 0;
}
