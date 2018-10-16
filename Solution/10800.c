#include<stdio.h>
#include<string.h>
int main()
{
	int cases;
	int x,y,i,len,max,count=0,min;
	char RFC[60],*Ptr;
	char graph[60][60];
	int end[60],temp;
	scanf("%d",&cases);
	while(cases--){
		printf("Case #%d:\n",++count);
		scanf("%s",RFC);
		memset(graph,' ',sizeof(graph));
		len=strlen(RFC);
		temp=0,min=0;
		for(i=0;i<len;i++){
			if(RFC[i]=='R')
				temp++;
			else if(RFC[i]=='F')
				if(--temp<min) min=temp;
		}
		y=1-min,max=0;
		for(i=0,x=2;i<len;i++,x++){
			switch(RFC[i]){
				case 'R':
					end[y]=x+1;
					graph[y][x]='/';
					max=(y>max?y:max);
					y++;
					break;
				case 'C':
					end[y]=x+1;
					graph[y][x]='_';
					max=(y>max?y:max);
					break;
				case 'F':
					graph[--y][x]='\\';
					end[y]=x+1;
					max=(y>max?y:max);
					break;
			}
		}
		for(i=1;i<=max;i++){
			graph[i][end[i]]=0;
			*graph[i]='|';
		}
		for(i=1;i<len+3;i++)
			(*graph)[i]='-';
		(*graph)[len+3]=0;
		(*graph)[0]='+';
		for(i=max;i>=0;i--)
			printf("%s\n",graph[i]);
		printf("\n");
	}
	return 0;
}
