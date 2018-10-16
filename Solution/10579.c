#include<stdio.h>
#include<string.h>
#define maxd 1500
#define maxn 5002
int main()
{
	int i,j,num,previous=3;
	char fib[maxn][maxd+1]={0},out[maxd+1]={0};
	while(scanf("%d",&num)!=EOF){
		if(num==0)
			printf("%d\n",0);
		else{
			fib[1][maxd-1]=1;
			fib[2][maxd-1]=1;
			if(num>=previous){
				for(j=previous;j<=num;j++){
					for(i=maxd-1;i>=0;i--){
						fib[j][i]=fib[j-1][i]+fib[j-2][i]+(i>maxd-1?0:fib[j][i+1])/10;
						if(i<maxd-1)
							fib[j][i+1]%=10;
					}
				}
			}
			for(i=0;i<maxd;i++)
				out[i]=fib[num][i]+'0';
			printf("%s\n",out+strspn(out,"0"));
		}
		previous=(num>previous?num:previous);
	}
	return 0;
}
