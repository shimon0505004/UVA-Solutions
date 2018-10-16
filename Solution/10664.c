#include<stdio.h>
#include<string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int n,lug[25],n_lug,len,i,j,half;
	char *ptr,input[100];
	int table[25][205];
	scanf("%d ",&n);
	while(n--){
		fgets(input,100,stdin);
		half=0;
		for(n_lug=0,ptr=input;sscanf(ptr,"%d%n",&lug[++n_lug],&len)==1;ptr+=len)
			half+=lug[n_lug];
		n_lug--;
		if(half%2!=0){
			puts("NO");
			continue;
		}
		half>>=1;
		memset(table,0,sizeof(table));
		for(i=1;i<=n_lug;i++){
			for(j=1;j<=half;j++){
				if(lug[i]>j)
					table[i][j]=table[i-1][j];
				else{
					table[i][j]=MAX(table[i-1][j],lug[i]+table[i-1][j-lug[i]]);
				}

			}
		}
		if(table[n_lug][half]==half) puts("YES");
		else puts("NO");
	}
	return 0;
}
