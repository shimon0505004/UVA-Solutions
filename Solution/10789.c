#include<stdio.h>
#include<string.h>
int main()
{
	int cases,i,j;
	char sentence[2005];
	int freq[128],len,start;
	char isprime[2002]={0};
	isprime[0]=isprime[1]=1;
	for(i=2;i<=1001;i++)
		if(!isprime[i])
			for(j=2;i*j<2002;j++)
				isprime[i*j]=1;
	scanf("%d",&cases);
	i=0;
	while(i<cases){
		start=0;
		scanf("%s",sentence);
		len=strlen(sentence);
		memset(freq,0,sizeof(freq));
		for(j=0;j<len;j++)
			freq[sentence[j]]++;
		printf("Case %d: ",++i);
		for(j=0;j<128;j++)
			if(!isprime[freq[j]]){
				printf("%c",j);
				start=1;
			}
		if(!start)
			printf("empty");
		printf("\n");
	}
	return 0;
}
