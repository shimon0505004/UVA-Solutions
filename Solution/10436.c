#include<stdio.h>
#include<string.h>
int relay[25][25];
char name[25][30];
int find_name(char name[][30],char find[]){
	int n;
	for(n=0;strcmp(name[n],find);n++);
	return n;
}
void printRoute(int from,int to){
	int r=relay[from][to];
	if(r!=-1)
		printRoute(from,r),printRoute(r,to);
	else printf(" %s",name[to]);
}
int main(){
	int Maps,cases;
	int map[25][25],n_route;
	int pass[25],n_station;
	int i,j,k,t,n1,n2,dis;
	int n_query,n_passenger;
	char name1[30],name2[30];
	scanf("%d",&Maps);
	for(cases=1;cases<=Maps;cases++){
		if(cases>1) puts("");
		printf("Map #%d\n",cases);
		scanf("%d",&n_station);
		for(i=0;i<n_station;i++) scanf("%s%d",name[i],&pass[i]);
		scanf("%d",&n_route);
		for(i=0;i<n_station;i++)
			for(j=0;j<=i;j++){
				map[i][j]=map[j][i]=1000000000;
				relay[i][j]=relay[j][i]=-1;
			}
		while(n_route--){
			scanf("%s%s",name1,name2);
			n1=find_name(name,name1),n2=find_name(name,name2);
			scanf("%d",&dis);
			map[n1][n2]=dis*2+pass[n2];
			map[n2][n1]=dis*2+pass[n1];
		}
		for(k=0;k<n_station;k++)
			for(i=0;i<n_station;i++)
				for(j=0;j<n_station;j++)
					if((t=map[i][k]+map[k][j])<map[i][j]){
						map[i][j]=t;
						relay[i][j]=k;
					}
		scanf("%d",&n_query);
		for(i=1;i<=n_query;i++){
			double cost;
			printf("Query #%d\n",i);
			scanf("%s%s%d",name1,name2,&n_passenger);
			n1=find_name(name,name1),n2=find_name(name,name2);
			printf(name1);
			printRoute(n1,n2);
			puts("");
			cost=(map[n1][n2]+pass[n1])*1.1/n_passenger;
			printf("Each passenger has to pay : %.2lf taka\n",cost);
		}
	}
	return 0;
}
