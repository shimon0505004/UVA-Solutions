#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
int main()
{
	int n,i;
	int minpsb,inputpsb,allpsb,maxpsb;
	int seq[1000005];
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%d",&seq[i]);
		qsort(seq,n,sizeof(int),compar);
		if(n%2==1){
			minpsb=seq[n/2];
			inputpsb=allpsb=1;
			for(i=n/2+1;seq[i]==minpsb&&i<n;i++) inputpsb++;
			for(i=n/2-1;seq[i]==minpsb&&i>=0;i--) inputpsb++;
		}else{
			minpsb=seq[n/2-1];
			maxpsb=seq[n/2];
			inputpsb=2;
			allpsb=maxpsb-minpsb+1;
			for(i=n/2+1;seq[i]==maxpsb&&i<n;i++) inputpsb++;
			for(i=n/2-2;seq[i]==minpsb&&i>=0;i--) inputpsb++;
		}
		printf("%d %d %d\n",minpsb,inputpsb,allpsb);
	}
	return 0;
}
