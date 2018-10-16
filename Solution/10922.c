#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	char input[1005];
	int tot,t,count,i,len;
	char a;
	while(fgets(input,1005,stdin)!=NULL){
		if(*input=='0') break;
		input[strlen(input)-1]=0;
		len=strlen(input);
		tot=0;
		for(i=0;i<len;i++)
			if(isdigit(input[i]))
				tot+=input[i]-'0';
		if(tot%9!=0){
			printf("%s is not a multiple of 9.\n",input);
			continue;
		}
		count=1;
		while(tot>9){
			t=0;
			while(tot){
				t+=tot%10;
				tot/=10;
			}
			tot=t;
			count++;
		}
		printf("%s is a multiple of 9 and has 9-degree %d.\n",input,count);
	}
	return 0;
}
