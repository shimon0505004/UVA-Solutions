#include<stdio.h>
#include<string.h>
#define inf 1000000
int main(){
	int totlen,len,all;
	char temp[150],from,to,*ptr;
	int map[26][26],odd[26];
	int i,j,k,t;
	while(!feof(stdin)){
		totlen=0,memset(map,0,sizeof(map));
		memset(odd,0,sizeof(odd));
		while(scanf("%s ",temp),strcmp(temp,"deadend")){
			len=strlen(temp);
			from=temp[0]-'a',to=temp[len-1]-'a';
			map[from][to]+=len;
			map[to][from]+=len;
			odd[from]++,odd[to]++;
			totlen+=len;
		}
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				if(map[i][j]==0) map[i][j]=inf;
		ptr=&from;
		for(i=0;i<26;i++) if(odd[i]%2) *ptr=i,ptr=&to;
		if(ptr==&from){
			printf("%d\n",totlen);
			continue;
		}
		for(k=0;k<26;k++)
			for(i=0;i<26;i++)
				for(j=0;j<i;j++)
					if((t=map[i][k]+map[k][j])<map[i][j])
						map[i][j]=map[j][i]=t;
		printf("%d\n",totlen+map[from][to]);
	}
	return 0;
}
