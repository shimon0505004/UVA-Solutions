#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char sentence[1000];
	int words=0,i,j,len;
	while(fgets(sentence,1000,stdin)!=NULL){
		words=0;
		len=strlen(sentence);
		for(i=0;i<len;i++){
			if(isalpha(sentence[i])){
				for(j=i;j<len;j++)
					if(!isalpha(sentence[j])){
						words++;
						i=j;
						break;
					}
			}
		}
		printf("%d\n",words);
	}
	return 0;
}
