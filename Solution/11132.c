#include<stdio.h>
#include<string.h>
int main(){
	int n,s,len,t,i,j;
	int offset,readsize,sum;
	char coins[1005];
	int die[1005];
	while(scanf("%d%*c%d",&n,&s),n|s){
		scanf("%s",coins);
		len=strlen(coins);
		for(t=1,readsize=0;t<s;t<<=1,readsize++);
		offset=0;
		for(i=0;i<n&&offset+readsize*(n-i)<=len;offset+=readsize){
			die[i]=0;
			for(j=offset;j<offset+readsize;j++)
				die[i]=(die[i]<<1)+((coins[j]=='T')?1:0);
			if(die[i]<s) i++;
		}
		if(i==n){
			sum=0;
			for(i=0;i<n;i++) sum+=die[i];
			printf("%d\n",sum+n);
		}else puts("-1");
	}
	return 0;
}
