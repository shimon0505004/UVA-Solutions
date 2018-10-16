#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k;
	char name[10][13]={0},tname[13];
	int receive[10],temp,give,start=0;
	while(scanf("%d",&n)!=EOF){
		if(start++) printf("\n");
		memset(name,0,sizeof(name));
		memset(receive,0,sizeof(receive));
		for(i=0;i<n;i++)
			scanf("%s",name[i]);
		for(i=0;i<n;i++){
			scanf("%s%d%d",tname,&temp,&give);
			temp/=(give?give:1);
			for(j=0;j<n;j++)
				if(!strcmp(tname,name[j]))
					receive[j]-=(temp*give);
			for(j=0;j<give;j++){
				scanf("%s",tname);
				for(k=0;k<n;k++)
					if(!strcmp(tname,name[k])){
						receive[k]+=temp;
						break;
					}
			}
		}
		for(i=0;i<n;i++)
			printf("%s %d\n",name[i],receive[i]);
	}
	return 0;
}
