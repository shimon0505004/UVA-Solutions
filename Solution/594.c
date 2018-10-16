#include<stdio.h>
int main()
{
	int N,output,i;
	unsigned temp;
	while(scanf("%d",&N)==1){
		output=0;
		temp=(unsigned)N;
		for(i=0;i<3;i++){
			output+=(temp&((1<<8)-1));
			output<<=8;
			temp>>=8;
		}
		output+=temp;
		printf("%d converts to %d\n",N,output);
	}
	return 0;
}
