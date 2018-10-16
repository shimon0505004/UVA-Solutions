#include<stdio.h>
#include<ctype.h>
#define Ubound (52*20+5)
int main()
{
	char isprime[Ubound]={0};
	int i,j,tot;
	char input[25];
	isprime[0]=1;
	i=2;
	for(j=2;i*j<Ubound;j++) isprime[i*j]=1;
	for(i=3;i<Ubound;i+=2){
		if(isprime[i]) continue;
		for(j=2;i*j<Ubound;j++)
			isprime[i*j]=1;
	}
	while(scanf("%s",input)==1){
		tot=0;
		for(i=0;input[i];i++)
			if(isupper(input[i])) tot+=input[i]-'A'+27;
			else tot+=input[i]-'a'+1;
		if(isprime[tot]) puts("It is not a prime word.");
		else puts("It is a prime word.");
	}
	return 0;
}
