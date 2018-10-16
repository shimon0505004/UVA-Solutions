#include<stdio.h>
#include<stdlib.h>
int compar(const void *a,const void *b){
	if(*((int *)a)<=0&&*((int *)b)<=0)
		return *((int *)a+1)-*((int *)b+1);
	return *((int *)a)-*((int *)b);
}
int main()
{
	int cases,M,i,n,L,R,count;
	int seg[100005][2];
	int answer[100005];
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&M);
		for(n=0;scanf("%d%d",&seg[n][0],&seg[n][1])==2;n++){
			if(!(seg[n][0]+seg[n][1])) break;
			if(seg[n][0]>=M||seg[n][1]<=0){
				n--;
				continue;
			}
		}
		qsort(seg,n,2*sizeof(int),compar);
		count=R=0;
		for(i=0;seg[i][0]<=0&&i<n;i++)
			if(seg[i][1]>R) R=seg[i][1],answer[0]=i;
		if(!i){
			puts("0");
			continue;
		}
		while(seg[answer[count]][1]<M){
			for(;seg[i][0]<=seg[answer[count]][1]&&i<n;i++)
				if(seg[i][1]>R) R=seg[i][1],answer[count+1]=i;
			count++;
		}
		if(seg[answer[count]][1]<M){
			puts("0");
			continue;
		}
		printf("%d\n",++count);
		for(i=0;i<count;i++)
			printf("%d %d\n",seg[answer[i]][0],seg[answer[i]][1]);
	}
	return 0;
}
