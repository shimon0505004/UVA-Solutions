#include<stdio.h>
#include<string.h>
#define MAX 26
int main(){
	char iswake[MAX],connect[MAX][MAX],map[MAX],input[5],from,to,stall,rest;
	char c[MAX];
	int areas,connections,count,i,j,time;
	while(scanf("%d%d",&areas,&connections)==2){
		memset(iswake,0,sizeof(iswake));
		memset(connect,0,sizeof(connect));
		memset(c,0,sizeof(c));
		count=0;
		for(i=0;i<MAX;i++) map[i]=-1;
		scanf("%s",input);
		for(i=0;i<3;i++){
			if(map[input[i]-'A']==-1) map[input[i]-'A']=count++;
			iswake[map[input[i]-'A']]=1;
		}
		while(connections--){
			scanf("%s",input);
			if(map[input[0]-'A']==-1) map[input[0]-'A']=count++;
			if(map[input[1]-'A']==-1) map[input[1]-'A']=count++;
			from=map[input[0]-'A'],to=map[input[1]-'A'];
			connect[from][to]=connect[to][from]=1;
		}
		for(time=0,rest=areas-3,stall=0;rest>0&&stall==0;time++){
			stall=1;
			for(i=0;i<areas;i++){
				if(iswake[i]) continue;
				for(j=0;j<areas;j++)
					if(iswake[j]&&connect[i][j])
						c[i]++,connect[i][j]=0;
			}
			for(i=0;i<areas;i++)
				if(c[i]>=3&&iswake[i]==0) iswake[i]=1,rest--,stall=0;
		}
		if(stall) puts("THIS BRAIN NEVER WAKES UP");
		else printf("WAKE UP IN, %d, YEARS\n",time);
	}
	return 0;
}
