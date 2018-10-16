#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
	int K,E,i,j,max,n=0;
	char keywords[21][21];
	char excuses[21][80],temp[80],*excusePtr,wtemp[80];
	int worst[21],len;
	while(scanf("%d%d",&K,&E)==2){
		memset(keywords,0,sizeof(keywords));
		for(i=0;i<K;i++)
			scanf("%s",keywords[i]);
		getchar();
		memset(worst,0,sizeof(worst));
		for(i=0;i<E;i++){
			fgets(excuses[i],80,stdin);
			excuses[i][strlen(excuses[i])-1]=0;
			len=strlen(excuses[i]);
			memset(temp,0,sizeof(temp));
			for(j=0;j<len;j++)
				temp[j]=tolower(excuses[i][j]);
			excusePtr=temp;
			while(1){
				len=strcspn(excusePtr,"abcdefghijklmnopqrstuvwxyz");
				excusePtr+=len;
				len=strspn(excusePtr,"abcdefghijklmnopqrstuvwxyz");
				if(!len) break;
				memset(wtemp,0,sizeof(wtemp));
				strncpy(wtemp,excusePtr,len);
				excusePtr+=len;
				for(j=0;j<K;j++)
				if(!strcmp(wtemp,keywords[j]))
					worst[i]++;
			}
		}
		for(i=1,max=worst[0];i<E;i++)
			if(worst[i]>max)
				max=worst[i];
		printf("Excuse Set #%d\n",++n);
		for(i=0;i<E;i++)
			if(worst[i]==max)
				printf("%s\n",excuses[i]);
		printf("\n");
	}
	return 0;
}
