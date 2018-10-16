#include<stdio.h>
#include<string.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	char triangle[105][205];
	int table[105][205];
	int n,i,j,max;
	int cases;
	for(cases=1;scanf("%d",&n),n;cases++){
		for(i=0;i<n;i++) scanf("%s",triangle[i]);
		memset(table,0,sizeof(table));
		max=0;
		for(i=0;i<2*n-1;i++)
			if(triangle[0][i]=='-') table[0][i]=1,max=MAX(max,1);
		for(i=1;i<n;i++)
			for(j=0;j<2*(n-i)-1;j+=2)
				if(triangle[i][j]=='-'){
					if(triangle[i-1][j+1]=='-'){
						table[i][j]=MIN(table[i-1][j],table[i-1][j+2])+1;
						if(max<table[i][j]) max=table[i][j];
					}else table[i][j]=1,max=MAX(max,1);
				}
		memset(table,0,sizeof(table));
		if(n>1&&triangle[n-2][1]=='-') table[n-2][1]=1,max=MAX(max,1);
		for(i=n-3;i>=0;i--){
			if(triangle[i][1]=='-') table[i][1]=1,max=MAX(max,1);
			if(triangle[i][2*(n-i)-3]=='-') table[i][2*(n-i)-3]=1,max=MAX(max,1);
			for(j=3;j<2*(n-i)-4;j+=2)
				if(triangle[i][j]=='-'){
					if(triangle[i+1][j-1]=='-'){
						table[i][j]=MIN(table[i+1][j-2],table[i+1][j])+1;
						if(max<table[i][j]) max=table[i][j];
					}else table[i][j]=1,max=MAX(max,1);
				}
		}
		printf("Triangle #%d\n",cases);
		printf("The largest triangle area is %d.\n",max*max);
		puts("");
	}
	return 0;
}
