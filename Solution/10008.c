#include<stdio.h>
#include<string.h>
int main()
{
	int n,alphabat[26]={0},i,ascii,exitn=0,max=0,maxi;
	scanf("%d ",&n);
	while(1){
		ascii=getchar();
		if(ascii=='\n')
			exitn++;
		if(exitn==n)
			break;
		if(ascii>='a' &&ascii<='z')
			alphabat[ascii-'a']++;
		else if(ascii>='A' && ascii<='Z')
			alphabat[ascii-'A']++;
	}
	max=-1;
	while(max!=0){
		max=0;
		for(i=0;i<26;i++)
			if(max<alphabat[i]){
				max=alphabat[i];
				maxi=i;
			}
		if(max>0){
			printf("%c %d\n",maxi+'A',alphabat[maxi]);
			alphabat[maxi]=0;
		}
	}
	return 0;
}
