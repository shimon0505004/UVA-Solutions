#include<stdio.h>
int main(){
	int pages,n_sheet;
	int i;
	while(scanf("%d",&pages),pages){
		printf("Printing order for %d pages:\n",pages);
		n_sheet=(pages+3)/4;
		for(i=0;i<n_sheet;i++){
			printf("Sheet %d, front:",i+1);
			if(4*n_sheet-i*2>pages) printf(" Blank,");
			else printf(" %d,",4*n_sheet-i*2);
			printf(" %d\n",i*2+1);
			if(i*2+2<=pages){
				printf("Sheet %d, back :",i+1);
				printf(" %d,",i*2+2);
				if(4*n_sheet-i*2-1>pages) printf(" Blank\n");
				else printf(" %d\n",4*n_sheet-i*2-1);
			}
		}
	}
	return 0;
}
