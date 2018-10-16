#include<stdio.h>
#include<string.h>
struct VECTOR{
	int x,y;
};
char match(char puzzle[][55],int row,int col,struct VECTOR v[],int n_v){
	int i,j,k;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++){
			for(k=0;k<n_v;k++)
				if(puzzle[i+v[k].x][j+v[k].y]!='*')
					break;
			if(k==n_v) return 1;
		}
	return 0;
			
}
int main(){
	struct VECTOR v[2505],ref;
	char puzzle[55][55],pattern[55][55];
	int cases,row,col,n_patt,prow,pcol,i,j,n_v;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d%d",&row,&col,&n_patt);
		for(i=0;i<row;i++)
			scanf("%s",puzzle[i]);
		while(n_patt--){
			scanf("%d%d",&prow,&pcol);
			for(i=0;i<prow;i++)
				scanf("%s",pattern[i]);
			ref.x=-1,ref.y=55;
			for(i=0;i<prow;i++){
				char *ptr=strchr(pattern[i],'*');
				if(ptr!=NULL){
					if(ref.x==-1) ref.x=i;
					if(ptr-pattern[i]<ref.y)
						ref.y=ptr-pattern[i];
				}
			}
			n_v=0;
			for(i=ref.x;i<prow;i++)
				for(j=ref.y;j<pcol;j++)
					if(pattern[i][j]=='*'){
						v[n_v].x=i-ref.x,v[n_v].y=j-ref.y;
						n_v++;
					}
			if(match(puzzle,row,col,v,n_v)) puts("Yes");
			else puts("No");
		}
		puts("");
	}
	return 0;
}
