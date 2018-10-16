#include<stdio.h>
#include<string.h>
int main(){
	int i,cases;
	char fre[10000],enc[6000];
	int times1[128],times2[128],rank[128],map[128];
	int max,maxi,exit,n,count;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s%s",fre,enc);
		memset(times1,0,sizeof(times1));
		memset(times2,0,sizeof(times2));
		for(i=0;fre[i];i++) times1[fre[i]]++;
		for(i=0;enc[i];i++) times2[enc[i]]++;
		exit=0;
		n=0;
		while(1){
			exit=1;
			max=-1;
			for(i=0;i<128;i++)
				if(times1[i]){
					exit=0;
					if(times1[i]>max){
						max=times1[i];
						maxi=i;
					}
				}
			if(exit) break;
			rank[n++]=maxi;
			times1[maxi]=0;
		}
		count=0;
		while(1){
			exit=1;
			max=-1;
			for(i=0;i<128;i++)
				if(times2[i]){
					exit=0;
					if(times2[i]>max){
						max=times2[i];
						maxi=i;
					}
				}
			if(exit) break;
			times2[maxi]=0;
			map[maxi]=rank[count++];
		}
		for(i=0;enc[i];i++) printf("%c",map[enc[i]]);
		puts("");
		if(cases) puts("");
	}
	return 0;
}
