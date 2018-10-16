#include<stdio.h>
#include<string.h>
int main(){
	int G,i,j,len;
	char line[105];
	while(scanf("%d",&G),G){
		scanf("%s",line);
		len=strlen(line)/G;
		for(i=0;i<G;i++) for(j=i*len+len-1;j>=i*len;j--) putchar(line[j]);
		puts("");
	}
	return 0;
}
