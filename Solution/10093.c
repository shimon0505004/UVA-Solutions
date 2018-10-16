#include<stdio.h>
int compare[128];
int minbase(char input[]){
	char base='1';
	int len=strlen(input),i;
	for(i=0;i<len;i++)
		if(input[i]>base)
			base=input[i];
	return compare[base]+1;
}
char calculate(char input[],int base){
	int i,t=0,len=strlen(input),divide=base-1;
	for(i=0;i<len;i++)
		t=(t*base+compare[input[i]])%divide;
	return !t;
}
int main(){
	char input[10005];
	int i,t=0;
	for(i='0';i<='9';i++) compare[i]=t++;
	for(i='A';i<='Z';i++) compare[i]=t++;
	for(i='a';i<='z';i++) compare[i]=t++;
	while(1){
		scanf(" %[^0-9A-z]",input);
		scanf("%s",input);
		if(feof(stdin)) break;
		for(i=minbase(input);i<=62;i++)
			if(calculate(input,i)) break;
		if(i>62) puts("such number is impossible!");
		else printf("%d\n",i);
	}
	return 0;
}
