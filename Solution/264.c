#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,up,down,temp;
	float test;
	while(scanf("%d",&n)!=EOF){
		test=(-1.0+sqrt(8*n+1))/2.0;
		k=(int)test;
		if(k!=test)
			k++;
		down=k*(k+1)/2-n+1;
		up=k+1-down;
		if(k%2){
			temp=up;
			up=down;
			down=temp;
		}
		printf("TERM %d IS %d/%d\n",n,up,down);
	}
	return 0;
}
