#include<stdio.h>
#include<string.h>
#define maxd 781
#define maxn 367
int main()
{
	int i,j,k,num,previous=1,dig,ZeroToNine[10],start;
	char fac[maxn][maxd+1]={0},temp[4],out[maxd+1];
	while(scanf("%d",&num)!=EOF){
		memset(ZeroToNine,0,sizeof(ZeroToNine));
		if(!num) break;
		if(num>=previous){
			fac[0][maxd-1]=1;
			fac[1][maxd-1]=1;
			for(k=previous+1;k<=num;k++){
				sprintf(temp,"%d",k);
				dig=strlen(temp);
				for(i=0;i<dig;i++){
					for(j=maxd-1;j>=0;j--){
						fac[k][j-i]+=fac[k-1][j]*(temp[dig-1-i]-'0');
						fac[k][j-i]+=fac[k][j+1-i]/10;
						fac[k][j+1-i]%=10;
					}
				}
			}
		}
		dig=0;
		start=1;
		for(i=0;i<maxd;i++){
			if(!fac[num][i] && start)
				continue;
			out[dig++]=fac[num][i];
			start=0;
		}
		for(i=0;i<dig;i++)
			ZeroToNine[out[i]]++;
		previous=(num>previous?num:previous);
		printf("%d! --\n   ",num);
		for(i=0;i<10;i++){
			printf("(%d)%5d",i,ZeroToNine[i]);
			if(i==4) 
				printf("\n   ");
			else if(i==9)
				printf("\n");
			else
				printf("    ");
		}
	}
	return 0;
}
