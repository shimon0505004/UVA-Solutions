#include<stdio.h>
#include<string.h>
#define maxd 3000
#define maxn 1520
int main()
{
	int i,j,k,num,previous=1,dig;
	char fac[maxn][maxd+1]={0},out[maxd+1]={0},temp[5];
	while(scanf("%d",&num)!=EOF){
		if(num==0){
			printf("0!\n1\n");
			continue;
		}
		else if(num==1){
			printf("1!\n1\n");
			continue;
		}
		else if(num>previous){
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
		for(i=maxd-1;i>=0;i--)
			out[i]=fac[num][i]+'0';
		previous=(num>previous?num:previous);
		printf("%d!\n%s\n",num,out+strspn(out,"0"));
	}
	return 0;
}
