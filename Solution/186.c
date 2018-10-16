#include<stdio.h>
#include<string.h>
struct ROUTE{
	char name[15];
	int distance,relay;
}r[105][105];
char name[105][25];
void printRoute(int from,int to){
	int relay;
	if((relay=r[from][to].relay)!=-1){
		printRoute(from,relay);
		printRoute(relay,to);
	}else printf("%-20s %-20s %-10s %5d\n",name[from],name[to],r[from][to].name,r[from][to].distance);
}
int main(){
	char input[60],place[25],start[25],goal[25],rname[15],*ptr;
	int count=0,i,j,k,from,to,len,dis;
	for(i=0;i<105;i++)
		for(j=0;j<105;j++)
			r[i][j].distance=1000000000,r[i][j].relay=-1;
	while(fgets(input,60,stdin),*input!='\n'){
		ptr=input;
		sscanf(ptr,"%[^,]%*c%n",place,&len),ptr+=len;
		for(i=0;i<count;i++) if(strcmp(name[i],place)==0) break;
		from=i;
		if(i==count) strcpy(name[count++],place);
		sscanf(ptr,"%[^,]%*c%n",place,&len),ptr+=len;
		for(i=0;i<count;i++) if(strcmp(name[i],place)==0) break;
		to=i;
		if(i==count) strcpy(name[count++],place);
		sscanf(ptr,"%[^,]%*c%d",rname,&dis);
		if(r[from][to].distance>dis){
			r[from][to].distance=r[to][from].distance=dis;
			strcpy(r[from][to].name,rname);
			strcpy(r[to][from].name,rname);
		}
	}
	for(k=0;k<count;k++)
		for(i=0;i<count;i++)
			for(j=0;j<i;j++)
				if((dis=r[i][k].distance+r[k][j].distance)<r[i][j].distance){
					r[i][j].distance=r[j][i].distance=dis;
					r[i][j].relay=r[j][i].relay=k;
				}
	while(scanf("%[^,]%*c%[^\n]%*c",start,goal)==2){
		puts("\n");
		for(from=0;from<count;from++) if(strcmp(start,name[from])==0) break;
		for(to=0;to<count;to++) if(strcmp(goal,name[to])==0) break;
		printf("%-20s %-20s %-10s %-5s\n","From","To","Route","Miles");
		puts("-------------------- -------------------- ---------- -----");
		printRoute(from,to);
		printf("%58s\n","-----");
		printf("%42s%-10s %5d\n","","Total",r[from][to].distance);
	}
	return 0;
}
