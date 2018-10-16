#include<stdio.h>
#include<math.h>
int Mod(int,int,int);
int main()
{
	int B,P,M;
	while(scanf("%d%d%d",&B,&P,&M)==3){
		B%=M;
		printf("%d\n",Mod(B,P,M));
	}
	return 0;
}
int Mod(int B,int P,int M)
{
	int temp;
	if(!B)
		return 0;
	else if(!P)
		return 1;
	else if(M==1)
		return 0;
	else if(P==1)
		return B%M;
	else if(!(P%2)){
		temp=Mod(B,P/2,M);
		return (temp*temp)%M;
	}
	else
		return (Mod(B,1,M)*Mod(B,P-1,M))%M;
}
