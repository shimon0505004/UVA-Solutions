#include<stdio.h>
int main()
{
	int n,m,c,i,cases=0;
	int needampere[20];
	char onoff[20];
	int ampere,turn,blown,max;
	while(1){
		scanf("%d%d%d",&n,&m,&c);
		if(!(n+m+c)) break;
		memset(needampere,0,sizeof(needampere));
		for(i=0;i<n;i++)
			scanf("%d",&needampere[i]);
		ampere=0;
		blown=0;
		max=0;
		memset(onoff,0,sizeof(onoff));
		for(i=0;i<m;i++){
			scanf("%d",&turn);
			turn--;
			if(onoff[turn]){
				ampere-=needampere[turn];
				onoff[turn]=0;
			}
			else{
				ampere+=needampere[turn];
				if(ampere>c) blown=1;
				if(ampere>max) max=ampere;
				onoff[turn]=1;
			}
		}
		if(blown)
			printf("Sequence %d\nFuse was blown.\n",++cases);
		else{
			printf("Sequence %d\n",++cases);
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n",max);
		}
		printf("\n");
	}
	return 0;
}
