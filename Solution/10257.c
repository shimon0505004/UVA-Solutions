#include<stdio.h>
int main()
{
	int s,p,y,j,x;
	while(scanf("%d%d%d%d",&s,&p,&y,&j)==4){
		x=(12+j-(2*p+s));
		switch(x%3){
			case 0:
				x/=3;
				if(s+p==y)
					printf("%d %d %d\n",x+s+p,x+p,x);
				else
					printf("%d %d %d\n",x+s+p+1,x+p,x-1);
				break;
			case 1:
				x/=3;
				printf("%d %d %d\n",x+s+p+1,x+p,x);
				break;
			case 2:
				x/=3;
				printf("%d %d %d\n",x+s+p+1,x+p+1,x);
		}
	}
	return 0;
}
