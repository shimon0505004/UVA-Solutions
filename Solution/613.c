#include<stdio.h>
#include<string.h>
void inventory(char *des,char *src){
	int count[10]={0};
	int i,len=strlen(src),inc;
	char *ptr;
	for(i=0;i<len;i++)
		count[src[i]-'0']++;
	for(i=0,ptr=des;i<10;i++)
		if(count[i]!=0){
			inc=sprintf(ptr,"%d%d",count[i],i);
			ptr+=inc;
		}
}
int main(){
	char loop[20][25];
	char input[81];
	int i,j;
	while(scanf("%s",input),*input!='-'){
		printf(input);
		strcpy(loop[0],input);
		for(i=1;i<=15;i++){
			inventory(loop[i],loop[i-1]);
			for(j=i-1;j>=0;j--)
				if(strcmp(loop[i],loop[j])==0)
					break;
			if(j>=0) break;
		}
		if(i>15)
			puts(" can not be classified after 15 iterations");
		else if(j==i-1)
			if(j==0)
				puts(" is self-inventorying");
			else
				printf(" is self-inventorying after %d steps\n",j);
		else
			printf(" enters an inventory loop of length %d\n",i-j);
	}
	return 0;
}
