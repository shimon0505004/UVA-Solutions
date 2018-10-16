#include<stdio.h>
#include<string.h>
int find_insert(char e_name[][10],char find[],int *n_event){
	int n=*n_event;
	int i;
	for(i=0;i<n;i++) if(strcmp(e_name[i],find)==0) break;
	if(i<n) return i;
	strcpy(e_name[n],find);
	return (*n_event)++;
}
int main(){
	int N,NE,NM;
	int n_event;
	int i,j,k;
	int n_concurrent;
	char e_name[105][10];
	char map[105][105],t1[10],t2[10];
	char concurrent[2][2][10];
	int cases;
	for(cases=1;scanf("%d",&N),N;cases++){
		n_event=0;
		memset(map,0,sizeof(map));
		while(N--){
			int prev,now;
			scanf("%d",&NE);
			scanf("%s",t1);
			prev=find_insert(e_name,t1,&n_event);
			while(--NE){
				scanf("%s",t1);
				now=find_insert(e_name,t1,&n_event);
				map[prev][now]=1;
				prev=now;
			}
		}
		scanf("%d",&NM);
		while(NM--){
			int from,to;
			scanf("%s%s",t1,t2);
			from=find_insert(e_name,t1,&n_event);
			to=find_insert(e_name,t2,&n_event);
			map[from][to]=1;
		}
		for(k=0;k<n_event;k++)
			for(i=0;i<n_event;i++)
				for(j=0;j<n_event;j++)
					if(map[i][k]&&map[k][j]) map[i][j]=1;
		n_concurrent=0;
		for(i=0;i<n_event;i++)
			for(j=0;j<i;j++)
				if(map[i][j]==0&&map[j][i]==0){
					if(n_concurrent==0){
						strcpy(concurrent[0][0],e_name[i]);
						strcpy(concurrent[0][1],e_name[j]);
					}else if(n_concurrent==1){
						strcpy(concurrent[1][0],e_name[i]);
						strcpy(concurrent[1][1],e_name[j]);
					}
					n_concurrent++;
				}
		printf("Case %d, ",cases);
		if(n_concurrent==0) puts("no concurrent events.");
		else{
			printf("%d concurrent events:\n",n_concurrent);
			if(n_concurrent==1)
				printf("(%s,%s) \n",concurrent[0][0],concurrent[0][1]);
			else
				printf("(%s,%s) (%s,%s) \n",concurrent[0][0],concurrent[0][1],concurrent[1][0],concurrent[1][1]);
		}
	}
	return 0;
}
