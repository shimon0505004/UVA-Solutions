#include<stdio.h>
#include<string.h>
int main()
{
	const char rank[15]="cdefgabCDEFGAB";
	const char note[14][10]={{0,1,1,1,0,0,1,1,1,1},{0,1,1,1,0,0,1,1,1,0},{0,1,1,1,0,0,1,1,0,0},{0,1,1,1,0,0,1,0,0,0},{0,1,1,1,0,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},{1,1,1,1,0,0,1,1,1,0},{1,1,1,1,0,0,1,1,0,0},{1,1,1,1,0,0,1,0,0,0},{1,1,1,1,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0}};
	int cases,i,j,len,count;
	int fingermove[10],check;
	char input[500],previous;
	scanf("%d",&cases);
	getchar();
	for(i=0;i<cases;i++){
		memset(input,0,sizeof(input));
		memset(fingermove,0,sizeof(fingermove));
		fgets(input,500,stdin);
		len=strlen(input);
		previous=0;
		for(j=0;j<len;j++){
			if(input[j]=='\n') break;
			check=strchr(rank,input[j])-rank;
			if(!previous)
				for(count=0;count<10;count++)
					fingermove[count]+=note[check][count];
			else
				for(count=0;count<10;count++)
					if(!note[strchr(rank,previous)-rank][count]&&note[check][count])
							fingermove[count]++;
			previous=input[j];
		}
		for(j=0;j<10;j++){
			if(j) printf(" ");
			printf("%d",fingermove[j]);
		}
		printf("\n");
	}
	return 0;
}
