#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct GRID{
	int row,col;
};
int compar(const void *a,const void *b){
	return *((int *)a)-*((int *)b);
}
void to_grid(int n,struct GRID *grid){
	grid->row=(int)((sqrt(((double)n-0.5)*8+1)-1)/2+1);
	grid->col=n-grid->row*(grid->row-1)/2;
}
int main(){
	char line[50],*ptr;
	int n_number,len,num[10];
	struct GRID grid[10];
	int i;
	while(fgets(line,50,stdin)!=NULL){
		for(n_number=0,ptr=line;sscanf(ptr,"%d%n",&num[n_number],&len)==1;ptr+=len,n_number++)
			printf("%d ",num[n_number]);
		qsort(num,n_number,sizeof(int),compar);
		for(i=0;i<n_number;i++)
			to_grid(num[i],&grid[i]);
		if(n_number==3){
			if(grid[0].row==grid[1].row){
				if(grid[2].col==grid[1].col&&grid[1].col-grid[0].col==grid[2].row-grid[1].row)
					puts("are the vertices of a triangle");
				else puts("are not the vertices of an acceptable figure");
			}else if(grid[1].row==grid[2].row){
				if(grid[0].col==grid[1].col&&grid[2].col-grid[1].col==grid[1].row-grid[0].row)
					puts("are the vertices of a triangle");
				else puts("are not the vertices of an acceptable figure");
			}else puts("are not the vertices of an acceptable figure");
		}else if(n_number==4){
			if(grid[0].row==grid[1].row&&grid[2].row==grid[3].row&&grid[1].col-grid[0].col==grid[3].col-grid[2].col){
				if((grid[0].col==grid[2].col||grid[1].col==grid[2].col)&&grid[2].row-grid[0].row==grid[1].col-grid[0].col)
					puts("are the vertices of a parallelogram");
				else puts("are not the vertices of an acceptable figure");
			}else if(grid[1].row==grid[2].row&&grid[1].row-grid[0].row==grid[3].row-grid[2].row&&grid[0].col==grid[1].col&&grid[2].col==grid[3].col&&grid[1].row-grid[0].row==grid[2].col-grid[1].col){
				puts("are the vertices of a parallelogram");
			}else puts("are not the vertices of an acceptable figure");
		}else if(n_number==6){
			struct GRID check;
			int side;
			check=grid[0],side=grid[1].col-grid[0].col;
			if(grid[1].row==check.row&&grid[1].col==check.col+side&&grid[2].row==check.row+side&&grid[2].col==check.col&&grid[3].row==check.row+side&&grid[3].col==check.col+2*side&&grid[4].row==check.row+2*side&&grid[4].col==check.col+side&&grid[5].row==check.row+side*2&&grid[5].col==check.col+side*2)
				puts("are the vertices of a hexagon");
			else puts("are not the vertices of an acceptable figure");
		}else puts("are not the vertices of an acceptable figure");
	}
	return 0;
}
