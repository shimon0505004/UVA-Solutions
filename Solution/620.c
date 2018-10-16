#include<stdio.h>
#include<string.h>
#define SIMPLE 1
#define FULLY_GROWN 2
#define MUTAGENIC 3
#define OTHER 4
int type(char input[],int to){
	if(to==0&&*input=='B') return OTHER;
	if(to==0&&*input=='A') return SIMPLE;
	if(input[to]=='B'&&input[to-1]!='A') return OTHER;
	if(type(input,to-2)!=OTHER&&input[to]=='B'&&input[to-1]=='A') return FULLY_GROWN;
	if(type(input+1,to-2)!=OTHER&&*input=='B'&&input[to]=='A') return MUTAGENIC;
	return OTHER;
}
int main(){
	int n,len;
	char input[300];
	scanf("%d",&n);
	while(n--){
		scanf("%s",input);
		len=strlen(input);
		if(len%2==0){
			puts("MUTANT");
			continue;
		}
		switch(type(input,len-1)){
			case SIMPLE:
				puts("SIMPLE");
				break;
			case FULLY_GROWN:
				puts("FULLY-GROWN");
				break;
			case MUTAGENIC:
				puts("MUTAGENIC");
				break;
			case OTHER:
				puts("MUTANT");
		}
	}
	return 0;
}

