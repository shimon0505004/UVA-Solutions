#include<stdio.h>
#include<string.h>
#define maxd 210 
#define maxn 1001
int main()
{
	int i,j,num,previous=3;
	static char fib[maxn][maxd+1]={0},out[maxd+1]={0};
	while(scanf("%d",&num)==1){
		if(num==0)
			puts("1");
		else{
			fib[1][maxd-1]=2;
			fib[2][maxd-1]=3;
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
