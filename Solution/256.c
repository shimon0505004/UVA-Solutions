#include<stdio.h>
#include<math.h>
int main()
{
	int even,i,n,dig,p;
	int n1,n2;
	char Quirksome[4][20][10]={0};
	for(dig=2;dig<=8;dig+=2){
		n=0;
		p=pow(10,dig/2);
		for(i=0;i<p;i++){
			n1=i*i/p;
			n2=i*i%p;
			if(n1+n2==i)
				sprintf(Quirksome[dig/2-1][n++],"%.*d",dig,i*i);
		}
	}
	while(scanf("%d",&even)!=EOF)
		for(i=0;*Quirksome[even/2-1][i];i++)
			printf("%s\n",Quirksome[even/2-1][i]);
	return 0;
}
