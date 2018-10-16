#include<stdio.h>
#include<string.h>
struct UNION{
	int size,parent;
};
struct UNION u[630];
int side;
int map(int i,int j){
	return (i-1)*side+(j-1);
}
int find_root(int a){
	if(u[a].parent!=a) u[a].parent=find_root(u[a].parent);
	return u[a].parent;
}
void link(int a,int b){
	if(u[a].size<u[b].size) u[a].parent=b,u[b].size+=u[a].size;
	else u[b].parent=a,u[a].size+=u[b].size;
}
int main(){
	char cell[30][30];
	int cases,max;
	int i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",cell[1]+1);
		side=strlen(cell[1]+1);
		for(i=2;i<=side;i++) scanf("%s",cell[i]+1);
		for(i=0;i<630;i++) u[i].parent=i,u[i].size=0;
		for(i=1;i<=side;i++)
			for(j=1;j<=side;j++)
				if(cell[i][j]=='1') u[map(i,j)].size=1;
		for(i=1;i<=side;i++)
			for(j=1;j<=side;j++){
				if(cell[i][j]!='1') continue;
				if(cell[i-1][j]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i-1,j));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i][j-1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i,j-1));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i+1][j]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i+1,j));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i][j+1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i,j+1));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i-1][j-1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i-1,j-1));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i-1][j+1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i-1,j+1));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i+1][j-1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i+1,j-1));
					if(r1!=r2) link(r1,r2);
				}
				if(cell[i+1][j+1]=='1'){
					int r1=find_root(map(i,j)),r2=find_root(map(i+1,j+1));
					if(r1!=r2) link(r1,r2);
				}
			}
		max=0;
		for(i=1;i<=side;i++)
			for(j=1;j<=side;j++)
				if(max<u[map(i,j)].size) max=u[map(i,j)].size;
		printf("%d\n",max);
		if(cases) puts("");
	}
	return 0;
}
