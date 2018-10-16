#include<stdio.h>
#include<string.h>
int main()
{
	char sentence[105][105]={0};
	int i,j,count,len,maxlen;
	for(i=0;;i++){
		if(fgets(sentence[i],105,stdin)==NULL){
			count=i;
			break;
		}
		sentence[i][strlen(sentence[i])-1]=0;
	}
	
	for(i=1,maxlen=strlen(sentence[0]);i<count;i++){
		len=strlen(sentence[i]);
		maxlen=len>maxlen?len:maxlen;
	}
	for(i=0;i<count;i++)
		for(j=strlen(sentence[i]);j<maxlen;j++)
			sentence[i][j]=' ';
	for(i=0;i<maxlen;i++){
		for(j=count-1;j>=0;j--)
			putchar(sentence[j][i]);
		printf("\n");
	}
	return 0;
}
