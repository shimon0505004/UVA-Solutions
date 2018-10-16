#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int len;
int dis(char *a,char *b){
	int distance=0,i;
	for(i=0;i<len;i++)
		if(a[i]!=b[i]) distance++;
	return distance;
}
int main(){
	int i,n;
	char **morph;
	char *temp;
	while(scanf("%d%d",&n,&len)==2){
		morph=(char **)calloc(n,sizeof(char *));
		morph[0]=(char *)calloc(len+1,sizeof(char));
		scanf("%s",morph[0]);
		for(i=1;i<n;i++){
			temp=(char *)calloc(len+1,sizeof(char));
			scanf("%s",temp);
			morph[dis(morph[0],temp)]=temp;
		}
		for(i=0;i<n;i++)
			puts(morph[i]);
	}
	return 0;
}
