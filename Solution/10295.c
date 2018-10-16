#include<stdio.h>
#include<string.h>
int main()
{
	int m,n,i,j;
	int haypoint[1005],result;
	char job[1005][20];
	char describe[100];
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
		scanf("%s%d",job[i],&haypoint[i]);
	for(i=0;i<n;i++){
		result=0;
		while(scanf("%s",describe)==1&&*describe!='.')
			for(j=0;j<m;j++)
				if(!strcmp(job[j],describe))
					result+=haypoint[j];
		printf("%d\n",result);
	}
	return 0;
}
