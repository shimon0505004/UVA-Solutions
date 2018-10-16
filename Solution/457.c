#include<stdio.h>
#include<string.h>
int main(){
	int cases,DNA[10],i,j;
	char dishes[42],tmp[42];
	scanf("%d",&cases);
	while(cases--){
		for(i=0;i<10;i++) scanf("%d",&DNA[i]);
		memset(dishes,0,sizeof(dishes));
		memset(tmp,0,sizeof(tmp));
		dishes[20]=1;
		for(i=0;i<50;i++){
			for(j=1;j<=40;j++){
				if(dishes[j]==0) putchar(' ');
				else if(dishes[j]==1) putchar('.');
				else if(dishes[j]==2) putchar('x');
				else putchar('W');
				tmp[j]=DNA[dishes[j]+dishes[j-1]+dishes[j+1]];
			}
			puts("");
			memcpy(dishes,tmp,sizeof(char[42]));
		}
		if(cases) puts("");
	}
	return 0;
}
