#include<stdio.h>
int main(){
	char string[1024],start=0;
	int i,n,times[128]={0},min=1024,mini=0,max=-1;
	while(fgets(string,1024,stdin)!=NULL){
		string[strlen(string)-1]=0;
		min=1024;
		max=-1;
		if(start) puts("");
		else start=1;
		for(i=0;i<128;i++)
			times[i]=0;
		for(i=0;i<strlen(string);i++)
			times[string[i]]++;
		while(max!=0){
			min=1024;
			max=-1;
			for(i=0;i<128;i++)
				if(min>=times[i]&&times[i]>0){
					min=times[i];
					mini=i;
				}
			if(min==1024) break;
			printf("%d %d\n",mini,times[mini]);
			times[mini]=0;
			for(i=0;i<128;i++)
				max=(max<times[i]?times[i]:max);
		}
	}
	return 0;
}
