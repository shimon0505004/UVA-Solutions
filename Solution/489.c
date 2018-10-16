#include<stdio.h>
#include<string.h>
#define ALLPASS 0
#define NONE 1
#define GUESSED 2
int main()
{
	int n,leng,lena,i,j,tot,hangman,flag;
	char answer[100],guess[100];
	while(1){
		scanf("%d",&n);
		if(n==-1) break;
		scanf("%s%s",answer,guess);
		leng=strlen(guess);
		lena=strlen(answer);
		hangman=0;
		for(i=0;i<leng;i++){
			flag=NONE;
			for(j=0;j<lena;j++){
				if(guess[i]==answer[j]){
					flag=GUESSED;
					answer[j]=0;
				}					
			}
			if(flag==NONE)
				hangman++;
			else if(flag==GUESSED){
				tot=0;
				for(j=0;j<lena;j++)
					tot+=answer[j];
				if(tot==0) flag=ALLPASS;
			}
			if(flag==ALLPASS) break;
		}
		if(hangman>=7)
			printf("Round %d\nYou lose.\n",n);
		else if(flag==ALLPASS)
			printf("Round %d\nYou win.\n",n);
		else
			printf("Round %d\nYou chickened out.\n",n);
	}
	return 0;
}
