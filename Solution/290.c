#include<stdio.h>
#include<string.h>
const char *numlist="0123456789ABCDE";
char out[50];
char result[50];
int realval(char n)
{
	return strchr(numlist,n)-numlist;
}
char *reverse(char *string)
{
	int i,len=strlen(string);
	memset(out,0,sizeof(out));
	for(i=0;i<len;i++)
		out[len-1-i]=string[i];
	return out;
}
char ispalindroms(char *string)
{
	int i;
	int len=strlen(string);
	for(i=0;i<len/2;i++)
		if(string[i]!=string[len-i-1])
			return 0;
	return 1;
}
char *add(char *num,int base)
{
	char rev[50]={0};
	int len=strlen(num),i;
	strcpy(rev,reverse(num));
	memset(result,0,sizeof(result));
	for(i=len;i>=1;i--){
		result[i]+=realval(num[i-1])+realval(rev[i-1]);
		result[i-1]=result[i]/base;
		result[i]=numlist[result[i]%base];
	}
	*result=numlist[*result];
	return strpbrk(result,numlist+1);
}
char islegal(char *num,int base)
{
	int len=strlen(num),i;
	for(i=0;i<len;i++)
		if(realval(num[i])>=base)
			return 0;
	return 1;
}
int main()
{
	int count,base;
	char input[50];
	char temp[50]={0};
	while(scanf("%s",input)==1){
		for(base=15;base>1;base--){
			if(islegal(input,base)){
				strcpy(temp,input);
				for(count=0;;count++){
					if(ispalindroms(temp)){
						printf("%d",count);
						break;
					}
					strcpy(temp,add(temp,base));
				}
			}
			else
				printf("?");
			if(base-2) printf(" ");
		}
		printf("\n");
		memset(temp,0,sizeof(temp));
	}
	return 0;
}
