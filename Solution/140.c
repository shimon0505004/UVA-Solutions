#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char ans[10],rank[10];
char map[10][10];
int count,min;
void dfs(char order[],int depth,char visit[]){
	int i,j,max,t;
	if(depth==count){
		max=0;
		for(i=0;i<count;i++){
			for(j=0;j<count;j++){
				if(max>min) break;
				if(map[i][j])
					if((t=abs(strchr(order,rank[i]+'A')-strchr(order,rank[j]+'A')))>max) max=t;
			}
			if(j<count) break;
		}
		if(i<count) return;
		if(max<min) min=max,strcpy(ans,order);
		else if(max==min&&strcmp(ans,order)>0) strcpy(ans,order);
		return;
	}
	for(i=0;i<count;i++){
		if(visit[i]) continue;
		visit[i]=1;
		order[depth]=rank[i]+'A';
		dfs(order,depth+1,visit);
		visit[i]=0;
	}
}
int main(){
	char input[200],check,from,to[10],*ptr;
	char order[10],appear[26],visit[10];
	int len,tolen,i,j;
	while(fgets(input,200,stdin),*input!='#'){
		memset(map,0,sizeof(map));
		memset(visit,0,sizeof(visit));
		memset(order,0,sizeof(order));
		for(i=0;i<26;i++) appear[i]=-1;
		count=0;
		for(ptr=input,check=';';check==';';ptr+=len){
			sscanf(ptr,"%c%*c%[^;\n]%c%n",&from,to,&check,&len);
			if(appear[from-'A']==-1) rank[count]=from-'A',appear[from-'A']=count++;
			tolen=strlen(to);
			for(i=0;i<tolen;i++){
				if(appear[to[i]-'A']==-1) rank[count]=to[i]-'A',appear[to[i]-'A']=count++;
				map[appear[from-'A']][appear[to[i]-'A']]=1;
			}
		}
		min=10;
		strcpy(ans,"ZZ");
		dfs(order,0,visit);
		for(i=0;i<count;i++)
			printf("%c ",ans[i]);
		printf("-> %d\n",min);
	}
	return 0;
}
