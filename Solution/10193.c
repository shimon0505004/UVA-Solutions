#include<stdio.h>
#include<string.h>
int main()
{
	int cases,i=0,j;
	char binary1[32],binary2[32];
	int exact1,exact2,len1,len2,GCD;
	scanf("%d",&cases);
	while(i<cases){
		scanf("%s%s",binary1,binary2);
		len1=strlen(binary1);
		len2=strlen(binary2);
		exact1=0;
		for(j=0;j<len1;j++)
			exact1+=(binary1[j]-'0')*(1<<(len1-1-j));
		exact2=0;
		for(j=0;j<len2;j++)
			exact2+=(binary2[j]-'0')*(1<<(len2-1-j));
		while(exact1%exact2){
			GCD=exact1%exact2;
			exact1=exact2;
			exact2=GCD;
		}
		printf("Pair #%d: ",++i);
		if(exact2==1)
			printf("Love is not all you need!\n");
		else
			printf("All you need is love!\n");
	}
	return 0;
}
