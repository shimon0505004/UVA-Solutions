#include<stdio.h>
#include<math.h>
int main()
{
	unsigned int sides,n=0;
	double diagonals;
	while(1){
		scanf("%lf",&diagonals);
		if(!diagonals) break;
		sides=ceil((3+sqrt(9+8*diagonals))/2);
		printf("Case %d: %u\n",++n,sides);
	}
	return 0;
}
