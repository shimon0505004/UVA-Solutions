#include<stdio.h>
int main()
{
	int i;
	char sentence[2000];
	while(scanf("%s",sentence)!=EOF){
		for(i=0;i<strlen(sentence);i++)
			sentence[i]+='.'-'5';
		printf("%s\n",sentence);
	}
	return 0;
}
