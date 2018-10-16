#include<stdio.h>
#include<string.h>
int main(){
	int i,j,half,total;
	int marble[7];
	int table[60005][7],maxv[60005];
	int cases;
	for(cases=1;;cases++){
		total=0;
		for(i=1;i<=6;i++) scanf("%d",&marble[i]),total+=marble[i]*i;
		if(total==0) break;
		printf("Collection #%d:\n",cases);
		if(total%2!=0){
			puts("Can't be divided.\n");
			continue;
		}
		half=total/2;
		memset(table,0,sizeof(table));
		memset(maxv,0,sizeof(maxv));
		for(j=1;j<=half;j++){
			int max=0,maxi;
			for(i=1;i<=6;i++){
				if(j<i) continue;
				if(table[j-i][i]<marble[i]&&maxv[j-i]+i>max)
					maxi=i,max=maxv[j-i]+i;
			}
			if(max>0){
				memcpy(table[j],table[j-maxi],sizeof(int[7]));
				table[j][maxi]++;
				maxv[j]=max;
			}else{
				memcpy(table[j],table[j-1],sizeof(int[7]));
				maxv[j]=maxv[j-1];
			}
		}
		if(maxv[half]==half) puts("Can be divided.\n");
		else puts("Can't be divided.\n");
	}
	return 0;
}
