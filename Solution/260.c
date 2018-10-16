#include<stdio.h>
int s;
int parent[40805];
int map(int i,int j){
	return i*(s+2)+j;
}
int find_root(int a){
	if(parent[a]!=a) parent[a]=find_root(parent[a]);
	return parent[a];
}
void link(int r1,int r2){
	parent[r1]=r2;
}
int main(){
	char gioco[205][205];
	int i,j,cases;
	for(cases=1;scanf("%d ",&s),s;cases++){
		for(i=1;i<=s;i++) fgets(gioco[i]+1,205,stdin);
		for(i=1;i<=s;i++){
			parent[map(0,i)]=map(0,1),parent[map(s+1,i)]=map(s+1,1);
			gioco[0][i]=gioco[s+1][i]='b';
			parent[map(i,0)]=map(1,0),parent[map(i,s+1)]=map(i,s+1);
			gioco[i][0]=gioco[i][s+1]='w';
		}
		for(i=1;i<=s;i++)
			for(j=1;j<=s;j++)
				parent[map(i,j)]=map(i,j);
		for(i=1;i<=s;i++)
			for(j=1;j<=s;j++){
				int x,y,r1,r2;
				x=i-1,y=j-1,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
				x=i-1,y=j,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
				x=i,y=j-1,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
				x=i,y=j+1,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
				x=i+1,y=j,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
				x=i+1,y=j+1,r1=find_root(map(i,j)),r2=find_root(map(x,y));
				if(r1!=r2&&gioco[i][j]==gioco[x][y]) link(r1,r2);
			}
		printf("%d ",cases);
		if(find_root(map(0,1))==find_root(map(s+1,1))) puts("B");
		else puts("W");
	}
	return 0;
}
