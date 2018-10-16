#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char ISBN[81];
	int len,i,total,count,flag,skipspace;
	while(1){
		flag=total=0;
		memset(ISBN,0,sizeof(ISBN));
		fgets(ISBN,200,stdin);
		ISBN[strlen(ISBN)-1]=0;
		if(feof(stdin)) break;
		len=strlen(ISBN);
		for(i=len-1;i>=0;i--)
			if(isspace(ISBN[i]))
				ISBN[i]=0;
			else
				break;
		for(i=0;isspace(ISBN[i]);i++);
		skipspace=i;
		for(count=0;count<9||ISBN[i]=='-';i++)
			if(isdigit(ISBN[i])){
				total+=(ISBN[i]-'0')*(10-count);
				count++;
			}
			else if(ISBN[i]=='-') continue;
			else{
				flag=1;
				break;
			}
		if(ISBN[i]=='X')
			total+=10;
		else if(isdigit(ISBN[i]))
			total+=ISBN[i]-'0';
		else
			flag=1;
		printf("%s",ISBN+skipspace);
		if(!(flag||(total%11)||ISBN[i+1]))
			puts(" is correct.");
		else
			puts(" is incorrect.");
	}
	return 0;
}
