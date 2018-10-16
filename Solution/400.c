#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compar(const void *a,const void *b){
	return strcmp((char *)a,(char *)b);
}
int main()
{
	int n,i,j,maxlen,len,col,row;
	char filename[105][62];
	const char *line = "------------------------------------------------------------";
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%s",filename[i]);
		qsort(filename,n,62*sizeof(char),compar);
		maxlen=0;
		for(i=0;i<n;i++)
			if((len=strlen(filename[i]))>maxlen)
				maxlen=len;
		col=60/(maxlen+2);
		if((maxlen+2)*(col+1)==62) col++;
		row=n/col;
		if(n%col!=0) row++;
		puts(line);
		for(i=0;i<row;i++){
			for(j=0;j*row+i<n;j++){
				printf("%-*s",maxlen,filename[i+j*row]);
				if(j<col-1) printf("  ");
			}
			puts("");
		}
	}
	return 0;
}
