#include<stdio.h>
int main(){
	int r,c;
	while(scanf("%d%d",&r,&c),r+c){
		if(r<2||c<2)
			printf("%d",r*c);
		else if(r==2||c==2)
			printf("%d",((r*c-1)/8+1)*4-2*(r*c%8==2?1:0));
		else
			printf("%d",(r*c+1)/2);
		printf(" knights may be placed on a %d row %d column board.\n",r,c);
	}
	return 0;
}
