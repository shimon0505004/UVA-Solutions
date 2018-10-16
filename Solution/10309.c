#include<stdio.h>
#include<string.h>
#define MAX 101
char panel[12][12];
int n_used;
void switch_light(int x,int y){
	panel[x][y-1]=1-panel[x][y-1];
	panel[x][y]=1-panel[x][y];
	panel[x][y+1]=1-panel[x][y+1];
	panel[x-1][y]=1-panel[x-1][y];
	panel[x+1][y]=1-panel[x+1][y];
}
int fill(){
	int i,j,res=0;
	for(i=2;i<=10;i++){
		for(j=1;j<=10;j++){
			if(panel[i-1][j]==0){
				switch_light(i,j);
				res++;
			}
		}
	}
	for(i=1;i<=10;i++)
		if(panel[10][i]==0) return -1;
	return res;
}
int main(){
	int i,j;
	char name[100];
	char orig_panel[12][12];
	while(fgets(name,100,stdin),strcmp(name,"end\n")){
		name[strlen(name)-1]='\0';
		for(i=1;i<=10;i++) scanf("%s ",orig_panel[i]+1);
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++){
				if(orig_panel[i][j]=='#') orig_panel[i][j]=1;
				else orig_panel[i][j]=0;
			}
		n_used=MAX;
		for(i=0;i<1<<10;i++){
			int t,used;
			memcpy(panel,orig_panel,sizeof(panel));
			used=0;
			for(j=1;j<=10;j++) if((1<<(j-1))&i) switch_light(1,j),used++;
			if((t=fill())!=-1) if(used+t<n_used) n_used=used+t;
		}
		printf("%s ",name);
		if(n_used!=MAX) printf("%d\n",n_used);
		else puts("-1");
	}
	return 0;
}
