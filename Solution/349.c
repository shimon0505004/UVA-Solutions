#include<stdio.h>
#include<string.h>
char bad_ballot(int ballot[],int c){
	int visit[6]={0};
	int i;
	for(i=0;i<c;i++){
		if(ballot[i]>c||ballot[i]<1) return 1;
		if(visit[ballot[i]]) return 1;
		visit[ballot[i]]=1;
	}
	return 0;
}
char duplicate(int votes[],int max,int c){
	char flag=0;
	int i;
	for(i=1;i<=c;i++)
		if(votes[i]==max){
			if(flag) return 1;
			else flag=1;
		}
	return 0;
}
int main(){
	int c,n,i,j;
	int ballot[105][5];
	int votes[6];
	int cases,n_bad_ballot;
	int max,min,mini,maxi;
	for(cases=1;scanf("%d%d",&c,&n),c|n;cases++){
		for(i=0;i<n;i++) for(j=0;j<c;j++) scanf("%d",&ballot[i][j]);
		n_bad_ballot=0;
		for(i=0;i<n;i++) if(bad_ballot(ballot[i],c)) n_bad_ballot++,memmove(&ballot[i],&ballot[--n],sizeof(int[5]));
		memset(votes,0,sizeof(votes));
		for(i=0;i<n;i++) votes[ballot[i][0]]++;
		max=-1,min=105;
		for(i=1;i<=c;i++){
			if(votes[i]>max) max=votes[i];
			if(votes[i]<min) min=votes[i],mini=i;
		}
		if(max*2<=n&&max!=min)
			for(i=0;i<n;i++) if(ballot[i][0]==mini) votes[ballot[i][1]]++;
		for(i=1;i<=c;i++) if(votes[i]>=max) max=votes[i],maxi=i;
		printf("Election #%d\n",cases);
		if(n_bad_ballot>0) printf("   %d bad ballot(s)\n",n_bad_ballot);
		if(duplicate(votes,max,c)){
			printf("   The following candidates are tied:");
			for(i=1;i<=c;i++) if(votes[i]==max) printf(" %d",i);
			puts("");
		}else printf("   Candidate %d is elected.\n",maxi);
	}
	return 0;
}
