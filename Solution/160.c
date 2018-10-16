#include<stdio.h>
#include<math.h>
int main()
{
	int i,n = 1,j,num;
	int prime[25],fac[101][25]={0};
	prime[0]=2;
	for(i=3;n<25;i++){
		int check = 1 ;
		for(j=0;prime[j]*prime[j]<=i;j++)
			if(i%prime[j]==0){
				check = 0 ;
				break;
			}
		if(check == 1) prime[n++] = i ;
	}
	for(i=2;i<=100;i++){
		int tmp = i ;
		j = 0 ;
		while(tmp != 1)
			if(tmp % prime[j] == 0){
				tmp /= prime[j] ;
				fac[i][j]++ ;
			}
			else j++ ;
	}
	for(i=3;i<=100;i++)
		for(j = 0 ; j < 25 ; j++)
			fac[i][j] += fac[i-1][j] ;
	while(1){
		scanf("%d",&num);
		if(!num) break;
		printf("%3d! =",num);
		for(i=0;fac[num][i]>0 && i<25;i++){
			if(i==15)
				printf("\n      ");
			if(fac[num][i])
				printf("%3d",fac[num][i]);
		}
		printf("\n");
	}
	return 0;
}
