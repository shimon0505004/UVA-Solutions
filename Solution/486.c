#include<stdio.h>
#include<string.h>
const char beforetwenty[20][15]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const char Nties[10][15]={"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
const char negative[15]="negative";
const char multiply[3][15]={"hundred", "thousand", "million"};
int translator(char num[]){
	int i;
	if(strcmp(num,negative)==0) return -1;
	for(i=0;i<20;i++)
		if(strcmp(num,beforetwenty[i])==0) return i;
	for(i=2;i<10;i++)
		if(strcmp(num,Nties[i])==0) return i*10;
}
int tonum(char num[]){
	int result=0,len;
	char *p,*t,tmp[20];
	if((t=strstr(num,multiply[0]))==NULL)
		for(p=num;sscanf(p,"%s%n",tmp,&len)==1;p+=len)
			result+=translator(tmp);
	else{
		sscanf(num,"%s",tmp);
		p=t+strlen(multiply[0]);
		result+=translator(tmp)*100+tonum(p);
	}
	return result;
}
int main(){
	char input[200];
	char temp[200],*p1,*p2;
	int result;
	while(fgets(input,200,stdin)!=NULL){
		result=0;
		if(strstr(input,negative)!=NULL) p1=p2=input+strlen(negative);
		else p1=p2=input;
		if((p2=strstr(input,multiply[2]))!=NULL){
			memset(temp,0,sizeof(temp));
			strncpy(temp,p1,p2-p1-1);
			result+=tonum(temp)*1000000;
			p1=(p2+=strlen(multiply[2]));
		}
		if((p2=strstr(input,multiply[1]))!=NULL){
			memset(temp,0,sizeof(temp));
			strncpy(temp,p1,p2-p1-1);
			result+=tonum(temp)*1000;
			p1=(p2+=strlen(multiply[1]));
		}
		result+=tonum(p1);
		if(strstr(input,negative)!=NULL) result*=-1;
		printf("%d\n",result);
	}
	return 0;
}
