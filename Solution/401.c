#include<stdio.h>
#include<string.h>
void reverse(char num[])
{
	char hold;
	int i,len=strlen(num);
	for(i=0;i<len/2;i++){
		hold=num[i];
		num[i]=num[len-1-i];
		num[len-1-i]=hold;
	}
}
int mirror(char num[])
{
	char hold;
	char mirrorchar[36]="ABCD3FGHILKJMNOPQR2TUVWXY51SE4Z6789";
	char normal[36]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	char bilateral[22]="AEHIJLMOSTUVWXYZ12358";
	int i,len=strlen(num),ismirror=1;
	for(i=0;i<=len/2;i++){
		if(strchr(bilateral,num[i])==NULL){
			ismirror=0;
			break;
		}
		hold=num[i];
		num[i]=mirrorchar[strchr(normal,num[len-1-i])-normal];
		num[len-1-i]=mirrorchar[strchr(normal,hold)-normal];
	}
	return ismirror;
}
int main()
{
	char s[1005],temp[1005];
	int value,i,ismirror;
	while(scanf("%s",s)==1){
		value=0;
		strcpy(temp,s);
		reverse(temp);
		if(!strcmp(temp,s))
			value=1;
		strcpy(temp,s);
		ismirror=mirror(temp);
		if(!strcmp(temp,s)&&ismirror)
			value+=2;
		switch(value){
			case 0:
				printf("%s -- is not a palindrome.\n",s);
				break;
			case 1:
				printf("%s -- is a regular palindrome.\n",s);
				break;
			case 2:
				printf("%s -- is a mirrored string.\n",s);
				break;
			case 3:
				printf("%s -- is a mirrored palindrome.\n",s);
				break;
		}
		printf("\n");
	}
	return 0;
}
